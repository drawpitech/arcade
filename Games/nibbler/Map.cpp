/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Map
*/

#include <iostream>
#include "Nibbler.hpp"

Map::Map(ass::IEngine &engine) : _sprite(engine.create_sprite())
{
    // init map
    for (const auto &line : MAP) {
        std::vector<MapPart> v;

        for (char tile : line) {
            switch (tile) {
                case ' ':
                    v.push_back(MapPart::Void);
                    break;
                case 'O':
                    v.push_back(MapPart::Wall);
                    break;
                default:
                    throw std::runtime_error("Invalid tile in map");
            }
        }

        _map.push_back(v);
    }

    // init sprite
    _sprite->set_asset({
        .sprite =
            {
                .height = 1,
                .width = 1,
                .chars = {{L'\x2588'}},  // L'\x2588' L'█'
                .char_colors = {{ass::xterm_color_t(ass::TermColor::White)}},
            },
        .path = "assets/nibbler/wall.png",
    });
}

Map::~Map() = default;

Map::MapPart Map::get_tile(pos_t pos) const
{
    auto x = static_cast<size_t>(pos.x);
    auto y = static_cast<size_t>(pos.y);

    if (x < 0 || y < 0)
        throw std::runtime_error("Invalid position");
    if (y >= _map.size() || x >= _map.at(y).size())
        throw std::runtime_error("Invalid position");
    return _map.at(y).at(x);
}

void Map::draw(ass::IEngine &engine)
{
    for (size_t y = 0; y < _map.size(); y++) {
        for (size_t x = 0; x < _map.at(y).size(); x++) {
            if (_map.at(y).at(x) != Map::MapPart::Wall)
                continue;
            _sprite->move({
                .x = static_cast<float>(x),
                .y = static_cast<float>(y),
            });
            engine.draw_sprite(*_sprite);
        }
    }
}
