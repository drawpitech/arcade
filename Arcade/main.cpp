/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main
*/

#include <iostream>

#include "Arcade.hpp"

int main(int argc, char **argv)
{
    try {
        return gg::Arcade(argc, argv).run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
