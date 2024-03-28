/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Args
*/

#include "Args.hpp"

#include <iostream>
#include <span>
#include <string>

#include "Exception.hpp"

gg::Args::Args(int argc, char **argv) : _args(0)
{
    for (std::string arg : std::span(argv, argc).subspan(1)) {
        if (arg.empty())
            throw gg::Exception("Empty argument");

        if (arg.at(0) == '-') {
            // Long argument
            if (arg.at(1) == '-') {
                getLongArg(arg.substr(2));
                continue;
            }

            // Short arguments
            for (const auto &c : arg.substr(1))
                getShortArg(c);
            continue;
        }

        // Game path argument
        if (game.empty()) {
            game = std::move(arg);
            continue;
        }
        if (renderer.empty()) {
            renderer = std::move(arg);
            continue;
        }
        throw gg::Exception("Too many arguments");
    }
}

gg::Args::~Args() = default;

void gg::Args::getLongArg(const std::string &name)
{
    for (const auto &arg : ARGS) {
        if (!arg.name.empty() && arg.name == name) {
            _args |= arg.arg;
            return;
        }
    }
    throw gg::Exception("Unknown argument: --" + name);
}

void gg::Args::getShortArg(char c)
{
    for (const auto &arg : ARGS) {
        if (arg.c != '\0' && arg.c == c) {
            _args |= arg.arg;
            return;
        }
    }
    throw gg::Exception("Unknown argument: -" + std::string{c});
}

void gg::Args::showHelp()
{
    std::cout << "USAGE:\n"
              << "\tarcade [OPTIONS] <gamepath> <graphicpath>\n\n"
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

bool gg::Args::operator&(const arg_t &other) const
{
    return (_args & other) == other;
}

const std::string &gg::Args::getGame() const
{
    return game;
}

const std::string &gg::Args::getRenderer() const
{
    return renderer;
}

gg::Arg::Arg(char c, std::string name, std::string description, arg_t arg)
    : c(c), name(std::move(name)), description(std::move(description)), arg(arg)
{
}
