/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_ttf.h>

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>

extern "C" std::unique_ptr<ass::IRenderer> uwu_goofy_ahhh_renderer_entrypoint()
{
    return std::make_unique<SDL2>();
}

SDL2::SDL2() : _window(nullptr), _renderer(nullptr)
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    int HEIGHT = 720;
    int WIDTH = 1200;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error(
            "Couldn't initialize SDL: " + std::string(SDL_GetError()) + "\n");

    _window = SDL_CreateWindow(
        "Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, windowFlags);

    if (_window == nullptr)
        throw std::runtime_error(
            "Failed to open " + std::to_string(WIDTH) + " x " +
            std::to_string(HEIGHT) + " window: " + SDL_GetError() + "\n");

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    _renderer = SDL_CreateRenderer(_window, -1, rendererFlags);

    if (_renderer == nullptr)
        throw std::runtime_error(
            "Failed to create renderer: " + std::string(SDL_GetError()) + "\n");

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init();

    refresh();
}

SDL2::~SDL2()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

void SDL2::refresh()
{
    SDL_RenderPresent(_renderer);
}

void SDL2::clear(ass::TermColor color)
{
    const auto &c = COLORS.at(color);
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
    SDL_RenderClear(_renderer);
}

void SDL2::set_title(std::wstring title) {}

void SDL2::draw_sprite(ass::ISprite &sprite, void *&raw_data)
{
    auto &data = reinterpret_cast<SpriteData *&>(raw_data);

    if (raw_data == nullptr) {
        data = new SpriteData{0};
        data->texture =
            IMG_LoadTexture(_renderer, sprite.get_asset().path.c_str());
        if (data->texture == nullptr)
            throw std::runtime_error("Texture loading failed");
        SDL_QueryTexture(
            data->texture, nullptr, nullptr, &data->dest.w, &data->dest.h);
    }

    data->dest.x = int(sprite.position().x) * 32;
    data->dest.y = int(sprite.position().y) * 32;
    SDL_RenderCopy(_renderer, data->texture, nullptr, &data->dest);
}

ass::Vector2<size_t> SDL2::get_window_size() const
{
    int width = 0;
    int height = 0;

    SDL_GetRendererOutputSize(_renderer, &width, &height);
    return {
        size_t(width) / 32,
        size_t(height) / 32,
    };
}

std::vector<ass::Event> SDL2::events()
{
    std::vector<ass::Event> events{};

    for (SDL_Event event; SDL_PollEvent(&event) == 1;) {
        SDL_Keycode k = 0;
        switch (event.type) {
            case SDL_QUIT:
                events.push_back(
                    {ass::EventKey::KeyQ, ass::EventState::KeyPressed});
                break;

            case SDL_KEYDOWN:
                k = SDL_GetKeyFromScancode(event.key.keysym.scancode);
                if (KEYS.contains(k))
                    events.push_back({KEYS.at(k), ass::EventState::KeyPressed});
                break;
            case SDL_KEYUP:
                k = SDL_GetKeyFromScancode(event.key.keysym.scancode);
                if (KEYS.contains(k))
                    events.push_back(
                        {KEYS.at(k), ass::EventState::KeyReleased});
                break;
            default:
                break;
        }
    }
    return events;
}

void SDL2::free_sprite(void *&raw_data)
{
    auto &data = reinterpret_cast<SpriteData *&>(raw_data);

    if (data == nullptr)
        return;
    if (data->texture != nullptr)
        SDL_DestroyTexture(data->texture);
    delete data;
}

void SDL2::draw_text(
    ass::Vector2<float> pos, std::string str, uint size, ass::TermColor color)
{
    if (TTF_WasInit() == 0)
        throw std::runtime_error("TTF wasn't loaded in SDL2");

    TTF_Font *font = TTF_OpenFont("assets/Comic Sans MS 400.ttf", size);
    if (font == nullptr)
        throw std::runtime_error("Font failed to load");
    auto *text_surface = TTF_RenderText_Solid(font, str.c_str(), COLORS.at(color));
    if (text_surface == nullptr)
        throw std::runtime_error("Font failed to load");
    auto *text = SDL_CreateTextureFromSurface(_renderer, text_surface);
    if (text == nullptr)
        throw std::runtime_error("Font failed to load");

    int text_width = text_surface->w;
    int text_height = text_surface->h;
    SDL_Rect render_quad = {
        int(pos.x) * 32, int(pos.y) * 32, text_width, text_height};

    SDL_RenderCopy(_renderer, text, nullptr, &render_quad);

    TTF_CloseFont(font);
    SDL_DestroyTexture(text);
    SDL_FreeSurface(text_surface);
}
