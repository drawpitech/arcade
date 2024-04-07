/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"

#include <dlfcn.h>

#include <ASS/IGame.hpp>
#include <algorithm>
#include <iostream>
#include <memory>

#include "Engine.hpp"
#include "Menu.hpp"
#include "SharedObject.hpp"

gg::Arcade::Arcade(int argc, char** argv) : _args(argc, argv)
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
    size_t best_score = 0;

    auto username = gg::Menu::get_username(engine);

    std::unique_ptr<gg::SharedObject> game = nullptr;
    gg::Menu::show(engine, game);
    auto game_instance = game->get<ass::IGame>();

    for (bool running = true; running;) {
        auto status = game_instance->run(engine);
        if (status.second > best_score)
            std::clog << "New best score for '" << username
                      << "': " << best_score << std::endl;

        switch (status.first) {
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
                auto v = gg::Engine::get_shared_objects().first;
                std::sort(v.begin(), v.end());
                auto it = std::find(v.begin(), v.end(), game->get_path());
                size_t index = 0;
                if (it != v.end()) {
                    index = it - v.begin() + 1;
                    if (index >= v.size())
                        index = 0;
                }

                auto new_game = std::make_unique<gg::SharedObject>(v.at(index));
                game_instance = new_game->get<ass::IGame>();
                game = std::move(new_game);
                break;
        }
    }
    return 0;
}
