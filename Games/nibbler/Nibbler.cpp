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

ass::RunStatus Nibbler::run(ass::IEngine &engine)
{
    Player snake{engine};
    Fruit fruit{engine};

    while (true) {
        // Avoid that the fruit can disapear
        const auto &fruit_pos = fruit.position();
        const auto &[w, h] = engine.get_renderer().get_window_size();
        if (fruit_pos.x >= w || fruit_pos.y >= h)
            fruit.move(engine);

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
                case ass::EventKey::KeySpace:
                    for (size_t i = 0; i < 3; i++)
                        snake.move(engine, fruit);
                    break;
                default:
                    break;
            }
        }
        snake.move(engine, fruit);

        // Check if the player is dead
        if (snake.is_dead(engine))
            return ass::RunStatus::Exit;

        // Redraw screen
        engine.clear(ass::TermColor::Black);
        snake.draw(engine);
        fruit.draw(engine);
        engine.refresh();
        engine.wait_frame(10 + snake.get_size() / 4);
    }
}
