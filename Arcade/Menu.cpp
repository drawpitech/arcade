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
#include <iostream>
#include <thread>

#include "Engine.hpp"
#include "SharedObject.hpp"

using Color = ass::TermColor;
using Key = ass::EventKey;

std::string gg::Menu::get_username(gg::Engine &engine)
{
    std::string username;

    while (true) {
        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case Key::KeyEnter:
                    return username;
                default:
                    if (KeysToChar.contains(event.key))
                        username += KeysToChar.at(event.key);
                    break;
            }
        }

        engine.clear(Color::White);
        engine.draw_text({5, 2}, "Arcade", 30, Color::Red);
        engine.draw_text({5, 5}, "Enter your username: ", 20, Color::Black);
        engine.draw_text({5, 6}, username, 24, Color::Blue);
        engine.draw_text({5, 8}, "Press ENTER to confirm", 20, Color::Black);
        engine.refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void gg::Menu::show(gg::Engine &engine, std::unique_ptr<gg::SharedObject> &game)
{
    auto items = gg::Engine::get_shared_objects();

    game = std::make_unique<gg::SharedObject>(
        Menu::get_selection(engine, items.first));
    engine.set_renderer(Menu::get_selection(engine, items.second));
}

std::string gg::Menu::get_selection(
    gg::Engine &engine, std::vector<std::string> &items)
{
    const auto interval = std::chrono::milliseconds(100);

    int index = 0;
    while (true) {
        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case Key::KeyQ:
                    throw std::runtime_error("Exited menu");
                case Key::KeyUp:
                    index -= 1;
                    break;
                case Key::KeyDown:
                    index += 1;
                    break;
                case Key::KeyEnter:
                    return items.at(index);
                default:
                    break;
            }
            index = std::clamp(index, 0, int(items.size()) - 1);
        }

        engine.clear(Color::White);
        for (size_t i = 0; i < items.size(); i++) {
            auto color = (i == index) ? Color::Blue : Color::Black;
            engine.draw_text({5, 5 + float(i)}, items.at(i), 24, color);
        }
        engine.refresh();
        std::this_thread::sleep_for(interval);
    }
}
