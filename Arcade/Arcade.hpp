/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <cstdint>
#include <functional>
#include <list>
#include <memory>
#include <string>
#include <utility>

#include "ASS/IGame.hpp"

namespace gg {

using arg_t = std::uint16_t;
using entrypoint_t = ass::IGame *(*)();

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
    arg_t _args;
    void *_handle;
    std::unique_ptr<ass::IGame> _game;

    std::string loadArgs(int argc, char **argv);
    static void printHelp();
};

class Arg
{
   public:
    enum
    {
        HELP = 1 << 0,
    };

    Arg(char c, std::string name, std::string description, arg_t arg)
        : c(c),
          name(std::move(name)),
          description(std::move(description)),
          arg(arg)
    {
    }

    char c;
    std::string name;
    std::string description;
    arg_t arg;
};

static const std::list<Arg> ARGS = {
    {'h', "help", "Display the help message", Arg::HELP},
};
}  // namespace gg
