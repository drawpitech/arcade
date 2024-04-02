/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu
*/

#include "Menu.hpp"

#include <sys/stat.h>

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <thread>

extern "C" std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint()
{
    return std::make_unique<Menu>();
}

Menu::Menu()
{
    std::srand(std::time(nullptr));
}

Menu::~Menu() = default;

using Color = ass::TermColor;
using Key = ass::EventKey;

std::string Menu::get_selection(ass::IEngine &engine)
{
    const auto interval = std::chrono::milliseconds(100);

    int index = 0;
    for (bool running = true; running;) {
        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case Key::KeyQ:
                    running = false;
                    break;
                case Key::KeyUp:
                    index -= 1;
                    break;
                case Key::KeyDown:
                    index += 1;
                    break;
                case Key::KeyEnter:
                    return shared_objects.at(index);
                default:
                    break;
            }
            index = std::clamp(index, 0, int(shared_objects.size()) - 1);
        }

        engine.clear(Color::Black);
        for (size_t i = 0; i < shared_objects.size(); i++) {
            auto color = (i == index) ? Color::Blue : Color::Black;
            engine.draw_text(
                {5, 5 + float(i)}, shared_objects.at(i), 12, color);
        }
        engine.refresh();
        std::this_thread::sleep_for(interval);
    }
    return "";
}
