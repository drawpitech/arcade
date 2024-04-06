/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SFML
*/

#include "SFML.hpp"

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <SFML/Graphics.hpp>

extern "C" std::unique_ptr<ass::IRenderer> uwu_goofy_ahhh_renderer_entrypoint()
{
    return std::make_unique<RSFML>();
}

RSFML::RSFML() : _window(sf::VideoMode(1200, 720), "Arcade", sf::Style::None)
{
    if (!_window.isOpen())
        throw std::runtime_error("The window failed to open");

    if (!_font.loadFromFile("assets/Comic Sans MS 400.ttf"))
        throw std::runtime_error("Font failed to load");
}

RSFML::~RSFML()
{
    _window.close();
}

void RSFML::refresh()
{
    _window.display();
}

void RSFML::clear(ass::TermColor color)
{
    _window.clear(COLORS.at(color));
}

void RSFML::set_title(std::wstring title)
{
    _window.setTitle(title);
}

void RSFML::draw_sprite(ass::ISprite &sprite, void *&raw_data)
{
    auto &data = reinterpret_cast<RawSpriteData *&>(raw_data);

    if (data == nullptr) {
        data = new RawSpriteData;
        if (!data->texture.loadFromFile(sprite.get_asset().path))
            throw std::runtime_error("Texture failed");
        data->sprite.setTexture(data->texture);
    }

    const auto &pos = sprite.position();
    data->sprite.setPosition(pos.x * 32, pos.y * 32);
    _window.draw(data->sprite);
}

ass::Vector2<size_t> RSFML::get_window_size() const
{
    const auto [w, h] = _window.getSize();
    return {w / 32, h / 32};
}

std::vector<ass::Event> RSFML::events()
{
    std::vector<ass::Event> vec;
    sf::Event event{};
    while (_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                if (KEYS.contains(event.key.code))
                    vec.push_back(
                        {KEYS.at(event.key.code), ass::EventState::KeyPressed});
                break;
            case sf::Event::Closed:
                vec.push_back(
                    {ass::EventKey::KeyQ, ass::EventState::KeyPressed});
                break;
        }
    }
    return vec;
}

void RSFML::draw_text(
    ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color)
{
    sf::Text display_text;
    display_text.setFont(_font);
    display_text.setString(text);
    display_text.setCharacterSize(size);
    display_text.setFillColor(COLORS.at(color));
    display_text.setPosition(pos.x * 32, pos.y * 32);
    _window.draw(display_text);
}

void RSFML::free_sprite(void *&raw_data)
{
    delete reinterpret_cast<RawSpriteData *&>(raw_data);
}
