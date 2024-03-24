/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NCurses
*/

#pragma once

#include <ASS/IRenderer.hpp>
#include <ASS/ISprite.hpp>
#include <string>
#include "ASS/IEngine.hpp"

class NCurses : public ass::IRenderer
{
   public:
    struct Properties
    {
        std::wstring title;
    };

    ~NCurses() override;

    void start() final;

    void refresh() final;

    void clear(ass::TermColor color) final;

    void stop() noexcept final;

    void set_title(std::wstring title) final;

   private:
    ass::IEngine *_engine;
};
