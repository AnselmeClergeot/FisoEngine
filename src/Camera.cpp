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

#include "Camera.hpp"
#include "TileGroup.hpp"
#include "EntitiesContainer.hpp"

fe::Camera::Camera() : m_viewDimensions(1980, 1080),
                       m_viewCenter(1980/2, 1080/2),
                       m_mapTilegroup(nullptr),
                       m_shadowsTilegroup(nullptr)
{ }

fe::Camera::Camera(const unsigned int viewW, const unsigned int viewH) : m_viewDimensions(viewW, viewH),
                                                                         m_viewCenter(viewW/2, viewH/2),
                                                                         m_mapTilegroup(nullptr),
                                                                         m_shadowsTilegroup(nullptr)
{ }

void fe::Camera::setViewDimensions(const fe::Vector2 dim) {
    m_viewDimensions = dim;

    m_viewCenter.x = m_viewDimensions.x/2;
    m_viewCenter.y = m_viewDimensions.y/2;
}

void fe::Camera::setViewDimensions(const unsigned int w, const unsigned int h) {
    setViewDimensions(fe::Vector2(w, h));
}

void fe::Camera::setViewCenter(const fe::Vector2 center) {
    m_viewCenter = center;

    if(m_mapTilegroup!=0 && m_shadowsTilegroup!=0 && m_entitiesContainer!=0)
    {
        m_mapTilegroup->updatePosition();
        m_shadowsTilegroup->updatePosition();

        for(int i(0); i<m_entitiesContainer->getEntitiesNumber(); i++)
            m_entitiesContainer->entityAt(i).setPosition(m_entitiesContainer->entityAt(i).getPosition());
    }
}

void fe::Camera::setViewCenter(const unsigned int centerX, const unsigned int centerY) {
    setViewCenter(fe::Vector2(centerX, centerY));
}

void fe::Camera::moveViewCenter(const fe::Vector2 rate) {
    m_viewCenter+=rate;
    setViewCenter(m_viewCenter);
}

void fe::Camera::moveViewCenter(const unsigned int rx, const unsigned int ry) {
    moveViewCenter(fe::Vector2(rx, ry));
}

fe::Vector2 fe::Camera::getViewDimensions() const {
    return m_viewDimensions;
}

fe::Vector2 fe::Camera::getViewCenter() const {
    return m_viewCenter;
}

void fe::Camera::setTileGroups(fe::TileGroup &map, fe::TileGroup &shadows) {
    m_mapTilegroup = std::unique_ptr<fe::TileGroup>(&map);
    m_shadowsTilegroup = std::unique_ptr<fe::TileGroup>(&shadows);
}

void fe::Camera::setEntitiesContainer(fe::EntitiesContainer &container) {
    m_entitiesContainer = std::unique_ptr<fe::EntitiesContainer>(&container);
}
