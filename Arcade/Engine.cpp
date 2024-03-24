/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#pragma once

#include "Engine.hpp"

gg::Engine::Engine() = default;
gg::Engine::~Engine() = default;

void gg::Engine::refresh() {}

ass::ISprite **gg::Engine::create_sprite(ass::SpriteAssets sprite) {}

void gg::Engine::clear(ass::TermColor color) {}

void gg::Engine::set_title(std::wstring title) {}

std::vector<Event> gg::Engine::events() {}

void gg::Engine::set_renderer(ass::IRenderer *renderer)
{
    _renderer.reset(renderer);
}

ass::IRenderer *gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return _renderer.get();
}
