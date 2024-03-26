/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <string>

class NCurses : public ass::IRenderer
{
   public:
    struct Properties
    {
        std::wstring title;
    };

    NCurses();
    ~NCurses() override;

    void refresh() final;

    void clear(ass::TermColor color) final;

    void set_title(std::wstring title) final;

    void draw_sprite(ass::ISprite &sprite) final;
};
