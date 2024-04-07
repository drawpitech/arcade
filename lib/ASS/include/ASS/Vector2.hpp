/*
** EPITECH PROJECT, 2024
** ASS
** File description:
** Vector2.hpp
*/

/**
 * @file
 *
 * @brief Vector Struct
 */

#pragma once

namespace ass {
/**
 * @brief Vector for 2 Dimensional reference
 * @tparam T Type of the vector
 */
template<typename T>
struct Vector2 {
    T x; ///< x value
    T y; ///< y value
};
} // namespace ass
