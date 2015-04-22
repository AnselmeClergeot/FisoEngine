#include "Entity.h"

#include "IsometricMath.h"
#include "ioFuncs.h"
#include "DrawingFuncs.h"

Entity::Entity(MData &mapData, ScreenInfos &screenInfos) : m_tilePosition(),
                                                              m_pixelPosition(),
                                                              m_dimensions(),
                                                              m_baseCoord(),
                                                              m_texture(),
                                                              m_sprite(),
                                                              m_drawState(false),
                                                              m_mapData(&mapData),
                                                              m_screenInfos(&screenInfos)
{}

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

void Entity::setPixelPosition(const Vector2 pos) {
    m_pixelPosition = pos;
    m_sprite.setPosition(pos.x, pos.y);

    calculateTilePosition();
}

void Entity::setPixelPosition(const unsigned int x, const unsigned int y) {
    setPixelPosition(Vector2(x, y));
}

void Entity::move(const Vector2 rate) {
    m_pixelPosition += rate;
    setPixelPosition(m_pixelPosition);
}

void Entity::move(const unsigned int x, const unsigned int y) {
    move(Vector2(x, y));
}

void Entity::setImagePath(const std::string path) {
    if(fileExists(path))
        m_texture.loadFromFile(path);
    m_sprite.setTexture(m_texture);
}

void Entity::draw(sf::RenderTarget& target) const {
    if(isVisible(m_pixelPosition, m_baseCoord, *m_screenInfos))
        target.draw(m_sprite);
}

void Entity::setDrawState(const bool set) {
    m_drawState = set;
}

void Entity::calculateTilePosition() {
    m_tilePosition.x = getTileCoordAtPixels(m_pixelPosition+m_baseCoord, m_tilePosition.z, *m_mapData).x;
    m_tilePosition.y = getTileCoordAtPixels(m_pixelPosition+m_baseCoord, m_tilePosition.z, *m_mapData).y;
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

Vector2 Entity::getPixelPosition() const {
    return m_pixelPosition;
}

sf::Sprite &Entity::getSprite() {
    return m_sprite;
}

bool Entity::getDrawingState() const {
    return m_drawState;
}
