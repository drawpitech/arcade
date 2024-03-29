/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SDL2
*/

#pragma once

#include <SDL.h>

#include <ASS/Events.hpp>
#include <ASS/IEngine.hpp>
#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <map>
#include <string>

static const std::map<SDL_Scancode, ass::EventKey> KEYS = {
    { SDL_SCANCODE_A, ass::EventKey::KeyA },
    { SDL_SCANCODE_B, ass::EventKey::KeyB },
    { SDL_SCANCODE_C, ass::EventKey::KeyC },
    { SDL_SCANCODE_D, ass::EventKey::KeyD },
    { SDL_SCANCODE_E, ass::EventKey::KeyE },
    { SDL_SCANCODE_F, ass::EventKey::KeyF },
    { SDL_SCANCODE_G, ass::EventKey::KeyG },
    { SDL_SCANCODE_H, ass::EventKey::KeyH },
    { SDL_SCANCODE_I, ass::EventKey::KeyI },
    { SDL_SCANCODE_J, ass::EventKey::KeyJ },
    { SDL_SCANCODE_K, ass::EventKey::KeyK },
    { SDL_SCANCODE_L, ass::EventKey::KeyL },
    { SDL_SCANCODE_M, ass::EventKey::KeyM },
    { SDL_SCANCODE_N, ass::EventKey::KeyN },
    { SDL_SCANCODE_O, ass::EventKey::KeyO },
    { SDL_SCANCODE_P, ass::EventKey::KeyP },
    { SDL_SCANCODE_Q, ass::EventKey::KeyQ },
    { SDL_SCANCODE_R, ass::EventKey::KeyR },
    { SDL_SCANCODE_S, ass::EventKey::KeyS },
    { SDL_SCANCODE_T, ass::EventKey::KeyT },
    { SDL_SCANCODE_U, ass::EventKey::KeyU },
    { SDL_SCANCODE_V, ass::EventKey::KeyV },
    { SDL_SCANCODE_W, ass::EventKey::KeyW },
    { SDL_SCANCODE_X, ass::EventKey::KeyX },
    { SDL_SCANCODE_Y, ass::EventKey::KeyY },
    { SDL_SCANCODE_Z, ass::EventKey::KeyZ },
    { SDL_SCANCODE_UP, ass::EventKey::KeyUp },
    { SDL_SCANCODE_DOWN, ass::EventKey::KeyDown },
    { SDL_SCANCODE_LEFT, ass::EventKey::KeyLeft },
    { SDL_SCANCODE_RIGHT, ass::EventKey::KeyRight },
    { SDL_SCANCODE_RETURN, ass::EventKey::KeyEnter },
    { SDL_SCANCODE_SPACE, ass::EventKey::KeySpace },
    /* { 0, ass::EventKey::MouseRight }, */
    /* { 0, ass::EventKey::MouseMiddle }, */
    /* { 0, ass::EventKey::MouseLeft } */
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
