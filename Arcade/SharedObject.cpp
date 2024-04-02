/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SharedObject
*/

#include "SharedObject.hpp"

gg::SharedObject::SharedObject(const std::string &path)
    : _handle(dlopen(path.c_str(), RTLD_LAZY), dlclose)
{
    if (_handle == nullptr)
        throw gg::Exception(dlerror());
}

gg::SharedObject::~SharedObject() = default;

template <>
std::unique_ptr<ass::IGame> gg::SharedObject::get<ass::IGame>()
{
    return get_symbol<ass::IGame>("uwu_goofy_ahhh_game_entrypoint");
}

template <>
std::unique_ptr<ass::IRenderer> gg::SharedObject::get<ass::IRenderer>()
{
    return get_symbol<ass::IRenderer>("uwu_goofy_ahhh_renderer_entrypoint");
}

template <>
std::unique_ptr<ass::ISprite> gg::SharedObject::get<ass::ISprite>()
{
    return get_symbol<ass::ISprite>("uwu_goofy_ahhh_sprite_entrypoint");
}
