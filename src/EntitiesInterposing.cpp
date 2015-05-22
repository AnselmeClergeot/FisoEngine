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

#include "EntitiesInterposing.hpp"



fe::EntitiesInterposing::EntitiesInterposing(fe::EntitiesContainer &container,
                                             fe::MapData &mapData) : m_container(container),
                                                                     m_mapData(mapData)
{ }

void fe::EntitiesInterposing::interpose(fe::Vector3 coord, sf::RenderTarget& target) const {
    for(std::size_t i(0); i<m_container.getEntitiesNumber(); i++)
    {
        if(m_container.entityAt(i).getDrawStatus()==fe::DrawStatus::Draw &&
           (m_container.entityAt(i).getTilePosition()==coord ||
           m_container.entityAt(i).getTilePosition().z==m_mapData.getSize().y))
                m_container.entityAt(i).draw(target);

    }
}
