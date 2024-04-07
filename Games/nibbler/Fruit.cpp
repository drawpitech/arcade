/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Fruit
*/

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>

#include "Nibbler.hpp"

Fruit::Fruit(ass::IEngine &engine) : _sprite(engine.create_sprite())
{
    _sprite->set_asset({
        .sprite =
            {
                .height = 1,
                .width = 1,
                .chars = {{'x'}},
                .char_colors = {{ass::xterm_color_t(ass::TermColor::Red)}},
            },
        .path = "assets/nibbler/fruit.png",
    });
    _sprite->move({9, 8});
}

void Fruit::move(pos_t pos)
{
    _sprite->move(pos);
}

pos_t Fruit::position()
{
    return _sprite->position();
}

void Fruit::draw(ass::IEngine &engine)
{
    engine.draw_sprite(*_sprite);
}
