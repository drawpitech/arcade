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

#include "Events.hpp"
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

    /**
     * @brief Draw a sprite to the window (should NOT be used outside of the Engine)
     * @param[in] sprite sprite to display
     * @param[in] raw_data sprite internal used by the renderer
     */
    virtual void draw_sprite(ISprite &sprite, void *&raw_data) = 0;

    /**
     * @brief Free the internal sprite's data (should NOT be used outside of the Engine)
     * @param[in] raw_data sprite internal by for the renderer
     */
    virtual void free_sprite(void *&raw_data) = 0;

    /**
     * @brief Get the window size
     * @return window size (width, height)
     */
    virtual Vector2<size_t> get_window_size() const = 0;

    /**
     * @brief get last events from engine
     * @return array of Event
     */
    virtual std::vector<Event> events() = 0;

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
