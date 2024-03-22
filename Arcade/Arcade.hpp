/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <cstdint>
#include <list>
#include <string>
#include <utility>

namespace gg {

using arg_t = std::uint16_t;

/**
 * Main class of the arcade
 */
class Arcade
{
   public:
    /**
     * Take the arguments directly from the main function
     * @param argc The number of arguments
     * @param argv The arguments
     */
    Arcade(int argc, char **argv);

    /**
     * Run the arcade
     */
    int run();

   private:
    std::string _gamepath;
    arg_t _args;

    void print_help();
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
