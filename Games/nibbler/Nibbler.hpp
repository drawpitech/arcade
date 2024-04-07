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

class Nibbler : public ass::IGame
{
   public:
    Nibbler();
    ~Nibbler() override;

    std::pair<ass::RunStatus, size_t> run(ass::IEngine &engine) final;
};

enum class Direction
{
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
    void move(pos_t pos);
    pos_t position();

   private:
    std::unique_ptr<ass::ISprite> _sprite;
};

class Map
{
   public:
    Map(ass::IEngine &engine);
    ~Map();

    enum class MapPart : char
    {
        Void,
        Wall,
    };

    MapPart get_tile(pos_t pos) const;
    void draw(ass::IEngine &engine);

   private:
    std::vector<std::vector<MapPart>> _map;
    std::unique_ptr<ass::ISprite> _sprite;
};

class Player
{
   public:
    Player(ass::IEngine &engine);
    ~Player() = default;

    void draw(ass::IEngine &engine);
    void move(Fruit &fruit, Map &map);
    bool is_dead(ass::IEngine &engine);
    void grow();
    void set_direction(Direction direction, Map &map);

    pos_t &get_head();
    pos_t &get_tail();
    size_t get_size() const;

   private:
    std::unique_ptr<ass::ISprite> _sprite;
    Direction _current_direction;
    Direction _last_direction;
    std::vector<pos_t> _body;

    bool is_safe(Direction dir, Map &map);
};

static const std::vector<std::string> MAP{
    "OOOOOOOOOOOOOOOOOOO",
    "O                 O",
    "O OOO O OOO O OOO O",
    "O O O O     O O O O",
    "O OOO O O O O OOO O",
    "O     O O O O     O",
    "O OOOOO O O OOOOO O",
    "O O             O O",
    "O O OOOOO OOOOO O O",
    "O                 O",
    "O OOOOO OOO OOOOO O",
    "O       O O       O",
    "O OOO O OOO O OOO O",
    "O O O O     O O O O",
    "O OOO O OOO O OOO O",
    "O     O O O O     O",
    "O OOOOO OOO OOOOO O",
    "O                 O",
    "OOOOOOOOOOOOOOOOOOO",
};
