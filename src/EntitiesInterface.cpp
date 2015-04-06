#include "EntitiesInterface.h"

EntitiesInterface::EntitiesInterface(EntitiesContainer &container) : m_container(container)
{}

void EntitiesInterface::createEntity() {
    m_container.add();
}

void EntitiesInterface::removeEntity(const unsigned int iter) {
    m_container.remove(iter);
}

void EntitiesInterface::setDimensionsOf(const unsigned int iter, const Vector2 dim) {
    m_container.entityAt(iter).setDimensions(dim);
}

void EntitiesInterface::setBaseCoordOf(const unsigned int iter, const Vector2 coord) {
    m_container.entityAt(iter).setBaseCoord(coord);
}

void EntitiesInterface::updatePixelPositionOf(const unsigned int iter, const Vector2 pos) {
    m_container.entityAt(iter).updatePixelPosition(pos);
}

void EntitiesInterface::move(const unsigned int iter, const Vector2 rate) {
    m_container.entityAt(iter).move(rate);
}

void EntitiesInterface::setImagePathOf(const unsigned int iter, const std::string path) {
    m_container.entityAt(iter).setImagePath(path);
}

void EntitiesInterface::setDrawStateOf(const unsigned int iter, const bool set) {
    m_container.entityAt(iter).setDrawState(set);
}

void EntitiesInterface::setLayerOf(const unsigned int iter, const unsigned int layer) {
    m_container.entityAt(iter).setLayer(layer);
}

sf::Sprite &EntitiesInterface::getSpriteOf(const unsigned int iter) {
    return m_container.entityAt(iter).getSprite();
}

Vector3 EntitiesInterface::getTilePositionOf(const unsigned int iter) {
    return m_container.entityAt(iter).getTilePosition();
}

Vector2 EntitiesInterface::getBaseCoordOf(const unsigned int iter) {
    return m_container.entityAt(iter).getBaseCoord();
}

bool EntitiesInterface::getDrawStateOf(const unsigned int iter) {
    return m_container.entityAt(iter).getDrawingState();
}

Vector2 EntitiesInterface::getDimensionsOf(const unsigned int iter) {
    return m_container.entityAt(iter).getDimensions();
}
