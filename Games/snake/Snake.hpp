/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/IGame.hpp>
#include <queue>

#include "ASS/ISprite.hpp"

class Snake : public ass::IGame
{
   public:
    Snake();
    ~Snake() override;

    ass::RunStatus run(ass::IEngine &engine) final;
};

enum class Direction {
    Up,
    Down,
    Left,
    Right,
};

using pos_t = ass::Vector2<float>;

class Fruit
{
   public:
    Fruit(ass::IEngine &engine);
    ~Fruit() = default;

    void draw(ass::IEngine &engine);
    void move(ass::IEngine &engine);
    pos_t position();

   private:
    std::unique_ptr<ass::ISprite> _sprite;
};

class Player
{
   public:
    Player(ass::IEngine &engine);
    ~Player() = default;

    void draw(ass::IEngine &engine);
    void move(ass::IEngine &engine, Fruit &fruit);
    bool is_dead(ass::IEngine &engine);
    void grow();
    void set_direction(Direction direction);

    pos_t &get_head();

   private:
    std::unique_ptr<ass::ISprite> _sprite;
    std::queue<Direction> _directions;
    Direction _current_direction;
    std::vector<pos_t> _body;
};
