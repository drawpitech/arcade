/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#pragma once

#include <curses.h>
#include <ASS/IEngine.hpp>
#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Events.hpp>
#include <map>
#include <string>

static const std::map<int, ass::EventKey> KEYS = {
    { 'a', ass::EventKey::KeyA },
    { 'b', ass::EventKey::KeyB },
    { 'c', ass::EventKey::KeyC },
    { 'd', ass::EventKey::KeyD },
    { 'e', ass::EventKey::KeyE },
    { 'f', ass::EventKey::KeyF },
    { 'g', ass::EventKey::KeyG },
    { 'h', ass::EventKey::KeyH },
    { 'i', ass::EventKey::KeyI },
    { 'j', ass::EventKey::KeyJ },
    { 'k', ass::EventKey::KeyK },
    { 'l', ass::EventKey::KeyL },
    { 'm', ass::EventKey::KeyM },
    { 'n', ass::EventKey::KeyN },
    { 'o', ass::EventKey::KeyO },
    { 'p', ass::EventKey::KeyP },
    { 'q', ass::EventKey::KeyQ },
    { 'r', ass::EventKey::KeyR },
    { 's', ass::EventKey::KeyS },
    { 't', ass::EventKey::KeyT },
    { 'u', ass::EventKey::KeyU },
    { 'v', ass::EventKey::KeyV },
    { 'w', ass::EventKey::KeyW },
    { 'x', ass::EventKey::KeyX },
    { 'y', ass::EventKey::KeyY },
    { 'z', ass::EventKey::KeyZ },
    { KEY_UP, ass::EventKey::KeyUp },
    { KEY_DOWN, ass::EventKey::KeyDown },
    { KEY_LEFT, ass::EventKey::KeyLeft },
    { KEY_RIGHT, ass::EventKey::KeyRight },
    { '\n', ass::EventKey::KeyEnter },
    { ' ', ass::EventKey::KeySpace },
    { -1, ass::EventKey::MouseRight },
    { -1, ass::EventKey::MouseMiddle },
    { -1, ass::EventKey::MouseLeft },
};

class NCurses : public ass::IRenderer
{
   public:
    struct Properties
    {
        std::wstring title;
    };

    NCurses();
    ~NCurses() override;

    void refresh() final;
    void clear(ass::TermColor color) final;
    void set_title(std::wstring title) final;
    void draw_sprite(ass::ISprite &sprite, void *&raw_data) final;
    void free_sprite(void *&raw_data) final;
    void draw_text(ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color) final;

    ass::Vector2<size_t> get_window_size() const final;
    std::vector<ass::Event> events() final;
};
