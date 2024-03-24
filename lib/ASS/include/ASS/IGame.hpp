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
class IGame { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    virtual ~IGame() = default;

    class Exception: public std::exception {};

    virtual void start(ass::IEngine *engine) = 0;

    virtual void run() = 0;

    virtual void stop() = 0;
};

} // namespace ass

extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint();
