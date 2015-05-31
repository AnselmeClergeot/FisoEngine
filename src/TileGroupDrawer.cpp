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
#include "TileGroupColors.hpp"

fe::TileGroupDrawer::TileGroupDrawer(fe::MapData &mapData,
                                     fe::TileGroupData &data,
                                     fe::Camera *&camera,
                                     fe::TileGroupColors &colors) : m_mapData(mapData),
                                                                    m_data(data),
                                                                    m_camera(camera),
                                                                    m_colors(colors)
{ }

void fe::TileGroupDrawer::drawTile(const fe::Vector3 coord, sf::RenderTarget& target,
                                   const fe::EntitiesInterposing *interposing) const {
        if(isVisible(toIsometricPosition(coord, m_mapData),m_mapData.getTileSize(), *m_camera) &&
           m_mapData.getTempConf().at(coord.x, coord.y, coord.z)!=m_mapData.getInvisibleTile() &&
           m_colors.getTileColor(coord).a>0)
        {
            target.draw(m_data.spriteAt(coord));
        }

        if(interposing!=0)
            interposing->interpose(coord, target);
}
