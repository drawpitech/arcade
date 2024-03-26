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

#include <exception>

#include "IEngine.hpp"

namespace ass {

/**
 * @brief Game Interface
 * @details Set of method to implement for the Game part of the Arcade project
 */
class IGame {
public:
    class Exception: public std::exception {};

    IGame() = default;
    virtual ~IGame() = default;
    virtual void run(ass::IEngine &) = 0;;

    IGame(const IGame &) = default;
    IGame(IGame &&) = delete;
    IGame &operator=(const IGame &) = default;
    IGame &operator=(IGame &&) = delete;
};

}  // namespace ass

extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint();
