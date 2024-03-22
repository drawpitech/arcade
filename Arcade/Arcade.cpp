/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

#include <dlfcn.h>

#include <ASS/IGame.hpp>
#include <iostream>
#include <span>

#include "Exception.hpp"

gg::Arcade::Arcade(int argc, char **argv) : _args(0)
{
    std::string gamepath = loadArgs(argc, argv);
    if (gamepath.empty())
        throw gg::Exception("No game path provided");

    // Get entrypoint
    _handle = dlopen(gamepath.c_str(), RTLD_LAZY);
    if (_handle == nullptr)
        throw gg::Exception(dlerror());
    void *entrypoint = dlsym(_handle, "uwu_goofy_ahhh_game_entrypoint");
    if (entrypoint == nullptr)
        throw gg::Exception(dlerror());
    _game.reset(reinterpret_cast<entrypoint_t>(entrypoint)());
}

gg::Arcade::~Arcade()
{
    _game.reset(nullptr);
    // explicitly free the pointer, because we close the handle later,
    // and we lost the pointer and cannot free the memory later
    dlclose(_handle);
}

std::string gg::Arcade::loadArgs(int argc, char **argv)
{
    std::string gamepath;

    for (std::string arg : std::span(argv, argc).subspan(1)) {
        if (arg.empty())
            throw gg::Exception("Empty argument");

        // Game path argument
        if (arg.at(0) != '-') {
            if (!gamepath.empty())
                throw gg::Exception("Too many arguments");
            gamepath = arg;
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
        printHelp();
        exit(0);
    }
    return std::move(gamepath);
}

void gg::Arcade::printHelp()
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
    _game->start();
    _game->run();
    _game->stop();
    return 0;
}
