/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#pragma once

#include <exception>
#include <string>

namespace gg {

class Exception : public std::exception
{
   public:
    Exception(std::string message);
    [[nodiscard]] const char *what() const noexcept override;

   private:
    std::string _message;
};

}  // namespace gg
