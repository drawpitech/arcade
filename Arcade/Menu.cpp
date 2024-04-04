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
#include <thread>

#include "Engine.hpp"
#include "SharedObject.hpp"

void gg::Menu::show(
    gg::Engine &engine, std::unique_ptr<gg::SharedObject> &game,
    std::unique_ptr<gg::SharedObject> &renderer)
{
    auto items = gg::Engine::get_shared_objects();

    game = std::make_unique<gg::SharedObject>(
        Menu::get_selection(engine, items.first));

    auto new_renderer = std::make_unique<gg::SharedObject>(
        Menu::get_selection(engine, items.second));
    engine.set_renderer(new_renderer->get<ass::IRenderer>());
    renderer = std::move(new_renderer);
}

using Color = ass::TermColor;
using Key = ass::EventKey;

std::string gg::Menu::get_selection(gg::Engine &engine, SOMap &items)
{
    const auto interval = std::chrono::milliseconds(100);

    std::vector<std::string> keys;
    keys.reserve(items.size());
    for (const auto &[k, _] : items)
        keys.push_back(k);

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
                    return keys.at(index);
                default:
                    break;
            }
            index = std::clamp(index, 0, int(keys.size()) - 1);
        }

        engine.clear(Color::White);
        for (size_t i = 0; i < keys.size(); i++) {
            auto color = (i == index) ? Color::Blue : Color::Black;
            engine.draw_text({5, 5 + float(i)}, keys.at(i), 24, color);
        }
        engine.refresh();
        std::this_thread::sleep_for(interval);
    }
}
