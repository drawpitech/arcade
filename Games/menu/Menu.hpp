/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/IGame.hpp>

static const std::vector<std::string> RENDERERS = {
    "ncurses", "sdl2", "ndk++",    "aalib",  "libcaca", "allegro5", "xlib",
    "gtk+",    "sfml", "irrlicht", "opengl", "vulkan",  "qt5",
};

class Menu : public ass::IGame
{
   public:
    Menu();
    ~Menu() override;

    void run(ass::IEngine &engine) final;

   private:
    std::vector<std::string> shared_objects;

    std::string get_selection(ass::IEngine &engine);
};
