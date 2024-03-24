/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Snake.hpp"

#include <curses.h>

#include <ASS/IGame.hpp>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

extern "C" ass::IGame *uwu_goofy_ahhh_game_entrypoint()
{
    return new Snake();
}

void Snake::start(ass::IEngine *engine)
{
    _engine = engine;
    std::clog << "Start snake game." << std::endl;
    _engine->get_renderer()->start();
    std::srand(std::time(nullptr));
}

using pos_t = struct
{
    int x;
    int y;
};

void Snake::run()
{
    std::clog << "Run   snake game." << std::endl;
    struct
    {
        std::vector<pos_t> body;
        pos_t direction{};
    } snake;

    snake.direction = {
        .x = 1,
        .y = 0,
    };
    snake.body.push_back({0, 0});
    const auto interval = std::chrono::milliseconds(100);

    pos_t fruit{
        .x = rand() % COLS,
        .y = rand() % LINES,
    };

    while (true) {
        auto &head = snake.body.at(0);
        switch (getch()) {
            case KEY_UP:
                if (snake.direction.y == 1)
                    continue;
                snake.direction.x = 0;
                snake.direction.y = -1;
                break;
            case KEY_DOWN:
                if (snake.direction.y == -1)
                    continue;
                snake.direction.x = 0;
                snake.direction.y = 1;
                break;
            case KEY_LEFT:
                if (snake.direction.x == 1)
                    continue;
                snake.direction.x = -1;
                snake.direction.y = 0;
                break;
            case KEY_RIGHT:
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

        if (head.x == fruit.x && head.y == fruit.y) {
            snake.body.push_back({fruit.x, fruit.y});
            fruit.x = rand() % COLS;
            fruit.y = rand() % LINES;
        } else if (
            head.x < 0 || head.x >= COLS || head.y < 0 || head.y >= LINES) {
            return;
        }

        clear();
        for (auto &part : snake.body)
            mvprintw(part.y, part.x, "o");
        mvprintw(fruit.y, fruit.x, "x");
        refresh();
        std::this_thread::sleep_for(interval);
    }
}

void Snake::stop()
{
    std::clog << "Stop  snake game." << std::endl;
    _engine->get_renderer()->stop();
}
