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

/**
 * @defgroup game Game
 */
#pragma once

#include <exception>

namespace ass {

/**
 * @interface IGame
 * @brief Game Interface
 * @details Set of method to implement for the Game part of the Arcade project
 * @ingroup game
 * @exception IGame::Exception Game’s exceptions
 */
class IGame { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    virtual ~IGame() = default;

    /**
     * @brief Game Exception
     * @details Base class for Games’s scoped exceptions
     */
    class Exception: public std::exception {};

    /**
     * @brief Run the game
     */
    virtual void run() = 0;
};
} // namespace ass

/**
 * @brief Arcade Game shared library entrypoint
 * @relates ass::IGame
 * @ingroup game
 * @attention Must be defined a return a pointer to a final class derived from IGame
 * @return pointer to a newly allocated IGame derived class
 */
extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint(void);
