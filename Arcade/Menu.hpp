/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/IGame.hpp>

#include "Engine.hpp"
#include "SharedObject.hpp"

namespace gg {

class Menu
{
   public:
    Menu() = default;
    static void show(
        gg::Engine &engine, std::unique_ptr<gg::SharedObject> &game,
        std::unique_ptr<gg::SharedObject> &renderer);

   private:
    static std::string get_selection(gg::Engine &engine, SOMap &items);
};

}  // namespace gg
