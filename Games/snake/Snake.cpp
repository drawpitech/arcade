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
#include <iostream>
#include <thread>

extern "C" std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint()
{
    return std::make_unique<Snake>();
}

Snake::Snake()
{
    std::srand(std::time(nullptr));
}

Snake::~Snake() = default;

ass::RunStatus Snake::run(ass::IEngine &engine)
{
    const auto interval = std::chrono::milliseconds(100);

    Player snake{engine};
    Fruit fruit{engine};

    while (true) {
        // Move the snake
        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case ass::EventKey::KeyQ:
                    return ass::RunStatus::Exit;
                case ass::EventKey::KeyR:
                    return ass::RunStatus::Restart;
                case ass::EventKey::KeyM:
                    return ass::RunStatus::ShowMenu;
                case ass::EventKey::KeyN:
                    engine.next_renderer();
                    break;
                case ass::EventKey::KeyUp:
                    snake.set_direction(Direction::Up);
                    break;
                case ass::EventKey::KeyDown:
                    snake.set_direction(Direction::Down);
                    break;
                case ass::EventKey::KeyLeft:
                    snake.set_direction(Direction::Left);
                    break;
                case ass::EventKey::KeyRight:
                    snake.set_direction(Direction::Right);
                    break;
                default:
                    break;
            }
        }
        snake.move();

        // Check if the player is dead
        if (snake.is_dead(engine))
            return ass::RunStatus::Exit;

        // The snake touches the fruit
        auto fruit_pos = fruit.position();
        auto head = snake.get_head();
        if (head.x == fruit_pos.x && head.y == fruit_pos.y) {
            fruit.move(engine);
            snake.grow();
        }

        // Redraw screen
        engine.clear(ass::TermColor::Black);
        snake.draw(engine);
        fruit.draw(engine);
        engine.refresh();
        std::this_thread::sleep_for(interval);
    }
}
