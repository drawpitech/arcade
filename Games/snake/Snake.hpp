/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <ASS/IGame.hpp>

class Snake : public ass::IGame
{
    void start() final;

    void run() final;

    void stop() final;
};
