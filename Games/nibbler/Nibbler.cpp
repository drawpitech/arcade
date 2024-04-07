/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "Nibbler.hpp"

#include <ASS/Events.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <ASS/Vector2.hpp>
#include <ctime>

extern "C" std::unique_ptr<ass::IGame> uwu_goofy_ahhh_game_entrypoint()
{
    return std::make_unique<Nibbler>();
}

Nibbler::Nibbler()
{
    std::srand(std::time(nullptr));
}

Nibbler::~Nibbler() = default;

std::pair<ass::RunStatus, size_t> Nibbler::run(ass::IEngine &engine)
{
    size_t score = 0;

    Player snake{engine};
    Fruit fruit{engine};
    Map map{engine};

    while (true) {
        // Move the snake
        for (auto &event : engine.events()) {
            if (event.state != ass::EventState::KeyPressed)
                continue;
            switch (event.key) {
                case ass::EventKey::KeyQ:
                    return {ass::RunStatus::Exit, score};
                case ass::EventKey::KeyR:
                    return {ass::RunStatus::Restart, score};
                case ass::EventKey::KeyM:
                    return {ass::RunStatus::ShowMenu, score};
                case ass::EventKey::KeyN:
                    engine.next_renderer();
                    break;
                case ass::EventKey::KeyUp:
                    snake.set_direction(Direction::Up, map);
                    break;
                case ass::EventKey::KeyDown:
                    snake.set_direction(Direction::Down, map);
                    break;
                case ass::EventKey::KeyLeft:
                    snake.set_direction(Direction::Left, map);
                    break;
                case ass::EventKey::KeyRight:
                    snake.set_direction(Direction::Right, map);
                    break;
                case ass::EventKey::KeySpace:
                    for (size_t i = 0; i < 3; i++)
                        snake.move(fruit, map);
                    break;
                default:
                    break;
            }
        }
        snake.move(fruit, map);

        // Check if the player is dead
        if (snake.is_dead(engine))
            return {ass::RunStatus::Exit, score};

        // Redraw screen
        engine.clear(ass::TermColor::Black);
        fruit.draw(engine);
        snake.draw(engine);
        map.draw(engine);
        engine.refresh();
        engine.wait_frame(7 + snake.get_size() / 4);
    }
}
