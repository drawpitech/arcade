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

template <typename T>
using Entrypoint = std::unique_ptr<T> (*)();

class SharedObject
{
   public:
    SharedObject(std::string path);
    ~SharedObject();

    std::string get_path();

    SharedObject(const SharedObject &);
    SharedObject(SharedObject &&) = default;
    SharedObject &operator=(const SharedObject &);
    SharedObject &operator=(SharedObject &&) = default;

    template <typename T>
    Entrypoint<T> get_symbol(const std::string &name)
    {
        return reinterpret_cast<Entrypoint<T>>(
            dlsym(_handle.get(), name.c_str()));
    }

   private:
    std::string _path;
    std::unique_ptr<void, int (*)(void *)> _handle;

    template <typename T>
    std::unique_ptr<T> get_val(const std::string &symbol)
    {
        auto sym = get_symbol<T>(symbol);
        if (sym == nullptr)
            throw gg::Exception("No such symbol `" + symbol + "`");
        return sym();
    }

   public:
    template <typename T>
    std::unique_ptr<T> get();

    template <typename T>
    bool is_such();
};

}  // namespace gg
