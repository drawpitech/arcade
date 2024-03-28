/*
** EPITECH PROJECT, 2024
** ASS
** File description:
** Events.hpp
*/

/**
 * @file
 * @brief Header file for Events
 */

#pragma once
#include <sys/types.h>

namespace ass {
/**
 * @brief Event Key enumeration
 */
enum class EventKey: u_int8_t {
    KeyA,
    KeyB,
    KeyC,
    KeyD,
    KeyE,
    KeyF,
    KeyG,
    KeyH,
    KeyI,
    KeyJ,
    KeyK,
    KeyL,
    KeyM,
    KeyN,
    KeyO,
    KeyP,
    KeyQ,
    KeyR,
    KeyS,
    KeyT,
    KeyU,
    KeyV,
    KeyW,
    KeyX,
    KeyY,
    KeyZ,
    KeyUp,
    KeyDown,
    KeyLeft,
    KeyRight,
    KeyEnter,
    KeySpace,
    MouseRight,
    MouseMiddle,
    MouseLeft,
};

/**
 * @brief Event Key enumeration
 */
enum class EventState: int8_t  {
    KeyReleased, ///< State for Key release
    KeyPressed, ///< State for Key press
};

/**
 * @brief Event Container
 */
struct Event {
    /// Key of the Event
    EventKey key;

    ///State of the Event
    EventState state;
};
}
