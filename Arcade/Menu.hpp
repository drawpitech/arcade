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

static const std::map<ass::EventKey, char> KeysToChar{
    {ass::EventKey::KeyA, 'a'},
    {ass::EventKey::KeyB, 'b'},
    {ass::EventKey::KeyC, 'c'},
    {ass::EventKey::KeyD, 'd'},
    {ass::EventKey::KeyE, 'e'},
    {ass::EventKey::KeyF, 'f'},
    {ass::EventKey::KeyG, 'g'},
    {ass::EventKey::KeyH, 'h'},
    {ass::EventKey::KeyI, 'i'},
    {ass::EventKey::KeyJ, 'j'},
    {ass::EventKey::KeyK, 'k'},
    {ass::EventKey::KeyL, 'l'},
    {ass::EventKey::KeyM, 'm'},
    {ass::EventKey::KeyN, 'n'},
    {ass::EventKey::KeyO, 'o'},
    {ass::EventKey::KeyP, 'p'},
    {ass::EventKey::KeyQ, 'q'},
    {ass::EventKey::KeyR, 'r'},
    {ass::EventKey::KeyS, 's'},
    {ass::EventKey::KeyT, 't'},
    {ass::EventKey::KeyU, 'u'},
    {ass::EventKey::KeyV, 'v'},
    {ass::EventKey::KeyW, 'w'},
    {ass::EventKey::KeyX, 'x'},
    {ass::EventKey::KeyY, 'y'},
    {ass::EventKey::KeyZ, 'z'},
};

class Menu
{
   public:
    Menu() = default;
    static std::string get_username(gg::Engine &engine);
    static void show(
        gg::Engine &engine, std::unique_ptr<gg::SharedObject> &game);

   private:
    static std::string get_selection(
        gg::Engine &engine, std::vector<std::string> &items);
};

}  // namespace gg
