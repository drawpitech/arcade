/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Player
*/

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>
#include <cmath>
#include <iostream>
#include <vector>

#include "Nibbler.hpp"

Player::Player(ass::IEngine &engine)
    : _sprite(engine.create_sprite()),
      _current_direction(Direction::Right),
      _last_direction(_current_direction)
{
    _sprite->set_asset({
        .sprite =
            {
                .height = 1,
                .width = 1,
                .chars = {{'o'}},
                .char_colors = {{ass::xterm_color_t(ass::TermColor::White)}},
            },
        .path = "assets/nibbler/snake.png",
    });

    const auto [w, h] = engine.get_renderer().get_window_size();
    for (size_t i = 0; i < 4; i++)
        _body.push_back({static_cast<float>(4 - i), 1});
}

void Player::grow()
{
    if (_body.empty())
        throw std::runtime_error("Snake has no body *sad noises*");
    _body.push_back(_body.back());
}

bool Player::is_safe(Direction dir, Map &map)
{
    pos_t pos{get_head()};
    switch (dir) {
        case Direction::Up:
            pos.y -= 1;
            break;
        case Direction::Down:
            pos.y += 1;
            break;
        case Direction::Right:
            pos.x += 1;
            break;
        case Direction::Left:
            pos.x -= 1;
            break;
    }
    return map.get_tile(pos) == Map::MapPart::Void;
}

void Player::move(Fruit &fruit, Map &map)
{

    // Check that the snake doesn't do a 360 no scope
    if (is_safe(_current_direction, map) && int(_last_direction) / 2 != int(_current_direction) / 2)
        _last_direction = _current_direction;
    else
        _current_direction = _last_direction;

    // Move the head
    auto &head = get_head();
    if (is_safe(_current_direction, map)) {
        // Move the tail
        for (size_t i = _body.size() - 1; i > 0; i--)
            _body.at(i) = _body.at(i - 1);

        // Move the head
        switch (_current_direction) {
            case Direction::Up:
                head.y -= 1;
                break;
            case Direction::Down:
                head.y += 1;
                break;
            case Direction::Right:
                head.x += 1;
                break;
            case Direction::Left:
                head.x -= 1;
                break;
        }
    }

    // The snake touches the fruit
    auto fruit_pos = fruit.position();
    if (head.x == fruit_pos.x && head.y == fruit_pos.y) {
        fruit.move(get_tail());
        grow();
    }
}

bool Player::is_dead(ass::IEngine &engine)
{
    auto head = get_head();

    // Touches the tail
    for (size_t i = 2; i < _body.size(); i++)
        if (head.x == _body.at(i).x && head.y == _body.at(i).y)
            return true;
    return false;
}

void Player::set_direction(Direction direction, Map &map)
{
    if (int(direction) / 2 != int(_current_direction) / 2)
        _current_direction = direction;
}

pos_t &Player::get_head()
{
    return _body.at(0);
}

pos_t &Player::get_tail()
{
    return _body.at(_body.size() - 1);
}

void Player::draw(ass::IEngine &engine)
{
    for (auto &part : _body) {
        _sprite->move({part.x, part.y});
        engine.draw_sprite(*_sprite);
    }
}

size_t Player::get_size() const
{
    return _body.size();
}
