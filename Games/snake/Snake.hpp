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
    void start(ass::IEngine *engine) final;
    void run() final;
    void stop() final;

   private:
    ass::IEngine *_engine;
};
