/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** SharedObject
*/

#pragma once

#include <dlfcn.h>

#include <ASS/IEngine.hpp>
#include <ASS/IGame.hpp>
#include <ASS/ISprite.hpp>
#include <memory>

#include "Exception.hpp"

namespace gg {

class SharedObject
{
   public:
    SharedObject(const std::string &path);
    ~SharedObject();

   private:
    std::unique_ptr<void, int (*)(void *)> _handle;

    template <typename T>
    T *get_symbol(const std::string &name)
    {
        auto *symbol =
            reinterpret_cast<T *(*)()>(dlsym(_handle.get(), name.c_str()));
        if (symbol == nullptr)
            throw gg::Exception(dlerror());
        return symbol();
    }

   public:
    template <typename T>
    T *get();
};

}  // namespace gg
