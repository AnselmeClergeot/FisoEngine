#include "TileGroup.h"

TileGroup::TileGroup(MapData &mapData,
                     ScreenInfos &screenInfos) : m_data(mapData),
                                                 m_loader(m_data, mapData),
                                                 m_drawer(mapData, m_data, screenInfos)
{ }

void TileGroup::setTilesetPath(const std::string path) {
    m_loader.setTilesetPath(path);
}

void TileGroup::initialize() {
    m_loader.initialize();
}

void TileGroup::configureWith(Matrix3d<unsigned int> &matrix) {
    m_data.configureWith(matrix);
}

void TileGroup::setTileAt(const Vector3 coord, const unsigned int index) {
    m_data.setTileAt(coord, index);
}

void TileGroup::updatePosition() {
    m_data.updatePosition();
}

void TileGroup::setTileOpacity(const Vector3 coord, const unsigned int opacity) {
    m_data.setTileOpacity(coord, opacity);
}

void TileGroup::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    m_data.setTypeOpacity(tile, opacity);
}

void TileGroup::setGroupOpacity(const unsigned int opacity) {
    m_data.setGroupOpacity(opacity);
}

void TileGroup::reloadOpacities() {
    m_data.reloadOpacities();
}

void TileGroup::draw(sf::RenderTarget& target, const unsigned int layer,
                     const EntitiesInterposing *interposing) const {
    m_drawer.draw(target, layer, interposing);
}

unsigned int TileGroup::getTileOpacity(const Vector3 coord) {
    return m_data.getTileOpacity(coord);
}

unsigned int TileGroup::getGroupOpacity() const {
    return m_data.getGroupOpacity();
}

void TileGroup::setTileTilesetX(const Vector3 coord, const Vector2 tilesetCoord) {
    m_data.setTileTilesetX(coord, tilesetCoord);
}

unsigned int TileGroup::getOpacityOfType(const unsigned int type) const {
    return m_data.getOpacityOfType(type);
}
