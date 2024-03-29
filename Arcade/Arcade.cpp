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
    auto &engine = get_engine_singleton();
    engine.set_renderer(_renderer->get<ass::IRenderer>());

    std::unique_ptr<ass::IGame> game{_game->get<ass::IGame>()};
    game->run();
    engine.set_renderer(nullptr);
    return 0;
}
