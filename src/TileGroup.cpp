/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "TileGroup.hpp"



fe::TileGroup::TileGroup(fe::MapData &mapData,
                         fe::Camera &camera) : m_data(mapData, camera),
                                               m_loader(m_data, mapData, m_colors),
                                               m_drawer(mapData, m_data, camera, m_colors),
                                               m_colors(mapData, m_data)
{ }

void fe::TileGroup::setTilesetPath(const std::string path) {
    m_loader.setTilesetPath(path);
}

void fe::TileGroup::initialize() {
    m_loader.initialize();
}

void fe::TileGroup::configureWith(fe::Matrix3d<unsigned int> &matrix) {
    m_data.configureWith(matrix);
}

void fe::TileGroup::setTileAt(const fe::Vector3 coord, const unsigned int index) {
    m_data.setTileAt(coord, index);
    m_colors.checkForColor(coord, index);
}

void fe::TileGroup::updatePosition() {
    m_data.updatePosition();
}

void fe::TileGroup::setTileColor(const fe::Vector3 coord, const fe::Color color) {
    m_colors.setTileColor(coord, color);
}

void fe::TileGroup::setTileOpacity(const fe::Vector3 coord, const unsigned int opacity) {
    m_colors.setTileOpacity(coord, opacity);
}

void fe::TileGroup::setTypeColor(const unsigned int tile, const fe::Color color) {
    m_colors.setTypeColor(tile, color);
}

void fe::TileGroup::setGroupColor(fe::Color color) {
    m_colors.setGroupColor(color);
}

fe::Color fe::TileGroup::getGroupColor() const {
    return m_colors.getGroupColor();
}

void fe::TileGroup::reloadColors() {
    m_colors.reloadColors();
}

void fe::TileGroup::drawTile(const fe::Vector3 coord, sf::RenderTarget& target,
                                   const fe::EntitiesInterposing *interposing) const {
    m_drawer.drawTile(coord, target, interposing);
}

fe::Color fe::TileGroup::getTileColor(const fe::Vector3 coord) {
    return m_colors.getTileColor(coord);
}

void fe::TileGroup::setTileTilesetX(const fe::Vector3 coord, const fe::Vector2 tilesetCoord) {
    m_data.setTileTilesetX(coord, tilesetCoord);
}

fe::Color fe::TileGroup::getColorOfType(const unsigned int type) const {
    return m_colors.getColorOfType(type);
}
