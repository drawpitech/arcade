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
    if (!_sprites.contains(&sprite)) {
        std::clog << "need to create sprite" << std::endl;
    }
    // TODO: renderer.draw()
    std::clog << "need to draw sprite" << std::endl;
}

void gg::Engine::refresh() {}

void gg::Engine::clear(ass::TermColor color) {}

void gg::Engine::set_title(std::wstring title) {}

std::vector<Event> gg::Engine::events() {}

void gg::Engine::set_renderer(ass::IRenderer *renderer)
{
    _renderer.reset(renderer);
}

ass::IRenderer &gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return *_renderer;
}
