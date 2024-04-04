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

    if (_args.getRenderer().empty())
        throw gg::Exception("Missing arguments");
}

gg::Arcade::~Arcade() = default;

int gg::Arcade::run() const
{
    gg::Engine engine;
    engine.set_renderer(_args.getRenderer());

    std::unique_ptr<gg::SharedObject> game = nullptr;
    gg::Menu::show(engine, game);
    auto game_instance = game->get<ass::IGame>();

    for (bool running = true; running;) {
        switch (game_instance->run(engine)) {
            case ass::RunStatus::Exit:
                running = false;
                break;
            case ass::RunStatus::Restart:
                game_instance = game->get<ass::IGame>();
                engine.clear_sprites();
                break;
            case ass::RunStatus::ShowMenu:
                gg::Menu::show(engine, game);
                game_instance = game->get<ass::IGame>();
                break;
            case ass::RunStatus::NextGame:
                throw std::runtime_error("Not implemented");
        }
    }
    return 0;
}
