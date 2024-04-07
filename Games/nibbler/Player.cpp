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
#include <vector>

#include "Nibbler.hpp"

Player::Player(ass::IEngine &engine)
    : _sprite(engine.create_sprite()), _current_direction(Direction::Right)
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
        _body.push_back({
            std::round(static_cast<float>(w) / 2) - i,
            std::round(static_cast<float>(h) / 2),
        });
}

void Player::grow()
{
    if (_body.empty())
        throw std::runtime_error("Snake has no body *sad noises*");
    _body.push_back(_body.back());
}

void Player::move(ass::IEngine &engine, Fruit &fruit)
{
    // Move the tail
    for (size_t i = _body.size() - 1; i > 0; i--)
        _body.at(i) = _body.at(i - 1);

    if (!_directions.empty()) {
        auto direction = _directions.front();
        _directions.pop();

        // Check that the snake doesn't do a 360 no scope
        if (int(direction) / 2 != int(_current_direction) / 2)
            _current_direction = direction;
    }

    // Move the head
    auto &head = get_head();
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

    // Out of bounds
    auto [width, height] = engine.get_renderer().get_window_size();
    return head.x < 0 || head.x >= width || head.y < 0 || head.y >= height;
}

void Player::set_direction(Direction direction)
{
    _directions.push(direction);
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
