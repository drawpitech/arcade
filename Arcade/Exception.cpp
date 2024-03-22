/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#include "Exception.hpp"

#include <utility>

gg::Exception::Exception(std::string message) : _message(std::move(message)) {}

const char *gg::Exception::what() const noexcept
{
    return _message.c_str();
}
