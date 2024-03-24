/*
** EPITECH PROJECT, 2024
** Arcade System Specifications
** File description:
** IEngine.hpp
*/

/**
 * @file
 *
 * @brief File declaring IEngine Interface
 */

#pragma once

#include <string>

#include "IRenderer.hpp"
#include "Events.hpp"
#include "ISprite.hpp"

namespace ass {
/**
 * @brief Engine Interface
 * @details Set of method to implement for the business logic of the Arcade project
 */
class IEngine { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    class Exception: public std::exception {};

    virtual ~IEngine() = default;

    virtual void refresh() = 0;

    virtual ISprite **create_sprite(SpriteAssets sprite) = 0;

    virtual void clear(TermColor color) = 0;

    virtual void set_title(std::wstring title) = 0;

    virtual std::vector<Event> events() = 0;

    virtual void set_renderer(ass::IRenderer *renderer) = 0;
    virtual ass::IRenderer *get_renderer() = 0;
};
} // namespace ass
