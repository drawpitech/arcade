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

#include <cstddef>
#include <exception>
#include <memory>
#include <utility>

#include "IEngine.hpp"

namespace ass {
/**
 * @brief Enumeration of the Results of a game
 * @details the Menu use this status to know what to do
 */
enum class RunStatus
{
    Exit, /// Entirely Quit the program (key Q)
    Restart, /// Restart the game (key R)
    NextGame, /// switch to next game
    ShowMenu, /// Display the menu
};

/**
 * @interface IGame
 * @brief Game Interface
 * @details Set of method to implement for the Game part of the Arcade project
 * @ingroup game
 * @exception IGame::Exception Game’s exceptions
 */
class IGame
{
   public:
    /**
     * @brief Game Exception
     * @details Base class for Games’s scoped exceptions
     */
    class Exception : public std::exception
    {};

    IGame() = default;
    virtual ~IGame() = default;

    /**
     * @brief Run the game
     * @details All the game must start from this method. The game must only use
     * the renderer throught the engine's methods. You must implement these keys :
     * - q -> quit the game (Runstatus::Exit)
     * - n -> switch to next renderer (use `engine.next_renderer()`)
     * - g -> change to next game : properly end the game and return (Runstatus::NextGame)
     * - m -> go back to menu : properly end the game and return (Runstatus::ShowMenu)
     * - r -> restart the game : properly end the game and return (Runstatus::Restart)
     *
     * @param engine Engine
     * @return pair of Runstatus and score, check the Runstatus enum description for more details.
     */
    virtual std::pair<RunStatus, size_t> run(IEngine &engine) = 0;

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
 * @attention Must be defined and return an unique pointer to a final class
 * derived from IGame
 * @return unique pointer to a newly allocated IGame derived class
 */
extern "C" std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint(void);
