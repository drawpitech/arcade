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
#include <optional>
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
    struct Properties {
        std::wstring title;
    };

    class Exception: public std::exception {};

    virtual ~IRenderer() = default;

    virtual void start() = 0;

    virtual void refresh() = 0;

    virtual void clear(TermColor color) = 0;

    virtual void stop() noexcept = 0;

    virtual void set_title(std::wstring title) = 0;
};

} // ASS

extern "C" ass::IRenderer *uwu_goofy_ahhh_renderer_entrypoint();
