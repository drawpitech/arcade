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
#include "Entrypoint.hpp"

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

    _game = std::make_unique<gg::Entrypoint<ass::IGame>>(
        _args.getGame(), "uwu_goofy_ahhh_game_entrypoint");
    _renderer = std::make_unique<gg::Entrypoint<ass::IRenderer>>(
        _args.getRenderer(), "uwu_goofy_ahhh_renderer_entrypoint");
}

gg::Arcade::~Arcade() = default;

int gg::Arcade::run()
{
    gg::Engine engine;
    engine.set_renderer(_renderer->get());

    auto *game = _game->get();
    game->start(&engine);
    game->run();
    game->stop();
    delete game;
    return 0;
}
