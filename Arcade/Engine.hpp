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

    std::vector<ass::Event> events() final;

    void draw_text(ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color) final;

    void wait_frame(u_int8_t fps) final;

    void set_renderer(std::unique_ptr<ass::IRenderer> &&renderer) final;
    ass::IRenderer &get_renderer() final;

    void next_renderer() final;

   private:
    std::unique_ptr<ass::IRenderer> _renderer;
    std::map<ass::ISprite *, void *> _sprites;
};

}  // namespace gg
