/*
** EPITECH PROJECT, 2024
** ASS
** File description:
** ISprite.hpp
*/

/**
 * @file
 *
 * @brief File declaring ISprite Interface
 */

/**
 * @defgroup sprite Sprite
 */

#pragma once

#include <sys/types.h>

#include <string>
#include <vector>

#include "Vector2.hpp"

namespace ass {
/**
 * @brief Type for common color
 * @ingroup sprite
 */
using xterm_color_t = u_int8_t;

/**
 * @brief Colors for standard terminal colors
 * @ingroup sprite
 */
enum class TermColor: xterm_color_t {
    Black,
    Maroon,
    Green,
    Olive,
    Navy,
    Purple,
    Teal,
    Silver,
    Grey,
    Red,
    Lime,
    Yellow,
    Blue,
    Fuchsia,
    Aqua,
    White
};

/**
 * @brief Type for color content of sprite targeting terminal renderers
 * @ingroup sprite
 */
using ascii_color_array_t = std::vector<std::vector<xterm_color_t>>;

/**
 * @brief Type for char content of sprite targeting terminal renderers
 * @ingroup sprite
 */
using ascii_char_array_t = std::vector<std::vector<wchar_t>>;

/**
 * @brief Sprite asset for cross renderer compatibility
 * @ingroup sprite
 * @details Define what to render for:
 * @li Terminal based renderers
 * @li 2D based renderers
 */
struct SpriteAssets {
    /**
     * @brief Structure representing an ASCII sprite
     */
    struct AsciiSprite {
        uint height; ///< Height of the sprite
        uint width; ///< Width of the sprite
        ascii_char_array_t chars; ///< Characters of the sprite
        ascii_color_array_t char_colors; ///< Color of the characters
        ascii_color_array_t bg_colors; ///< Color of the background of each characters
    } sprite; ///< ASCII sprite

    std::string path; ///< Path of the Image sprite
};

/**
 * @brief Sprite Interface
 * @details Set of method to implement for the Sprite part of the Arcade project
 * @ingroup sprite
 * @exception ISprite::Exception Sprite’s exceptions
 */
class ISprite {
public:
    /**
     * @brief Sprite Exception
     * @details Base class for Sprite’s scoped exceptions
     */
    class Exception: public std::exception {};

    ISprite() = default;
    virtual ~ISprite() = default;

    /**
     * @brief Set the asset of the sprite
     * @param[in] asset asset to set
     */
    virtual void set_asset(SpriteAssets asset) = 0;

    /**
     * @brief Get the asset of the sprite
     */
    virtual SpriteAssets &get_asset() = 0;

    /**
     * @brief Move the sprite to a new position
     * @param[in] pos new position
     */
    virtual void move(Vector2<float> pos) = 0;

    /**
     * @brief Get the current position of the sprite
     * @return position of the sprite
     */
    virtual Vector2<float> position() = 0;

    ISprite(const ISprite &) = default;
    ISprite(ISprite &&) = default;
    ISprite &operator=(const ISprite &) = default;
    ISprite &operator=(ISprite &&) = default;
};

} // namespace ass
