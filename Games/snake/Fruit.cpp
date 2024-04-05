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

#include "Snake.hpp"

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
        .path = "./Games/snake/assets/fruit.png",
    });
    move(engine);
}

void Fruit::move(ass::IEngine &engine)
{
    auto [width, height] = engine.get_renderer().get_window_size();
    _sprite->move({
        static_cast<float>(rand() % width),
        static_cast<float>(rand() % height),
    });
}

pos_t Fruit::position()
{
    return _sprite->position();
}

void Fruit::draw(ass::IEngine &engine)
{
    engine.draw_sprite(*_sprite);
}
