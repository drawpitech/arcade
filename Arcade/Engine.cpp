/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#include "Engine.hpp"

#include <memory>

#include "Sprite.hpp"

gg::Engine::Engine() = default;
gg::Engine::~Engine() = default;

std::unique_ptr<ass::ISprite> gg::Engine::create_sprite()
{
    return std::make_unique<gg::Sprite>();
}

void gg::Engine::draw_sprite(ass::ISprite &sprite)
{
    if (!_sprites.contains(&sprite))
        _sprites.insert({&sprite, nullptr});
    _renderer->draw_sprite(sprite, _sprites.at(&sprite));
}

void gg::Engine::refresh()
{
    _renderer->refresh();
}

void gg::Engine::clear(ass::TermColor color)
{
    _renderer->clear(color);
}

std::vector<ass::Event> gg::Engine::events()
{
    return _renderer->events();
}

void gg::Engine::draw_text(
    ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color)
{
    _renderer->draw_text(pos, text, size, color);
}

void gg::Engine::set_renderer(ass::IRenderer *renderer)
{
    for (auto &[_, data] : _sprites)
        _renderer->free_sprite(data);
    _sprites.clear();
    _renderer.reset(renderer);
}

ass::IRenderer &gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return *_renderer;
}
