/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

#include <ASS/IGame.hpp>
#include <iostream>

extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint()
{
    return new Snake();
}

void Snake::start()
{
    std::clog << "Start snake game." << std::endl;
}

void Snake::run()
{
    std::clog << "Run   snake game." << std::endl;
}

void Snake::stop()
{
    std::clog << "Stop  snake game." << std::endl;
}
