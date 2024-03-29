/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#include "SDL2.hpp"

#include <SDL.h>
#include <SDL2/SDL_image.h>

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <iostream>

extern "C" ass::IRenderer *uwu_goofy_ahhh_renderer_entrypoint()
{
    return new SDL2();
}

SDL2::SDL2() : _window(nullptr), _renderer(nullptr)
{
    int rendererFlags = SDL_RENDERER_ACCELERATED;
    int windowFlags = 0;

    int HEIGHT = 720;
    int WIDTH = 1200;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    _window = SDL_CreateWindow(
        "Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, windowFlags);

    if (_window == nullptr) {
        printf(
            "Failed to open %d x %d window: %s\n", WIDTH, HEIGHT,
            SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    _renderer = SDL_CreateRenderer(_window, -1, rendererFlags);

    if (_renderer == nullptr) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

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

void SDL2::clear(ass::TermColor /*color*/)
{
    SDL_SetRenderDrawColor(_renderer, 96, 128, 255, 255);
    SDL_RenderClear(_renderer);
}

void SDL2::set_title(std::wstring title) {}

void SDL2::draw_sprite(ass::ISprite &sprite, void *&raw_data)
{
    auto &texture = reinterpret_cast<SDL_Texture *&>(raw_data);

    if (raw_data == nullptr)
        texture = IMG_LoadTexture(_renderer, sprite.get_asset().path.c_str());

    SDL_Rect dest;
    dest.x = int(sprite.position().x) * 32;
    dest.y = int(sprite.position().y) * 32;

    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    SDL_RenderCopy(_renderer, texture, nullptr, &dest);
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
        switch (event.type) {
            case SDL_QUIT:
                events.push_back(
                    {ass::EventKey::KeyQ, ass::EventState::KeyPressed});
                break;

            case SDL_KEYDOWN:
                if (KEYS.contains(event.key.keysym.scancode))
                    events.push_back(
                        {KEYS.at(event.key.keysym.scancode),
                         ass::EventState::KeyPressed});
                break;
            case SDL_KEYUP:
                if (KEYS.contains(event.key.keysym.scancode))
                    events.push_back(
                        {KEYS.at(event.key.keysym.scancode),
                         ass::EventState::KeyReleased});
                break;
            default:
                break;
        }
    }
    return events;
}

void SDL2::free_sprite(void *&raw_data)
{
    SDL_DestroyTexture(reinterpret_cast<SDL_Texture *&>(raw_data));
}


void SDL2::draw_text(ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color)
{
    // TODO
}
