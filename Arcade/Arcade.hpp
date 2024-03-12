/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

/*
 * @file
 *
 */

#pragma once

namespace gg {

/**
 * Main class of the arcade
 */
class Arcade
{
   public:
    /**
     * Take the arguments directly from the main function
     * @param argc The number of arguments
     * @param argv The arguments
     */
    Arcade(int argc, char **argv);

    /**
     * Run the arcade
     */
    int run();

   private:
};
}  // namespace gg
