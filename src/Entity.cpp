#include "Entity.h"

#include "IsometricMath.h"

Entity::Entity(MData &mapData) : m_tilePosition(), m_pixelPosition(), m_dimensions(), m_baseCoord(),
                   m_texture(), m_sprite(),
                   m_drawState(false),
                   m_mapData(&mapData)
{

}

bool Entity::fileExists(const std::string path) {
    std::ifstream file(path.c_str());

    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}

void Entity::setDimensions(const Vector2 dim) {
    m_dimensions = dim;
}

void Entity::setBaseCoord(const Vector2 coord) {
    m_baseCoord = coord;
}

void Entity::updatePixelPosition(const Vector2 pos) {
    m_pixelPosition = pos;
    m_sprite.setPosition(pos.x, pos.y);

    calculateTilePosition();
}

void Entity::move(const Vector2 rate)
{
    m_pixelPosition += rate;
    updatePixelPosition(m_pixelPosition);
}

void Entity::setImagePath(const std::string path) {
    if(fileExists(path))
        m_texture.loadFromFile(path);
    m_sprite.setTexture(m_texture);
}

void Entity::draw(sf::RenderTarget& target) const {
    if(isVisible(target))
        target.draw(m_sprite);
}

bool Entity::isVisible(sf::RenderTarget &target) const {
    return (m_pixelPosition.x+m_dimensions.x>0 &&
            m_pixelPosition.y+m_dimensions.y>0 &&
            m_pixelPosition.x < target.getSize().x &&
            m_pixelPosition.y < target.getSize().y);
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

sf::Sprite &Entity::getSprite() {
    return m_sprite;
}

bool Entity::getDrawingState() const {
    return m_drawState;
}
