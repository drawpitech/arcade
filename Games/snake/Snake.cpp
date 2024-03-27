/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>
#include <chrono>
#include <thread>
#include <vector>

extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint()
{
    return new Snake();
}

Snake::Snake()
{
    std::srand(std::time(nullptr));
}

Snake::~Snake() = default;

using pos_t = ass::Vector2<float>;

void Snake::run(ass::IEngine &engine)
{
    const auto interval = std::chrono::milliseconds(100);

    auto createSprite = [&engine](char c) {
        auto sprite = engine.create_sprite();
        sprite->set_asset({
            .sprite =
                {
                    .height = 1,
                    .width = 1,
                    .chars = {{c}},
                },
            .path = "",
        });
        return sprite;
    };

    struct
    {
        std::vector<pos_t> body;
        pos_t direction{
            .x = 1,
            .y = 0,
        };
    } snake{};
    snake.body.push_back({0, 0});

    auto snake_sprite = createSprite('o');

    auto fruit = createSprite('x');
    auto [width, height] = engine.get_renderer().get_window_size();
    fruit->move({
        static_cast<float>(rand() % width),
        static_cast<float>(rand() % height),
    });

    bool running = true;
    while (running) {
        auto [width, height] = engine.get_renderer().get_window_size();
        auto &head = snake.body.at(0);

        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case ass::EventKey::KeyQ:
                    running = false;
                    break;
                case ass::EventKey::KeyUp:
                    if (snake.direction.y == 1)
                        continue;
                    snake.direction.x = 0;
                    snake.direction.y = -1;
                    break;
                case ass::EventKey::KeyDown:
                    if (snake.direction.y == -1)
                        continue;
                    snake.direction.x = 0;
                    snake.direction.y = 1;
                    break;
                case ass::EventKey::KeyLeft:
                    if (snake.direction.x == 1)
                        continue;
                    snake.direction.x = -1;
                    snake.direction.y = 0;
                    break;
                case ass::EventKey::KeyRight:
                    if (snake.direction.x == -1)
                        continue;
                    snake.direction.x = 1;
                    snake.direction.y = 0;
                    break;
                default:
                    break;
            }
        }

        for (size_t i = snake.body.size() - 1; i > 0; i--)
            snake.body.at(i) = snake.body.at(i - 1);
        head.x += snake.direction.x;
        head.y += snake.direction.y;

        for (size_t i = 1; i < snake.body.size(); i++)
            if (head.x == snake.body.at(i).x && head.y == snake.body.at(i).y)
                return;

        auto fruit_pos = fruit->position();
        if (head.x == fruit_pos.x && head.y == fruit_pos.y) {
            snake.body.push_back({fruit_pos.x, fruit_pos.y});
            float x = rand() % width;
            float y = rand() % height;
            fruit->move({x, y});
        } else if (
            head.x < 0 || head.x >= width || head.y < 0 || head.y >= height) {
            return;
        }

        engine.clear(ass::TermColor::Black);
        for (auto &part : snake.body) {
            snake_sprite->move({part.x, part.y});
            engine.draw_sprite(*snake_sprite);
        }
        engine.draw_sprite(*fruit);
        engine.refresh();
        std::this_thread::sleep_for(interval);
    }
}
