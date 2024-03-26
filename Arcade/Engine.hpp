/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/ISprite.hpp>
#include <map>
#include <memory>

#include "Exception.hpp"

namespace gg {

class Engine : public ass::IEngine
{
   public:
    class Exception : public gg::Exception
    {};

    Engine();
    ~Engine() override;

    std::unique_ptr<ass::ISprite> create_sprite() final;
    void draw_sprite(ass::ISprite &sprite) final;

    void refresh() final;

    void clear(ass::TermColor color) final;

    void set_title(std::wstring title) final;

    std::vector<Event> events() final;

    void set_renderer(ass::IRenderer *renderer) final;
    ass::IRenderer &get_renderer() final;

   private:
    std::unique_ptr<ass::IRenderer> _renderer;
    std::map<ass::ISprite *, void *> _sprites;
};

}  // namespace gg
