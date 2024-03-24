/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#pragma once

#include <ASS/IEngine.hpp>
#include <ASS/ISprite.hpp>
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

    void refresh() final;

    ass::ISprite **create_sprite(ass::SpriteAssets sprite) final;

    void clear(ass::TermColor color) final;

    void set_title(std::wstring title) final;

    std::vector<Event> events() final;

    void set_renderer(ass::IRenderer *renderer) final;
    ass::IRenderer *get_renderer() final;

   private:
    std::unique_ptr<ass::IRenderer> _renderer;
};

}  // namespace gg
