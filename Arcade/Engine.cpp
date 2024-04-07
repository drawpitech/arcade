/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Engine
*/

#include "Engine.hpp"

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <memory>
#include <thread>
#include <utility>

#include "SharedObject.hpp"
#include "Sprite.hpp"

gg::Engine::Engine() = default;

gg::Engine::~Engine()
{
    _renderer.reset(nullptr);
}

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
    if (!text.empty())
        _renderer->draw_text(pos, text, size, color);
}

void gg::Engine::wait_frame(u_int8_t fps)
{
    std::time_t last_frame = _last_frame;
    std::time_t now = std::time(nullptr);
    _last_frame = now;

    if (fps == 0)
        return;

    double target = 1 / double(fps);
    long diff = now - _last_frame;
    long to_wait = long(target * 1000) - diff;

    if (to_wait <= 0)
        return;
    std::this_thread::sleep_for(std::chrono::milliseconds(to_wait));
}

void gg::Engine::clear_sprites()
{
    if (_renderer != nullptr)
        for (auto &[_, data] : _sprites)
            _renderer->free_sprite(data);
    _sprites.clear();
}

void gg::Engine::set_renderer(std::string path)
{
    clear_sprites();

    auto new_renderer = std::make_unique<gg::SharedObject>(std::move(path));
    _renderer = std::move(new_renderer->get<ass::IRenderer>());
    _renderer_so = std::move(new_renderer);
}

ass::IRenderer &gg::Engine::get_renderer()
{
    if (_renderer == nullptr)
        throw gg::Exception("ono no renderer loaded");
    return *_renderer;
}

void gg::Engine::next_renderer()
{
    std::vector<std::string> rends = gg::Engine::get_shared_objects().second;

    if (rends.empty())
        throw gg::Exception("No renderers found");

    if (_renderer_so == nullptr) {
        set_renderer(rends.at(0));
        return;
    }

    std::sort(rends.begin(), rends.end());
    auto it = std::find(rends.begin(), rends.end(), _renderer_so->get_path());
    if (it == rends.end()) {
        set_renderer(rends.at(0));
        return;
    }

    size_t index = it - rends.begin() + 1;
    if (index >= rends.size())
        index = 0;
    set_renderer(rends.at(index));
}

std::pair<std::vector<std::string>, std::vector<std::string>>
gg::Engine::get_shared_objects()
{
    std::pair<std::vector<std::string>, std::vector<std::string>> items;

    for (const auto &entry : std::filesystem::directory_iterator("./lib")) {
        auto path = entry.path().string();
        try {
            gg::Engine::open_shared_object(path, items);
        } catch (const std::exception &e) {
            continue;
        }
    }

    if (items.first.empty() || items.second.empty())
        throw std::runtime_error("No game or renderers found :/");
    return items;
}

void gg::Engine::open_shared_object(
    const std::string &path,
    std::pair<std::vector<std::string>, std::vector<std::string>> &items)
{
    gg::SharedObject so(path);

    if (so.is_such<ass::IGame>()) {
        items.first.push_back(path);
        return;
    }
    if (so.is_such<ass::IRenderer>()) {
        items.second.push_back(path);
        return;
    }
}
