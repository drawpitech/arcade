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

#include <memory>
#include <string>

#include "IRenderer.hpp"
#include "Events.hpp"
#include "ISprite.hpp"

namespace ass {
/**
 * @brief Engine Interface
 * @details Set of method to implement for the business logic of the Arcade project
 */
class IEngine {
public:
    class Exception: public std::exception {};

    IEngine() = default;
    virtual ~IEngine() = default;

    virtual std::unique_ptr<ass::ISprite> create_sprite() = 0;
    virtual void draw_sprite(ass::ISprite &) = 0;

    virtual void refresh() = 0;

    virtual void clear(TermColor color) = 0;

    virtual void set_title(std::wstring title) = 0;

    virtual std::vector<Event> events() = 0;

    virtual void set_renderer(ass::IRenderer *renderer) = 0;
    virtual ass::IRenderer &get_renderer() = 0;

    IEngine(const IEngine &) = default;
    IEngine(IEngine &&) = delete;
    IEngine &operator=(const IEngine &) = default;
    IEngine &operator=(IEngine &&) = delete;
};
} // namespace ass
