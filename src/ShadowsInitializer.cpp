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

#include "ShadowsInitializer.h"

fe::ShadowsInitializer::ShadowsInitializer(fe::TileGroup &tilegroup,
                                           fe::ShadowsSystemStates &states,
                                           fe::MapData &mapData,
                                           fe::DynamicShader &shader) : m_tileGroup(tilegroup),
                                                                        m_mapData(mapData),
                                                                        m_states(states),
                                                                        m_shader(shader)
{ }

void fe::ShadowsInitializer::initialize() {
    fe::Matrix3d<unsigned int> tempConf;

    resizeMatrix(tempConf);
    fillMatrix(tempConf);
    m_tileGroup.initialize();
    m_tileGroup.configureWith(tempConf);
    m_shader.updateOpacityOfAll();

    m_states.setInitialized();
}

void fe::ShadowsInitializer::resizeMatrix(fe::Matrix3d<unsigned int> &tempConf) {
    tempConf.resize(m_mapData.getSize().x, m_mapData.getSize().x, m_mapData.getSize().y,
                    m_mapData.getInvisibleTile());
}

void fe::ShadowsInitializer::fillMatrix(fe::Matrix3d<unsigned int> &tempConf) {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                calculateShadowInConf(fe::Vector3(x, y, z), tempConf);
}

void fe::ShadowsInitializer::calculateShadowInConf(const fe::Vector3 coord, fe::Matrix3d<unsigned int> &tempConf) {
    if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, coord.z)))
    for(int z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
        {
            tempConf.at(coord.x, coord.y, z) = m_mapData.getTempConf().at(coord.x, coord.y, coord.z);
            break;
        }
        else
            tempConf.at(coord.x, coord.y, z) = m_mapData.getInvisibleTile();
    }

    for(int z(coord.z+1); z<m_mapData.getSize().y; z++)
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
            calculateShadowInConf(fe::Vector3(coord.x, coord.y, z), tempConf);
}
