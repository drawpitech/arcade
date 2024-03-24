/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Entrypoint
*/

#pragma once

#include <dlfcn.h>

#include <ASS/IEngine.hpp>
#include <ASS/ISprite.hpp>

#include "Exception.hpp"

namespace gg {

template <class T>
class Entrypoint
{
   public:
    Entrypoint(std::string path, std::string symbol)
    {
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (_handle == nullptr)
            throw gg::Exception(dlerror());

        _symbol = reinterpret_cast<T *(*)()>(dlsym(_handle, symbol.c_str()));
        if (_symbol == nullptr)
            throw gg::Exception(dlerror());
    }

    ~Entrypoint()
    {
        dlclose(_handle);
    }

    T *get()
    {
        return _symbol();
    }

   private:
    void *_handle;
    T *(*_symbol)();
};

}  // namespace gg
