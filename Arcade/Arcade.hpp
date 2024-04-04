/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <cstdint>

#include "Args.hpp"

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
    int run() const;

   private:
    Args _args;
};

}  // namespace gg
