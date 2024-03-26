/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

#include <ncurses.h>

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
    fruit->move({
        static_cast<float>(rand() % COLS),
        static_cast<float>(rand() % LINES),
    });

    bool running = true;
    while (running) {
        // TODO: Catch inputs with ncurses
        auto &head = snake.body.at(0);
        switch (getch()) {  // ncurses
            case 'q':
                running = false;
                break;
            case KEY_UP:  // ncurses
                if (snake.direction.y == 1)
                    continue;
                snake.direction.x = 0;
                snake.direction.y = -1;
                break;
            case KEY_DOWN:  // ncurses
                if (snake.direction.y == -1)
                    continue;
                snake.direction.x = 0;
                snake.direction.y = 1;
                break;
            case KEY_LEFT:  // ncurses
                if (snake.direction.x == 1)
                    continue;
                snake.direction.x = -1;
                snake.direction.y = 0;
                break;
            case KEY_RIGHT:  // ncurses
                if (snake.direction.x == -1)
                    continue;
                snake.direction.x = 1;
                snake.direction.y = 0;
                break;
            default:
                break;
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
            float x = rand() % COLS;
            float y = rand() % LINES;
            fruit->move({x, y});
        } else if (
            head.x < 0 || head.x >= COLS || head.y < 0 || head.y >= LINES) {
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
