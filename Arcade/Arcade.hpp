/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <cstdint>
#include <list>
#include <memory>
#include <string>
#include <utility>

#include "ASS/IGame.hpp"
#include "Args.hpp"
#include "Entrypoint.hpp"

namespace gg {

using arg_t = std::uint16_t;

/**
 * Main class of the arcade
 * The loader of games
 */
class Arcade
{
   public:
    Arcade(int argc, char **argv);
    ~Arcade();

    /**
     * Run the arcade
     */
    int run();

   private:
    Args _args;
    std::unique_ptr<gg::Entrypoint<ass::IGame>> _game;
    std::unique_ptr<gg::Entrypoint<ass::IRenderer>> _renderer;
};

}  // namespace gg
