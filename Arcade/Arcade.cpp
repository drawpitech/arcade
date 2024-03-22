/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

#include <iostream>
#include <span>

#include "Exception.hpp"

gg::Arcade::Arcade(int argc, char **argv)
{
    for (std::string arg : std::span(argv, argc).subspan(1)) {
        if (arg.empty())
            throw gg::Exception("Empty argument");

        // Game path argument
        if (arg.at(0) != '-') {
            if (!_gamepath.empty())
                throw gg::Exception("Too many arguments");
            _gamepath = arg;
            continue;
        }

        // Long argument
        if (arg.at(1) == '-') {
            std::string name = arg.substr(2);
            bool found = false;

            for (const auto &argpair : ARGS) {
                if (argpair.name == name) {
                    _args |= argpair.arg;
                    found = true;
                    break;
                }
            }
            if (!found)
                throw gg::Exception("Unknown argument: --" + name);
        }

        // Short arguments
        for (const auto &c : arg.substr(1)) {
            bool found = false;

            for (const auto &argpair : ARGS) {
                if (argpair.c == c) {
                    _args |= argpair.arg;
                    found = true;
                    break;
                }
            }
            if (!found)
                throw gg::Exception("Unknown argument: -" + std::string{c});
        }
    }
    if ((_args & gg::Arg::HELP) != 0) {
        print_help();
        exit(0);
    }
    if (_gamepath.empty())
        throw gg::Exception("No game path provided");
}

void gg::Arcade::print_help()
{
    std::cout << "USAGE:\n"
              << "\tarcade [OPTIONS] <gamepath>\n\n"
              << "OPTIONS:\n";
    for (const auto &arg : ARGS) {
        std::cout << "\t";
        if (arg.c != 0)
            std::cout << " -" << arg.c;
        if (!arg.name.empty())
            std::cout << " --" << arg.name;
        std::cout << ": " << arg.description << std::endl;
    }
}

int gg::Arcade::run()
{
    return 0;
}
