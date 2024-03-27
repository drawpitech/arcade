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
#include <vector>

#include "Snake.hpp"

Player::Player(ass::IEngine &engine)
    : _sprite(engine.create_sprite()), _direction{Direction::Right}
{
    _sprite->set_asset({
        .sprite =
            {
                .height = 1,
                .width = 1,
                .chars = {{'o'}},
            },
        .path = "",
    });

    grow();
}

void Player::grow()
{
    if (_body.size() == 0)
        _body.push_back({0, 0});
    else
        _body.push_back(_body.back());
}

void Player::move()
{
    // Move the tail
    for (size_t i = _body.size() - 1; i > 0; i--)
        _body.at(i) = _body.at(i - 1);

    // Move the head
    auto &head = get_head();
    switch (_direction) {
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

bool Player::is_dead(ass::IEngine &engine)
{
    auto head = get_head();

    // Touches the tail
    for (size_t i = 1; i < _body.size(); i++)
        if (head.x == _body.at(i).x && head.y == _body.at(i).y)
            return true;

    // Out of bounds
    auto [width, height] = engine.get_renderer().get_window_size();
    return head.x < 0 || head.x >= width || head.y < 0 || head.y >= height;
}

Direction Player::get_direction()
{
    return _direction;
}

void Player::set_direction(Direction direction)
{
    _direction = direction;
}

pos_t &Player::get_head()
{
    return _body.at(0);
}

void Player::draw(ass::IEngine &engine)
{
    for (auto &part : _body) {
        _sprite->move({part.x, part.y});
        engine.draw_sprite(*_sprite);
    }
}