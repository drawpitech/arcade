/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite
*/

#include "Sprite.hpp"

gg::Sprite::Sprite() : _position(0, 0) {}

gg::Sprite::~Sprite() = default;

void gg::Sprite::set_asset(ass::SpriteAssets assets) {
    _assets = assets;
}

ass::SpriteAssets &gg::Sprite::get_asset() {
    return _assets;
}

void gg::Sprite::move(ass::Vector2<float> pos)
{
    _position = pos;
}

ass::Vector2<float> gg::Sprite::position()
{
    return _position;
}
