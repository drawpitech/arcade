/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#include "Engine.hpp"

#include <filesystem>
#include <iostream>
#include <memory>

#include "Sprite.hpp"

gg::Engine::Engine() = default;
gg::Engine::~Engine() = default;

std::unique_ptr<ass::ISprite> gg::Engine::create_sprite()
{
    return std::make_unique<gg::Sprite>();
}

void gg::Engine::draw_sprite(ass::ISprite &sprite)
{
    if (!_sprites.contains(&sprite))
        _sprites.insert({&sprite, nullptr});
    _renderer->draw_sprite(sprite, _sprites.at(&sprite));
}

void gg::Engine::refresh()
{
    _renderer->refresh();
}

void gg::Engine::clear(ass::TermColor color)
{
    _renderer->clear(color);
}

std::vector<ass::Event> gg::Engine::events()
{
    return _renderer->events();
}

void gg::Engine::draw_text(
    ass::Vector2<float> pos, std::string text, uint size, ass::TermColor color)
{
    _renderer->draw_text(pos, text, size, color);
}

void gg::Engine::wait_frame(u_int8_t fps)
{
    // TODO
}

void gg::Engine::set_renderer(std::unique_ptr<ass::IRenderer> &&renderer)
{
    if (_renderer != nullptr)
        for (auto &[_, data] : _sprites)
            _renderer->free_sprite(data);
    _sprites.clear();
    _renderer = std::move(renderer);
}

ass::IRenderer &gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return *_renderer;
}

void gg::Engine::next_renderer()
{
    // TODO
}

std::pair<gg::SOMap, gg::SOMap> gg::Engine::get_shared_objects()
{
    std::pair<gg::SOMap, gg::SOMap> items;

    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        auto path = entry.path().string();
        try {
            gg::Engine::open_shared_object(path, items);
        } catch (const std::exception &e) {
            std::cerr << "While loading `" << path << "`: " << e.what()
                      << std::endl;
            continue;
        }
    }

    if (items.first.empty() || items.second.empty())
        throw std::runtime_error("No game or renderers found :/");
    return items;
}

void gg::Engine::open_shared_object(
    const std::string &path, std::pair<SOMap, SOMap> &items)
{
    gg::SharedObject so(path);

    if (so.is_such<ass::IGame>()) {
        items.first.insert({path, std::move(so)});
        return;
    }
    if (so.is_such<ass::IRenderer>()) {
        items.second.insert({path, std::move(so)});
        return;
    }
}
