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
#include "Menu.hpp"
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

    auto game_instance = _game->get<ass::IGame>();

    for (bool running = true; running;) {
        switch (game_instance->run(engine)) {
            case ass::RunStatus::Exit:
                running = false;
                break;
            case ass::RunStatus::Restart:
                game_instance = _game->get<ass::IGame>();

                // while we don't have a `engine::clear_spites()`
                engine.set_renderer(_renderer->get<ass::IRenderer>());
                break;
            case ass::RunStatus::ShowMenu:
                gg::Menu::show(engine, _game, _renderer);
                game_instance = _game->get<ass::IGame>();
                break;
            case ass::RunStatus::NextGame:
                throw std::runtime_error("Not implemented");
        }
    }
    return 0;
}
