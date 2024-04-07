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

extern "C" std::unique_ptr<ass::IRenderer> uwu_goofy_ahhh_renderer_entrypoint()
{
    return std::make_unique<NCurses>();
}

NCurses::NCurses()
{
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Init colors
    start_color();
    init_pair(int(ass::TermColor::Black), COLOR_BLACK, COLOR_BLACK);
    init_pair(int(ass::TermColor::Maroon), COLOR_BLACK, COLOR_BLACK);
    init_pair(int(ass::TermColor::Green), COLOR_GREEN, COLOR_BLACK);
    init_pair(int(ass::TermColor::Olive), COLOR_GREEN, COLOR_BLACK);
    init_pair(int(ass::TermColor::Navy), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Purple), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Teal), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Silver), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Grey), COLOR_WHITE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Red), COLOR_RED, COLOR_BLACK);
    init_pair(int(ass::TermColor::Lime), COLOR_GREEN, COLOR_BLACK);
    init_pair(int(ass::TermColor::Yellow), COLOR_YELLOW, COLOR_BLACK);
    init_pair(int(ass::TermColor::Blue), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Fuchsia), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::Aqua), COLOR_BLUE, COLOR_BLACK);
    init_pair(int(ass::TermColor::White), COLOR_WHITE, COLOR_BLACK);
}

NCurses::~NCurses()
{
    endwin();
}

void NCurses::refresh()
{
    ::refresh();
}

void NCurses::clear(ass::TermColor /*color*/)
{
    ::clear();
}

void NCurses::set_title(std::wstring title) {}

void NCurses::draw_sprite(ass::ISprite &sprite, void *& /*raw_data*/)
{
    auto pos = sprite.position();
    auto assets = sprite.get_asset().sprite;

    for (size_t i = 0; i < assets.height; i++) {
        for (size_t j = 0; j < assets.width; j++) {
            attron(COLOR_PAIR(int(assets.char_colors.at(i).at(j))));
            mvaddnwstr(pos.y + i, pos.x + j, &assets.chars.at(i).at(j), 1);
            attron(COLOR_PAIR(int(ass::TermColor::White)));
        }
    }
}

ass::Vector2<size_t> NCurses::get_window_size() const
{
    return {
        static_cast<unsigned long>(COLS),
        static_cast<unsigned long>(LINES),
    };
}

std::vector<ass::Event> NCurses::events()
{
    int key = getch();
    if (KEYS.contains(key))
        return {{KEYS.at(key), ass::EventState::KeyPressed}};

    return {};
}

void NCurses::draw_text(
    ass::Vector2<float> pos, std::string text, uint /*size*/,
    ass::TermColor color)
{
    attron(COLOR_PAIR(int(color)));
    mvaddstr(pos.y, pos.x, text.c_str());
    attron(COLOR_PAIR(int(ass::TermColor::White)));
}

void NCurses::free_sprite(void *&raw_data)
{
    // no data so no free
}
