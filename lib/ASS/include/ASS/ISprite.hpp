/*
** EPITECH PROJECT, 2024
** ASS
** File description:
** ISprite.hpp
*/

#pragma once

#include <sys/types.h>
#include <vector>

#include "Vector2.hpp"

namespace ass {

using xterm_color_t = u_int8_t;

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

using image_sprite_t = std::vector<std::byte>;
using ascii_color_array_t = std::vector<std::vector<xterm_color_t>>;
using ascii_char_array_t = std::vector<std::vector<wchar_t>>;

struct SpriteAssets {
    struct AsciiSprite {
        uint height, width;
        ascii_char_array_t chars;
        ascii_color_array_t char_colors;
        ascii_color_array_t bg_colors;
    } sprite;

    image_sprite_t image;
};

class ISprite {
public:
    ISprite() = default;
    virtual ~ISprite() = default;

    virtual void set_asset(SpriteAssets asset);

    virtual void move(Vector2<float> pos) = 0;
    virtual Vector2<float> position() = 0;

    virtual void draw() = 0;

    ISprite(const ISprite &) = default;
    ISprite(ISprite &&) = default;
    ISprite &operator=(const ISprite &) = default;
    ISprite &operator=(ISprite &&) = default;
};
} // namespace ass
