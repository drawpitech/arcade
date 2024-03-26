/*
** EPITECH PROJECT, 2024
** Arcade System Specifications
** File description:
** IRenderer.hpp
*/

/**
 * @file
 *
 * @brief File declaring IRenderer Interface
 */

#pragma once

#include <string>

#include "ISprite.hpp"

/**
 * @brief Arcade Standard Specifications
 * @details Set of interfaces to ensure perfect compatibility
 * accross Epitech’s arcade project
 */
namespace ass {

/**
 * @brief Renderer Interface
 * @details Set of method to implement for the Renderer part of the Arcade project
 */
class IRenderer {
public:
    /**
     * @brief Renderer Exception
     * @details Base class for Renderer’s scoped exceptions
     */
    class Exception: public std::exception {};

    IRenderer() = default;
    virtual ~IRenderer() = default;

    /**
     * @brief Flushes current renderer state to user
     */
    virtual void refresh() = 0;

    /**
     * @brief Fill entire window with color
     * @param[in] color filling color
     */
    virtual void clear(TermColor color) = 0;

    /**
     * @brief Set current window title
     * @param[in] title title of the window
     */
    virtual void set_title(std::wstring title) = 0;

    virtual void draw_sprite(ISprite &sprite, void *&raw_data) = 0;

    IRenderer(const IRenderer &) = default;
    IRenderer(IRenderer &&) = delete;
    IRenderer &operator=(const IRenderer &) = default;
    IRenderer &operator=(IRenderer &&) = delete;
};

} // namespace ass

/**
 * @brief Arcade Renderer shared library entrypoint
 * @relates ass::IRenderer
 * @ingroup renderer
 * @attention Must be defined and return a pointer to a final class derived from IRenderer
 * @return pointer to a newly allocated IRenderer derived class
 */
extern "C" ass::IRenderer *uwu_goofy_ahhh_renderer_entrypoint(void);
