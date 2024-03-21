/*
** EPITECH PROJECT, 2024
** Arcade System Specifications
** File description:
** IGame.hpp
*/

/**
 * @file
 *
 * @brief File declaring IGame Interface
 */
#pragma once
#include <memory>

namespace ass {

/**
 * @brief Game Interface
 * @details Set of method to implement for the Game part of the Arcade project
 */
class IGame {
public:
    virtual ~IGame() = 0;

    class Exception: public std::exception {};

    virtual void start() = 0;

    virtual void run() = 0;

    virtual void stop() = 0;
};

} // ASS

std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint();
