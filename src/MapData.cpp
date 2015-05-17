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

#include "MapData.hpp"

fe::MapData::MapData() : m_tempConf(),
                         m_permConf(),
                         m_size(),
                         m_position(),
                         m_tileSize(),
                         m_tileBaseHeight(0),
                         m_invisibleTile(0),
                         m_translucentTiles()
{ }

void fe::MapData::setSize(const fe::Vector2 size) {
    m_size = size;
}

void fe::MapData::setPosition(const fe::Vector2 position) {
    m_position = position;
}

void fe::MapData::move(const fe::Vector2 rate) {
    m_position+=rate;
}

void fe::MapData::setTileSize(const fe::Vector2 size) {
    m_tileSize = size;
}

void fe::MapData::setTileBaseHeight(const unsigned int h) {
    m_tileBaseHeight = h;
}

void fe::MapData::setInvisibleTile(const unsigned int tile) {
    m_invisibleTile = tile;
}

void fe::MapData::addTranslucentTile(const unsigned int tile) {
    m_translucentTiles.push_back(tile);
}

void fe::MapData::removeTranslucentTile(const unsigned int tile) {
    for(std::size_t i(0); i<m_translucentTiles.size(); i++)
    {
        if(m_translucentTiles[i]==tile)
            m_translucentTiles.erase(m_translucentTiles.begin()+i);
    }
}

fe::Matrix3d<unsigned int> &fe::MapData::getTempConf() {
    return m_tempConf;
}

fe::Matrix3d<unsigned int> &fe::MapData::getPermConf() {
    return m_permConf;
}

fe::Vector2 fe::MapData::getSize() const {
    return m_size;
}

fe::Vector2 fe::MapData::getPosition() const {
    return m_position;
}

fe::Vector2 fe::MapData::getTileSize() const {
    return m_tileSize;
}

unsigned int fe::MapData::getTileBaseHeight() const {
    return m_tileBaseHeight;
}

unsigned int fe::MapData::getInvisibleTile() const {
    return m_invisibleTile;
}

bool fe::MapData::isTranslucent(const unsigned int tile) const {
    return std::find(m_translucentTiles.begin(), m_translucentTiles.end(), tile)!=m_translucentTiles.end();
}
