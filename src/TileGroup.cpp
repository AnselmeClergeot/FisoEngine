#include "TileGroup.h"

TileGroup::TileGroup(MData &mapData, ScreenInfos &screenInfos) : m_data(mapData),
                                                                    m_loader(m_data),
                                                                    m_drawer(mapData, m_data, screenInfos)
{}

void TileGroup::setTilesetPath(const std::string path) {
    m_loader.setTilesetPath(path);
}

void TileGroup::initialize() {
    m_loader.initialize();
    //If a tilegroup opacity was set before initialization...
    m_data.applyGroupOpacity();
}

void TileGroup::setConfiguration(Matrix3d &matrix) {
    m_data.setConfiguration(matrix);
}

void TileGroup::setTileAt(const Vector3 coord, const unsigned int index) {
    m_data.setTileAt(coord, index);
}

void TileGroup::updatePosition() {
    m_data.updateTileGroupPosition();
}

void TileGroup::setSpecificOpacity(const unsigned int index, const unsigned int opacity) {
    m_data.setSpecificOpacity(index, opacity);
}

void TileGroup::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    m_data.setTypeOpacity(tile, opacity);
}

void TileGroup::setGroupOpacity(const unsigned int opacity) {
    m_data.setGroupOpacity(opacity);
}

void TileGroup::draw(sf::RenderTarget& target, const unsigned int layer,
                     const EntitiesInterposing *interposing) const {
    m_drawer.draw(target, layer, interposing);
}

unsigned int TileGroup::getTileOpacity(const unsigned int index) const {
    return m_data.getTileOpacity(index);
}

unsigned int TileGroup::getGroupOpacity() const {
    return m_data.getGroupOpacity();
}

void TileGroup::setTileSpritesheetX(const unsigned int iter, const unsigned int x) {
    m_data.setTileSpritesheetX(iter, x);
}
