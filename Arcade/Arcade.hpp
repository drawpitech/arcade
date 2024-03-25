/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <cstdint>
#include <memory>

#include "Args.hpp"
#include "SharedObject.hpp"

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
    std::unique_ptr<gg::SharedObject> _game;
    std::unique_ptr<gg::SharedObject> _renderer;
};

}  // namespace gg
