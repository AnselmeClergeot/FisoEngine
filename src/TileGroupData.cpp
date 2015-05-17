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

fe::TileGroupData::TileGroupData(fe::MapData &mapData,
                                 fe::Camera &camera) : m_tileset(),
                                                       m_tiles(),
                                                       m_mapData(mapData),
                                                       m_camera(camera),
                                                       m_tilesOpacities(),
                                                       m_typesOpacities(),
                                                       m_opacity(255)
{ }

sf::Texture &fe::TileGroupData::getTileset() {
    return m_tileset;
}

fe::Matrix3d<sf::Sprite> &fe::TileGroupData::getTiles() {
    return m_tiles;
}

fe::Matrix3d<unsigned int> &fe::TileGroupData::getOpacities() {
    return m_tilesOpacities;
}

unsigned int fe::TileGroupData::getTileNumber() const {
    return m_mapData.getTempConf().getSize();
}

void fe::TileGroupData::configureWith(fe::Matrix3d<unsigned int> &config) {
    for(std::size_t x(0); x<m_tiles.getW(); x++)
        for(std::size_t y(0); y<m_tiles.getH(); y++)
            for(std::size_t z(0); z<m_tiles.getD(); z++)
                frameTile(fe::Vector3(x, y, z), fe::Vector2(0, config.at(x, y, z)));
}

void fe::TileGroupData::setTileAt(const fe::Vector3 coord, const unsigned int index) {
    if(index==m_mapData.getInvisibleTile())
        resetOpacityOf(coord);
    else
        checkForOpacity(coord, index);

    frameTile(coord, fe::Vector2(0, index));
}

sf::Sprite &fe::TileGroupData::spriteAt(const fe::Vector3 coord) {
    return m_tiles.at(coord.x, coord.y, coord.z);
}

sf::Sprite &fe::TileGroupData::spriteAt(const unsigned int index) {
    return m_tiles.at(index);
}

void fe::TileGroupData::updatePosition() {
    for(std::size_t x(0); x<m_tiles.getW(); x++)
        for(std::size_t y(0); y<m_tiles.getH(); y++)
            for(std::size_t z(0); z<m_tiles.getD(); z++)
                setTilePosition(fe::Vector3(x, y, z));
}

void fe::TileGroupData::setTilePosition(const fe::Vector3 coord) {
    m_tiles.at(coord.x, coord.y, coord.z).
    setPosition(toIsometricPosition(coord, m_mapData).x+
                    m_camera.getViewDimensions().x/2-m_camera.getViewCenter().x,
                toIsometricPosition(coord, m_mapData).y+
                    m_camera.getViewDimensions().y/2-m_camera.getViewCenter().y);
}

void fe::TileGroupData::frameTile(const fe::Vector3 coord, const fe::Vector2 tilesetCoord) {
    m_tiles.at(coord.x, coord.y, coord.z).setTextureRect(sf::IntRect(tilesetCoord.x*m_mapData.getTileSize().x,
                                                         tilesetCoord.y*m_mapData.getTileSize().y,
                                                         m_mapData.getTileSize().x,
                                                         m_mapData.getTileSize().y));
}

void fe::TileGroupData::setTileOpacity(const fe::Vector3 coord, const unsigned int opacity) {
    m_tilesOpacities.at(coord.x, coord.y, coord.z) = opacity;

    applyOpacityOn(coord);
}

void fe::TileGroupData::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    bool alreadyPresent(false);

    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==tile)
            alreadyPresent = true;
    }

    if(!alreadyPresent)
        m_typesOpacities.push_back(fe::Vector2(tile, opacity));

    else
    {
        for(std::size_t i(0); i<m_typesOpacities.size(); i++)
        {
            if(m_typesOpacities[i].x==tile)
                m_typesOpacities[i].y = opacity;
        }
    }


        for(std::size_t x(0); x<m_tilesOpacities.getW(); x++)
            for(std::size_t y(0); y<m_tilesOpacities.getH(); y++)
                for(std::size_t z(0); z<m_tilesOpacities.getD(); z++)
                if(m_mapData.getTempConf().at(x, y, z)==tile)
                {
                    m_tilesOpacities.at(x, y, z) = opacity;
                    applyOpacityOn(fe::Vector3(x, y, z));
                }
}

void fe::TileGroupData::setGroupOpacity(const unsigned int opacity) {
    m_opacity = opacity;

    for(std::size_t x(0); x<m_tilesOpacities.getW(); x++)
        for(std::size_t y(0); y<m_tilesOpacities.getH(); y++)
            for(std::size_t z(0); z<m_tilesOpacities.getD(); z++)
            {
                m_tilesOpacities.at(x, y, z) = opacity;
                applyOpacityOn(fe::Vector3(x, y, z));
            }
}

void fe::TileGroupData::applyOpacityOn(const fe::Vector3 coord) {
        m_tiles.at(coord.x, coord.y, coord.z).setColor(sf::Color(255,
                                                                 255,
                                                                 255,
                                                                 m_tilesOpacities.at(coord.x, coord.y, coord.z)));
}

void fe::TileGroupData::checkForOpacity(const fe::Vector3 coord, const unsigned int tile) {
    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==tile)
        {
            m_tilesOpacities.at(coord.x, coord.y, coord.z) = m_typesOpacities[i].y;
            applyOpacityOn(coord);
        }
    }
}

void fe::TileGroupData::reloadOpacities() {
    for(std::size_t x(0); x<m_mapData.getSize().x; x++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t z(0); z<m_mapData.getSize().y; z++)
                checkForOpacity(fe::Vector3(x, y, z), m_mapData.getTempConf().at(x, y, z));
}

unsigned int fe::TileGroupData::getTileOpacity(const fe::Vector3 coord) {
    return m_tilesOpacities.at(coord.x, coord.y, coord.z);
}

unsigned int fe::TileGroupData::getGroupOpacity() const {
    return m_opacity;
}

void fe::TileGroupData::resetOpacityOf(const fe::Vector3 coord) {
    setTileOpacity(coord, 255);
}

void fe::TileGroupData::setTileTilesetX(const fe::Vector3 coord, const fe::Vector2 tilesetCoord) {
    if(isVisible(toIsometricPosition(coord, m_mapData), m_mapData.getTileSize(), m_camera))
        frameTile(coord, tilesetCoord);
}

unsigned int fe::TileGroupData::getOpacityOfType(const unsigned int type) const {
    for(std::size_t i(0); i<m_typesOpacities.size(); i++)
    {
        if(m_typesOpacities[i].x==type)
            return m_typesOpacities[i].y;
    }
    return 255;
}
