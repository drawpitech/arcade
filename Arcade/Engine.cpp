/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#include "Engine.hpp"

#include <iostream>
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
        _sprites.insert({&sprite, std::unique_ptr<void *>{nullptr}});
    _renderer->draw_sprite(sprite, *_sprites.at(&sprite));
}

void gg::Engine::refresh()
{
    _renderer->refresh();
}

void gg::Engine::clear(ass::TermColor color)
{
    _renderer->clear(color);
}

void gg::Engine::set_title(std::wstring title) {}

std::vector<Event> gg::Engine::events() {}

void gg::Engine::set_renderer(ass::IRenderer *renderer)
{
    // TODO: free all sprites
    _renderer.reset(renderer);
}

ass::IRenderer &gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return *_renderer;
}
