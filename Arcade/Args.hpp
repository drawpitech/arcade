/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Args
*/

#pragma once

#include <cstdint>
#include <list>
#include <string>

namespace gg {

using arg_t = std::uint16_t;

class Args
{
   public:
    Args(int argc, char **argv);
    ~Args();

    static void showHelp();
    bool operator&(const arg_t &other) const;

    [[nodiscard]] const std::string &getRenderer() const;

   private:
    arg_t _args;
    std::string renderer;

    void getLongArg(const std::string &name);
    void getShortArg(char c);
};

class Arg
{
   public:
    enum Type : arg_t
    {
        HELP = 1 << 0,
    };

    Arg(char c, std::string name, std::string description, arg_t arg);

    char c;
    std::string name;
    std::string description;
    arg_t arg;
};

static const std::list<Arg> ARGS = {
    {'h', "help", "Display the help message", Arg::Type::HELP},
};

}  // namespace gg
