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
    _engine->get_renderer().start();
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
        .x = rand() % COLS,   // ncurses
        .y = rand() % LINES,  // ncurses
    };

    bool running = true;
    while (running) {
        auto &head = snake.body.at(0);
        switch (getch()) {  // ncurses
            case 'q':
                running = false;
                break;
            case KEY_UP:    // ncurses
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

        if (head.x == fruit.x && head.y == fruit.y) {
            snake.body.push_back({fruit.x, fruit.y});
            fruit.x = rand() % COLS;   // ncurses
            fruit.y = rand() % LINES;  // ncurses
        } else if (
            head.x < 0 || head.x >= COLS || head.y < 0 || head.y >= LINES) {
            return;
        }

        _engine->get_renderer().clear(ass::TermColor::Black);
        for (auto &part : snake.body)
            mvprintw(part.y, part.x, "o");  // ncurses
        mvprintw(fruit.y, fruit.x, "x");    // ncurses
        _engine->get_renderer().refresh();
        std::this_thread::sleep_for(interval);
    }
}

void Snake::stop()
{
    std::clog << "Stop  snake game." << std::endl;
    _engine->get_renderer().stop();
}
