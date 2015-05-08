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

#include "Entity.h"
#include "IsometricMath.h"
#include "ioFuncs.h"
#include "DrawingFuncs.h"

Entity::Entity(MapData &mapData,
               Camera &camera) :  m_tilePosition(),
                                  m_pixelPosition(),
                                  m_dimensions(),
                                  m_baseCoord(),
                                  m_texture(),
                                  m_sprite(),
                                  m_drawState(false),
                                  m_mapData(mapData),
                                  m_camera(camera)
{
    setPosition(m_pixelPosition);
}

void Entity::setDimensions(const Vector2 dim) {
    m_dimensions = dim;
}

void Entity::setDimensions(const unsigned int w, const unsigned int h) {
    m_dimensions.x = w;
    m_dimensions.y = h;
}

void Entity::setBaseCoord(const Vector2 coord) {
    m_baseCoord = coord;
}

void Entity::setBaseCoord(const unsigned int x, const unsigned int y) {
    m_baseCoord.x = x;
    m_baseCoord.y = y;
}

void Entity::setPosition(const Vector2 pos) {
    m_pixelPosition = pos;
    m_sprite.setPosition(pos.x+m_camera.getViewDimensions().x/2-m_camera.getViewCenter().x,
                         pos.y+m_camera.getViewDimensions().y/2-m_camera.getViewCenter().y);

    calculateTilePosition();
}

void Entity::setPosition(const unsigned int x, const unsigned int y) {
    setPosition(Vector2(x, y));
}

void Entity::move(const Vector2 rate) {
    setPosition(m_pixelPosition);
    m_pixelPosition += rate;
}

void Entity::move(const unsigned int rx, const unsigned int ry) {
    move(Vector2(rx, ry));
}

void Entity::setImagePath(const std::string path) {
    if(fileExists(path))
        m_texture.loadFromFile(path);

    m_sprite.setTexture(m_texture);
}

void Entity::draw(sf::RenderTarget& target) const {
    if(isVisible(m_pixelPosition, m_dimensions, m_camera))
        target.draw(m_sprite);
}

void Entity::setDrawState(const bool state) {
    m_drawState = state;
}

void Entity::calculateTilePosition() {
    m_tilePosition.x = getTileCoordAtPixels(m_pixelPosition+m_baseCoord, m_tilePosition.z, m_mapData).x;
    m_tilePosition.y = getTileCoordAtPixels(m_pixelPosition+m_baseCoord, m_tilePosition.z, m_mapData).y;
}

void Entity::setLayer(const unsigned int layer) {
    m_tilePosition.z = layer;
}

Vector3 Entity::getTilePosition() const {
    return m_tilePosition;
}

Vector2 Entity::getBaseCoord() const {
    return m_baseCoord;
}

Vector2 Entity::getDimensions() const {
    return m_dimensions;
}

Vector2 Entity::getPosition() const {
    return m_pixelPosition;
}

sf::Sprite &Entity::getSprite() {
    return m_sprite;
}

bool Entity::getDrawingState() const {
    return m_drawState;
}
