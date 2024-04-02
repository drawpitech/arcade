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
#include <memory>

#include "IEngine.hpp"

namespace ass {

/**
 * @interface IGame
 * @brief Game Interface
 * @details Set of method to implement for the Game part of the Arcade project
 * @ingroup game
 * @exception IGame::Exception Game’s exceptions
 */
class IGame {
public:
    /**
     * @brief Game Exception
     * @details Base class for Games’s scoped exceptions
     */
    class Exception: public std::exception {};

    IGame() = default;
    virtual ~IGame() = default;

    /**
     * @brief Run the game
     */
    virtual void run(IEngine &engine) = 0;

    IGame(const IGame &) = default;
    IGame(IGame &&) = delete;
    IGame &operator=(const IGame &) = default;
    IGame &operator=(IGame &&) = delete;
};

}  // namespace ass

/**
 * @brief Arcade Game shared library entrypoint
 * @relates ass::IGame
 * @ingroup game
 * @attention Must be defined a return an unique pointer to a final class derived from IGame
 * @return unique pointer to a newly allocated IGame derived class
 */
extern "C" std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint(void);
