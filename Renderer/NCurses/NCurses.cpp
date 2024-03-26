/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#include "NCurses.hpp"

#include <curses.h>
#include <ncursesw/ncurses.h>

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>

extern "C" ass::IRenderer *uwu_goofy_ahhh_renderer_entrypoint()
{
    return new NCurses();
}

NCurses::NCurses()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

NCurses::~NCurses()
{
    delwin(stdscr);
    endwin();
}

void NCurses::refresh() {}

void NCurses::clear(ass::TermColor /*color*/)
{
    ::clear();
}

void NCurses::set_title(std::wstring title) {}

void NCurses::draw_sprite(ass::ISprite &sprite, void *& /*raw_data*/) {
    auto pos = sprite.position();
    auto assets = sprite.get_asset().sprite;

    size_t y = pos.y;
    for (size_t i = 0; i < assets.height; i++) {
        size_t x = pos.x;
        for (wchar_t ch : assets.chars.at(i))
            mvaddnwstr(y, x++, &ch, 1);
        y++;
    }
}
