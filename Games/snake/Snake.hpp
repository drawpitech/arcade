/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/IGame.hpp>

class Snake : public ass::IGame
{
   public:
    Snake();
    ~Snake() override;

    void run(ass::IEngine &engine) final;
};
