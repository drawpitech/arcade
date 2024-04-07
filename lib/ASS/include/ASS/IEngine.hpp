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

#include <memory>
#include <string>

#include "Events.hpp"
#include "IRenderer.hpp"
#include "ISprite.hpp"

namespace ass {
/**
 * @interface IEngine
 * @exception IEngine::Exception
 * @ingroup engine
 * @brief Engine Interface
 * @details Set of method to implement for the Engine Part of the Arcade
 * project. The engine handle the sprites data, and do the link between games
 * and renderers.
 *
 */
class IEngine
{
   public:
    /**
     * @brief Engine Exception
     * @details Base class for Engines’s scoped exceptions
     */
    class Exception : public std::exception
    {};

    IEngine() = default;
    virtual ~IEngine() = default;

    /**
     * @copydoc IRenderer::refresh()
     */
    virtual void refresh() = 0;

    /**
     * @brief Create a new sprite
     * @return Pointer to a new sprite
     */
    virtual std::unique_ptr<ass::ISprite> create_sprite() = 0;

    /**
     * @brief Draw a sprite
     */
    virtual void draw_sprite(ass::ISprite &) = 0;

    /**
     * @copydoc IRenderer::clear()
     */
    virtual void clear(TermColor color) = 0;

    /**
     * @brief get last events from engine
     * @return array of Event
     */
    virtual std::vector<Event> events() = 0;

    /**
     * @copydoc IRenderer::draw_text
     */
    virtual void draw_text(
        Vector2<float> pos, std::string text, uint size, TermColor color) = 0;

    /**
     * @brief sleep until the next frame
     * @param fps frame rate per seconds
     */
    virtual void wait_frame(u_int8_t fps) = 0;

    /**
     * @brief replace old renderer with a new one, do all the changes needed by the sprites
     * @param renderer new renderer
     */
    virtual void set_renderer(std::unique_ptr<ass::IRenderer> &&renderer) = 0;

    /**
     * @brief get access to the actual renderer
     * @return ref to the actual renderer
     */
    virtual ass::IRenderer &get_renderer() = 0;

    /**
     * @brief hot switch the renderer used
     * @details this method should read the `lib` folder, and set the renderer to the next one in the folder.
     */
    virtual void next_renderer() = 0;

    IEngine(const IEngine &) = default;
    IEngine(IEngine &&) = delete;
    IEngine &operator=(const IEngine &) = default;
    IEngine &operator=(IEngine &&) = delete;
};
}  // namespace ass
