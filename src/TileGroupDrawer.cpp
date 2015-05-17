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

#include "TileGroupDrawer.hpp"
#include "DrawingFuncs.hpp"



fe::TileGroupDrawer::TileGroupDrawer(fe::MapData &mapData,
                                     fe::TileGroupData &data,
                                     fe::Camera &camera) : m_mapData(mapData),
                                                           m_data(data),
                                                           m_camera(camera)
{ }

void fe::TileGroupDrawer::draw(sf::RenderTarget& target, const unsigned int layer,
                               const fe::EntitiesInterposing *interposing) const {
    for(std::size_t x(0); x<m_data.getTiles().getW(); x++)
        for(std::size_t y(0); y<m_data.getTiles().getH(); y++)
    {
        if(isVisible(toIsometricPosition(fe::Vector3(x, y, layer), m_mapData),m_mapData.getTileSize(), m_camera) &&
           m_mapData.getTempConf().at(x, y, layer)!=m_mapData.getInvisibleTile() &&
           m_data.getTileOpacity(fe::Vector3(x, y, layer))>0)
        {
            target.draw(m_data.spriteAt(fe::Vector3(x, y, layer)));
        }

        if(interposing!=0)
            interposing->interpose(fe::Vector3(x, y, layer), target);
    }
}
