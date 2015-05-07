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

#include "TileGroupData.h"

TileGroupData::TileGroupData(MapData &mapData, Camera &camera) : m_tileset(),
                                                                 m_tiles(),
                                                                 m_mapData(mapData),
                                                                 m_camera(camera),
                                                                 m_tilesOpacities(),
                                                                 m_typesOpacities(),
                                                                 m_opacity(255)
{ }

sf::Texture &TileGroupData::getTileset() {
    return m_tileset;
}

Matrix3d<sf::Sprite> &TileGroupData::getTiles() {
    return m_tiles;
}

Matrix3d<unsigned int> &TileGroupData::getOpacities() {
    return m_tilesOpacities;
}

unsigned int TileGroupData::getTileNumber() const {
    return m_mapData.getTempConf().getSize();
}

void TileGroupData::configureWith(Matrix3d<unsigned int> &config) {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                frameTile(Vector3(x, y, z), Vector2(0, config.at(x, y, z)));
}

void TileGroupData::setTileAt(const Vector3 coord, const unsigned int index) {
    if(index==m_mapData.getInvisibleTile())
        resetOpacityOf(coord);
    else
        checkForOpacity(coord, index);

    frameTile(coord, Vector2(0, index));
}

sf::Sprite &TileGroupData::spriteAt(const Vector3 coord) {
    return m_tiles.at(coord.x, coord.y, coord.z);
}

sf::Sprite &TileGroupData::spriteAt(const unsigned int index) {
    return m_tiles.at(index);
}

void TileGroupData::updatePosition() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                setTilePosition(Vector3(x, y, z));
}

void TileGroupData::setTilePosition(const Vector3 coord) {
    m_tiles.at(coord.x, coord.y, coord.z).
    setPosition(toIsometricPosition(coord, m_mapData).x, toIsometricPosition(coord, m_mapData).y);
}

void TileGroupData::frameTile(const Vector3 coord, const Vector2 tilesetCoord) {
    m_tiles.at(coord.x, coord.y, coord.z).setTextureRect(sf::IntRect(tilesetCoord.x*m_mapData.getTileSize().x,
                                                         tilesetCoord.y*m_mapData.getTileSize().y,
                                                         m_mapData.getTileSize().x,
                                                         m_mapData.getTileSize().y));
}

void TileGroupData::setTileOpacity(const Vector3 coord, const unsigned int opacity) {
    m_tilesOpacities.at(coord.x, coord.y, coord.z) = opacity;

    applyOpacityOn(coord);
}

void TileGroupData::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    bool alreadyPresent(false);

    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==tile)
            alreadyPresent = true;
    }

    if(!alreadyPresent)
        m_typesOpacities.push_back(Vector2(tile, opacity));

    else
    {
        for(std::size_t i(0); i<m_typesOpacities.size(); i++)
        {
            if(m_typesOpacities[i].x==tile)
                m_typesOpacities[i].y = opacity;
        }
    }

    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                if(m_mapData.getTempConf().at(x, y, z)==tile)
                {
                    m_tilesOpacities.at(x, y, z) = opacity;
                    applyOpacityOn(Vector3(x, y, z));
                }
}

void TileGroupData::setGroupOpacity(const unsigned int opacity) {
    m_opacity = opacity;

    for(std::size_t z(0); z<m_tiles.getD(); z++)
        for(std::size_t y(0); y<m_tiles.getH(); y++)
            for(std::size_t x(0); x<m_tiles.getW(); x++)
            {
                m_tilesOpacities.at(x, y, z) = opacity;
                applyOpacityOn(Vector3(x, y, z));
            }
}

void TileGroupData::applyOpacityOn(const Vector3 coord) {
        m_tiles.at(coord.x, coord.y, coord.z).setColor(sf::Color(255,
                                                                 255,
                                                                 255,
                                                                 m_tilesOpacities.at(coord.x, coord.y, coord.z)));
}

void TileGroupData::checkForOpacity(const Vector3 coord, const unsigned int tile) {
    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==tile)
        {
            m_tilesOpacities.at(coord.x, coord.y, coord.z) = m_typesOpacities[i].y;
            applyOpacityOn(coord);
        }
    }
}

void TileGroupData::reloadOpacities() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                checkForOpacity(Vector3(x, y, z), m_mapData.getTempConf().at(x, y, z));
}

unsigned int TileGroupData::getTileOpacity(const Vector3 coord) {
    return m_tilesOpacities.at(coord.x, coord.y, coord.z);
}

unsigned int TileGroupData::getGroupOpacity() const {
    return m_opacity;
}

void TileGroupData::resetOpacityOf(const Vector3 coord) {
    setTileOpacity(coord, 255);
}

void TileGroupData::setTileTilesetX(const Vector3 coord, const Vector2 tilesetCoord) {
    if(isVisible(toIsometricPosition(coord, m_mapData), m_mapData.getTileSize(), m_camera))
        frameTile(coord, tilesetCoord);
}

unsigned int TileGroupData::getOpacityOfType(const unsigned int type) const {
    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==type)
            return m_typesOpacities[i].y;
    }
    return 255;
}
