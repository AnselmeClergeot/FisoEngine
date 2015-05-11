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

#include "Camera.h"
#include "TileGroup.h"
#include "EntitiesContainer.h"

Camera::Camera() : m_viewDimensions(1980, 1080),
                   m_viewCenter(1980/2, 1080/2),
                   m_mapTilegroup(nullptr),
                   m_shadowsTilegroup(nullptr)
{ }

Camera::Camera(const unsigned int viewW, const unsigned int viewH) : m_viewDimensions(viewW, viewH),
                                                                     m_viewCenter(viewW/2, viewH/2),
                                                                     m_mapTilegroup(nullptr),
                                                                     m_shadowsTilegroup(nullptr)
{ }

void Camera::setViewDimensions(const Vector2 dim) {
    m_viewDimensions = dim;

    m_viewCenter.x = m_viewDimensions.x/2;
    m_viewCenter.y = m_viewDimensions.y/2;
}

void Camera::setViewDimensions(const unsigned int w, const unsigned int h) {
    setViewDimensions(Vector2(w, h));
}

void Camera::setViewCenter(const Vector2 center) {
    m_viewCenter = center;

    if(m_mapTilegroup!=0 && m_shadowsTilegroup!=0 && m_entitiesContainer!=0)
    {
        m_mapTilegroup->updatePosition();
        m_shadowsTilegroup->updatePosition();

        for(int i(0); i<m_entitiesContainer->getEntitiesNumber(); i++)
            m_entitiesContainer->entityAt(i).setPosition(m_entitiesContainer->entityAt(i).getPosition());
    }
}

void Camera::setViewCenter(const unsigned int centerX, const unsigned int centerY) {
    setViewCenter(Vector2(centerX, centerY));
}

void Camera::moveViewCenter(const Vector2 rate) {
    m_viewCenter+=rate;
    setViewCenter(m_viewCenter);
}

void Camera::moveViewCenter(const unsigned int rx, const unsigned int ry) {
    moveViewCenter(Vector2(rx, ry));
}

Vector2 Camera::getViewDimensions() const {
    return m_viewDimensions;
}

Vector2 Camera::getViewCenter() const {
    return m_viewCenter;
}

void Camera::setTileGroups(TileGroup &map, TileGroup &shadows) {
    m_mapTilegroup = std::unique_ptr<TileGroup>(&map);
    m_shadowsTilegroup = std::unique_ptr<TileGroup>(&shadows);
}

void Camera::setEntitiesContainer(EntitiesContainer &container) {
    m_entitiesContainer = std::unique_ptr<EntitiesContainer>(&container);
}
