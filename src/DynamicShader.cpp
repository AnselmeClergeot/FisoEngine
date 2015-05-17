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

#include "DynamicShader.hpp"

fe::DynamicShader::DynamicShader(fe::MapData &mapData,
                                 fe::TileGroup &mapTg,
                                 fe::TileGroup &shadowsTg) : m_mapData(mapData),
                                                             m_mapTg(mapTg),
                                                             m_shadowsTg(shadowsTg)
{ }

void fe::DynamicShader::updateShading(const fe::Vector3 coord) {
    for(int z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)) &&
           !m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, coord.z)))
        {
            m_shadowsTg.setTileAt(fe::Vector3(coord.x, coord.y, z),
                                  m_mapData.getTempConf().at(coord.x, coord.y, coord.z));

            updateOpacityOfSpecific(coord);

            break;
        }

        else
            m_shadowsTg.setTileAt(fe::Vector3(coord.x, coord.y, z), m_mapData.getInvisibleTile());
    }

    for(int z(coord.z+1); z<m_mapData.getSize().y; z++)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
            updateShading(fe::Vector3(coord.x, coord.y, z));
    }
}

void fe::DynamicShader::updateShadingOfAll() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                updateShading(fe::Vector3(x, y, z));
}

void fe::DynamicShader::updateOpacityOfAll() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                updateOpacityOfSpecific(fe::Vector3(x, y, z));
}

void fe::DynamicShader::updateOpacityOfType(const unsigned int type) {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                if(m_mapData.getTempConf().at(x, y, z)==type)
                {
                    updateOpacityOfSpecific(fe::Vector3(x, y, z));
                }
}

void fe::DynamicShader::updateOpacityOfSpecific(const fe::Vector3 coord) {
    if(haveShadowVisible(coord))
        m_shadowsTg.setTileOpacity(fe::Vector3(coord.x, coord.y, getShadowZ(coord)),
                            (int)((float)m_mapTg.getTileOpacity(coord)/(float)255*m_shadowsTg.getGroupOpacity()));
}

unsigned int fe::DynamicShader::getShadowZ(const fe::Vector3 tileCoord) {
    assert(haveShadowVisible(tileCoord));

    for(int z(tileCoord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, z)))
            return z;
    }
}

bool fe::DynamicShader::haveShadowVisible(const fe::Vector3 tileCoord) {
    if(tileCoord.z==0 ||
       m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, tileCoord.z)))
        return false;

    for(int z(tileCoord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, z)))
            return true;
    }
    return false;
}

void fe::DynamicShader::updateTileFromAnim(const fe::Vector3 tileCoord, const unsigned int animX) {
    if(haveShadowVisible(tileCoord))
        m_shadowsTg.setTileTilesetX(fe::Vector3(tileCoord.x, tileCoord.y, getShadowZ(tileCoord)),
                                    fe::Vector2(animX,
                                            m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, tileCoord.z)));
}
