/*
** EPITECH PROJECT, 2024
** ASS
** File description:
** Events.hpp
*/

#pragma once

enum class EventKey: u_int8_t {
    A = 1,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    Up,
    Down,
    Left,
    Right,
    Enter,
    Space,
    RMB,
    LMB,
    MMB,
};

enum class EventState: int {
    All = -1,
    KeyReleased,
    KeyPressed,
};

struct Event {
    EventKey key;
    EventState state;
};
