/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#pragma once

#include <ASS/Events.hpp>
#include <ASS/IEngine.hpp>
#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <string>

static const std::map<sf::Keyboard::Key, ass::EventKey> KEYS = {
    {sf::Keyboard::A, ass::EventKey::KeyA},
    {sf::Keyboard::B, ass::EventKey::KeyB},
    {sf::Keyboard::C, ass::EventKey::KeyC},
    {sf::Keyboard::D, ass::EventKey::KeyD},
    {sf::Keyboard::E, ass::EventKey::KeyE},
    {sf::Keyboard::F, ass::EventKey::KeyF},
    {sf::Keyboard::G, ass::EventKey::KeyG},
    {sf::Keyboard::H, ass::EventKey::KeyH},
    {sf::Keyboard::I, ass::EventKey::KeyI},
    {sf::Keyboard::J, ass::EventKey::KeyJ},
    {sf::Keyboard::K, ass::EventKey::KeyK},
    {sf::Keyboard::L, ass::EventKey::KeyL},
    {sf::Keyboard::M, ass::EventKey::KeyM},
    {sf::Keyboard::N, ass::EventKey::KeyN},
    {sf::Keyboard::O, ass::EventKey::KeyO},
    {sf::Keyboard::P, ass::EventKey::KeyP},
    {sf::Keyboard::Q, ass::EventKey::KeyQ},
    {sf::Keyboard::R, ass::EventKey::KeyR},
    {sf::Keyboard::S, ass::EventKey::KeyS},
    {sf::Keyboard::T, ass::EventKey::KeyT},
    {sf::Keyboard::U, ass::EventKey::KeyU},
    {sf::Keyboard::V, ass::EventKey::KeyV},
    {sf::Keyboard::W, ass::EventKey::KeyW},
    {sf::Keyboard::X, ass::EventKey::KeyX},
    {sf::Keyboard::Y, ass::EventKey::KeyY},
    {sf::Keyboard::Z, ass::EventKey::KeyZ},
    {sf::Keyboard::Up, ass::EventKey::KeyUp},
    {sf::Keyboard::Down, ass::EventKey::KeyDown},
    {sf::Keyboard::Left, ass::EventKey::KeyLeft},
    {sf::Keyboard::Right, ass::EventKey::KeyRight},
    {sf::Keyboard::Return, ass::EventKey::KeyEnter},
    {sf::Keyboard::Space, ass::EventKey::KeySpace},
    /* { 0, ass::EventKey::MouseRight }, */
    /* { 0, ass::EventKey::MouseMiddle }, */
    /* { 0, ass::EventKey::MouseLeft } */
};

static const std::map<ass::TermColor, sf::Color> COLORS = {
    {ass::TermColor::Black, sf::Color::Black},
    {ass::TermColor::Maroon, sf::Color::Black},
    {ass::TermColor::Green, sf::Color::Green},
    {ass::TermColor::Olive, sf::Color::Green},
    {ass::TermColor::Navy, sf::Color::Blue},
    {ass::TermColor::Purple, sf::Color::Blue},
    {ass::TermColor::Teal, sf::Color::Blue},
    {ass::TermColor::Silver, sf::Color::White},
    {ass::TermColor::Grey, sf::Color::White},
    {ass::TermColor::Red, sf::Color::Red},
    {ass::TermColor::Lime, sf::Color::Green},
    {ass::TermColor::Yellow, sf::Color::Yellow},
    {ass::TermColor::Blue, sf::Color::Blue},
    {ass::TermColor::Fuchsia, sf::Color::Magenta},
    {ass::TermColor::Aqua, sf::Color::Cyan},
    {ass::TermColor::White, sf::Color::White},
};

class RSFML : public ass::IRenderer
{
   public:
    struct Properties
    {
        std::wstring title;
    };

    RSFML();
    ~RSFML() override;

    void refresh() final;
    void clear(ass::TermColor color) final;
    void set_title(std::wstring title) final;
    void draw_sprite(ass::ISprite &sprite, void *&raw_data) final;
    void free_sprite(void *&raw_data) final;
    void draw_text(
        ass::Vector2<float> pos, std::string text, uint size,
        ass::TermColor color) final;

    ass::Vector2<size_t> get_window_size() const final;
    std::vector<ass::Event> events() final;

   private:
    sf::RenderWindow _window;
    sf::Font _font;
};

struct RawSpriteData
{
    sf::Sprite sprite;
    sf::Texture texture;
};
