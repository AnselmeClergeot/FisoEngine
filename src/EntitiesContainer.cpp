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

#include "EntitiesContainer.hpp"

fe::EntitiesContainer::EntitiesContainer(fe::MapData &mapData,
                                         fe::Camera &camera) : m_entities(),
                                                               m_mapData(mapData),
                                                               m_camera(camera)
{ }

fe::EntitiesContainer::~EntitiesContainer() {
    for(std::size_t i(0); i<m_entities.size(); i++)
        m_entities[i].release();
}

void fe::EntitiesContainer::createEntity() {
    m_entities.push_back(std::unique_ptr<fe::Entity>(new fe::Entity(m_mapData, m_camera)));
}

void fe::EntitiesContainer::removeEntity(const unsigned int iter) {
    m_entities.erase(m_entities.begin()+iter);
}
void fe::EntitiesContainer::removeAll() {
    m_entities.clear();
}

fe::Entity &fe::EntitiesContainer::entityAt(const unsigned int iter) {
    assert(iter<m_entities.size());
    return *m_entities[iter];
}

unsigned int fe::EntitiesContainer::getEntitiesNumber() const {
    return m_entities.size();
}
