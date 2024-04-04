/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#pragma once

#include <SDL2/SDL.h>

#include <ASS/Events.hpp>
#include <ASS/IEngine.hpp>
#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <map>
#include <string>


#include <SDL2/SDL_keycode.h>

static const std::map<SDL_Keycode, ass::EventKey> KEYS = {
    { SDLK_a, ass::EventKey::KeyA },
    { SDLK_b, ass::EventKey::KeyB },
    { SDLK_c, ass::EventKey::KeyC },
    { SDLK_d, ass::EventKey::KeyD },
    { SDLK_e, ass::EventKey::KeyE },
    { SDLK_f, ass::EventKey::KeyF },
    { SDLK_g, ass::EventKey::KeyG },
    { SDLK_h, ass::EventKey::KeyH },
    { SDLK_i, ass::EventKey::KeyI },
    { SDLK_j, ass::EventKey::KeyJ },
    { SDLK_k, ass::EventKey::KeyK },
    { SDLK_l, ass::EventKey::KeyL },
    { SDLK_m, ass::EventKey::KeyM },
    { SDLK_n, ass::EventKey::KeyN },
    { SDLK_o, ass::EventKey::KeyO },
    { SDLK_p, ass::EventKey::KeyP },
    { SDLK_q, ass::EventKey::KeyQ },
    { SDLK_r, ass::EventKey::KeyR },
    { SDLK_s, ass::EventKey::KeyS },
    { SDLK_t, ass::EventKey::KeyT },
    { SDLK_u, ass::EventKey::KeyU },
    { SDLK_v, ass::EventKey::KeyV },
    { SDLK_w, ass::EventKey::KeyW },
    { SDLK_x, ass::EventKey::KeyX },
    { SDLK_y, ass::EventKey::KeyY },
    { SDLK_z, ass::EventKey::KeyZ },
    { SDLK_UP, ass::EventKey::KeyUp },
    { SDLK_DOWN, ass::EventKey::KeyDown },
    { SDLK_LEFT, ass::EventKey::KeyLeft },
    { SDLK_RIGHT, ass::EventKey::KeyRight },
    { SDLK_RETURN, ass::EventKey::KeyEnter },
    { SDLK_SPACE, ass::EventKey::KeySpace },
    /* { 0, ass::EventKey::MouseRight }, */
    /* { 0, ass::EventKey::MouseMiddle }, */
    /* { 0, ass::EventKey::MouseLeft } */
};

static const std::map<ass::TermColor, SDL_Color> COLORS = {
    {ass::TermColor::Black, { 0, 0, 0, 0 }},
    {ass::TermColor::Maroon, { 128, 0, 0, 0 }},
    {ass::TermColor::Green, { 0, 128, 0, 0 }},
    {ass::TermColor::Olive, { 128, 128, 0, 0 }},
    {ass::TermColor::Navy, { 0, 0, 128, 0 }},
    {ass::TermColor::Purple, { 128, 0, 128, 0 }},
    {ass::TermColor::Teal, { 0, 128, 128, 0 }},
    {ass::TermColor::Silver, { 192, 192, 192, 0 }},
    {ass::TermColor::Grey, { 128, 128, 128, 0 }},
    {ass::TermColor::Red, { 255, 0, 0, 0 }},
    {ass::TermColor::Lime, { 0, 255, 0, 0 }},
    {ass::TermColor::Yellow, { 255, 255, 0, 0 }},
    {ass::TermColor::Blue, { 0, 0, 255, 0 }},
    {ass::TermColor::Fuchsia, { 255, 0, 255, 0 }},
    {ass::TermColor::Aqua, { 0, 255, 255, 0 }},
    {ass::TermColor::White, { 255, 255, 255, 0 }}
};

class SDL2 : public ass::IRenderer
{
   public:
    struct Properties
    {
        std::wstring title;
    };

    SDL2();
    ~SDL2() override;

    void refresh() final;
    void clear(ass::TermColor color) final;
    void set_title(std::wstring title) final;
    void draw_sprite(ass::ISprite &sprite, void *&raw_data) final;
    void free_sprite(void *&raw_data) final;
    void draw_text(ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color) final;

    ass::Vector2<size_t> get_window_size() const final;
    std::vector<ass::Event> events() final;

   private:
    SDL_Renderer *_renderer;
    SDL_Window *_window;
};
