/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sprite
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/ISprite.hpp>

namespace gg {

class Sprite : public ass::ISprite
{
   public:
    Sprite();
    ~Sprite() override;

    void set_asset(ass::SpriteAssets asset) final;

    void move(Vector2<float> pos) final;
    Vector2<float> position() final;

   private:
    Vector2<float> _position;
};

}  // namespace gg
