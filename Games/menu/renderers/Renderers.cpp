/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "../Menu.hpp"

#include <sys/stat.h>

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>
#include <algorithm>
#include <filesystem>

void Menu::run(ass::IEngine &engine) {
    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        const auto &path = entry.path().string();
        if (!path.ends_with(".so") || !path.starts_with("./lib/arcade_"))
            continue;

        std::string name{path.substr(13, path.length() - 16)};
        if (std::find(RENDERERS.begin(), RENDERERS.end(), name) !=
            RENDERERS.end())
            shared_objects.emplace_back(name);
    }

    get_selection(engine);
}
