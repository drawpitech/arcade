/*
** EPITECH PROJECT, 2024
** Arcade System Specifications
** File description:
** IEngine.hpp
*/

/**
 * @file
 *
 * @brief Header file declaring IEngine Interface
 */

/**
 * @defgroup engine Engine
 */

#pragma once

#include <string>

#include "Events.hpp"
#include "ISprite.hpp"

namespace ass {
/**
 * @interface IEngine
 * @exception IEngine::Exception
 * @ingroup engine
 * @brief Engine Interface
 * @details Set of method to implement for the Engine Part of the Arcade project
 *
 */
class IEngine { // NOLINT(cppcoreguidelines-special-member-functions)
public:
    /**
     * @brief Engine Exception
     * @details Base class for Engines’s scoped exceptions
     */
    class Exception: public std::exception {};

    virtual ~IEngine() = default;

    /**
     * @copydoc IRenderer::refresh()
     */
    virtual void refresh() = 0;

    /**
     * @brief Create a new sprite
     * @return Pointer to a
     */
    virtual ISprite *create_sprite() = 0;

    /**
     * @copydoc IRenderer::clear()
     */
    virtual void clear(TermColor color) = 0;

    /**
     * @brief get last events from engine
     * @return array of Event
     */
    virtual std::vector<Event> events() = 0;
};
} // namespace ass
