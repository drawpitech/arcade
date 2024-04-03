/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

#include <dlfcn.h>

#include <ASS/IGame.hpp>
#include <memory>

#include "Engine.hpp"
#include "SharedObject.hpp"

gg::Arcade::Arcade(int argc, char **argv) : _args(argc, argv)
{
    if (_args & gg::Arg::HELP) {
        Args::showHelp();
        exit(0);
    }

    auto game = _args.getGame();
    auto renderer = _args.getRenderer();

    if (game.empty() || renderer.empty())
        throw gg::Exception("Missing arguments");

    _game = std::make_unique<gg::SharedObject>(_args.getGame());
    _renderer = std::make_unique<gg::SharedObject>(_args.getRenderer());
}

gg::Arcade::~Arcade() = default;

int gg::Arcade::run()
{
    gg::Engine engine;
    engine.set_renderer(_renderer->get<ass::IRenderer>());

    auto game = _game->get<ass::IGame>();
    bool running = true;
    while (running) {
        switch (game->run(engine)) {
            case ass::RunStatus::Exit:
                running = false;
                break;
            case ass::RunStatus::Restart:
                game = _game->get<ass::IGame>();
                break;
            case ass::RunStatus::ShowMenu:
            case ass::RunStatus::NextGame:
                throw std::runtime_error("Not implemented");
        }
    }
    return 0;
}
