/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SharedObject
*/

#include "SharedObject.hpp"

#include <utility>

gg::SharedObject::SharedObject(std::string path)
    : _path(std::move(path)), _handle(nullptr, dlclose)
{
    _handle.reset(dlopen(_path.c_str(), RTLD_LAZY));
    if (_handle == nullptr)
        throw gg::Exception(dlerror());
}

gg::SharedObject::SharedObject(const SharedObject &other)
    : _path(other._path), _handle(nullptr, dlclose)
{
    _handle.reset(dlopen(_path.c_str(), RTLD_LAZY));
    if (_handle == nullptr)
        throw gg::Exception(dlerror());
}

gg::SharedObject &gg::SharedObject::operator=(const SharedObject &other)
{
    _path = other._path;
    _handle.reset(dlopen(_path.c_str(), RTLD_LAZY));
    if (_handle == nullptr)
        throw gg::Exception(dlerror());
    return *this;
}

gg::SharedObject::~SharedObject() = default;

const std::string GAME_ENTRYPOINT = "uwu_goofy_ahhh_game_entrypoint";
const std::string REND_ENTRYPOINT = "uwu_goofy_ahhh_renderer_entrypoint";

template <>
std::unique_ptr<ass::IGame> gg::SharedObject::get<ass::IGame>()
{
    return get_val<ass::IGame>(GAME_ENTRYPOINT);
}

template <>
std::unique_ptr<ass::IRenderer> gg::SharedObject::get<ass::IRenderer>()
{
    return get_val<ass::IRenderer>(REND_ENTRYPOINT);
}

template <>
bool gg::SharedObject::is_such<ass::IGame>()
{
    return get_symbol<ass::IGame>(GAME_ENTRYPOINT) != nullptr;
}

template <>
bool gg::SharedObject::is_such<ass::IRenderer>()
{
    return get_symbol<ass::IRenderer>(REND_ENTRYPOINT) != nullptr;
}
