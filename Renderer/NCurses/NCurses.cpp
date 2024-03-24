/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

#include <curses.h>

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>

extern "C" ass::IRenderer *uwu_goofy_ahhh_renderer_entrypoint()
{
    return new NCurses();
}

NCurses::~NCurses() = default;

void NCurses::start()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

void NCurses::refresh() {}

void NCurses::clear(ass::TermColor color)
{
    ::clear();
}

void NCurses::stop() noexcept
{
    delwin(stdscr);
    endwin();
}

void NCurses::set_title(std::wstring title) {}
