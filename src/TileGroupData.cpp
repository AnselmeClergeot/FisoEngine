#include "TileGroupData.h"

TileGroupData::TileGroupData(MapData &mapData) : m_tileset(),
                                                 m_tiles(),
                                                 m_config(),
                                                 m_mapData(mapData),
                                                 m_opacity(255)
{ }

sf::Texture &TileGroupData::getTileset() {
    return m_tileset;
}

Matrix3d<sf::Sprite> &TileGroupData::getTiles() {
    return m_tiles;
}

unsigned int TileGroupData::getTileNumber() const {
    return m_mapData.getTempConf().getSize();
}

void TileGroupData::setConfiguration(Matrix3d<unsigned int> &config) {
    m_config = config;
}

void TileGroupData::setTileAt(const Vector3 coord, const unsigned int index) {
    m_config.at(coord.x, coord.y, coord.z) = index;

    //If the tile set is the invisible one, reset the opacity
    if(index==m_mapData.getInvisibleTile())
        resetOpacityOf(coord);

    //Updating appearance of this tile
    updateTileFromConfig(m_config.get3dIter(coord.x, coord.y, coord.z));
}

sf::Sprite &TileGroupData::spriteAt(const Vector3 coord) {
    return m_tiles.at(coord.x, coord.y, coord.z);
}

sf::Sprite &TileGroupData::spriteAt(const unsigned int index) {
    return m_tiles.at(index);
}

void TileGroupData::updatePosition() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                setTilePosition(Vector3(x, y, z));
}

void TileGroupData::setTilePosition(const Vector3 coord) {
    m_tiles.at(coord.x, coord.y, coord.z).
    setPosition(toIsometricPosition(coord, m_mapData).x, toIsometricPosition(coord, m_mapData).y);
}

void TileGroupData::updateTileFromConfig(const unsigned int index) {
    frameTile(index, Vector2(0, m_config.at(index)));
}

void TileGroupData::frameTile(const unsigned int index, const Vector2 coord) {
    m_tiles.at(index).setTextureRect(sf::IntRect(coord.x*m_mapData.getTileSize().x,
                                              coord.y*m_mapData.getTileSize().y,
                                              m_mapData.getTileSize().x,
                                              m_mapData.getTileSize().y));
}

void TileGroupData::setTileOpacity(const Vector3 coord, const unsigned int opacity) {
    m_tiles.at(coord.x, coord.y, coord.z).
    setColor(sf::Color(255, 255, 255, opacity));
}

void TileGroupData::setTypeOpacity(const unsigned int tile, const unsigned int opacity) {
    for(std::size_t i(0); i<m_tiles.getSize(); i++)
        if(m_mapData.getTempConf().at(i)==tile)
            m_tiles.at(i).setColor(sf::Color(255, 255, 255, opacity));
}

void TileGroupData::setGroupOpacity(const unsigned int opacity) {
    m_opacity = opacity;
    applyGroupOpacity();
}

void TileGroupData::applyGroupOpacity() {
    for(std::size_t i(0); i<m_tiles.getSize(); i++)
        m_tiles.at(i).setColor(sf::Color(255, 255, 255, m_opacity));
}

unsigned int TileGroupData::getTileOpacity(const Vector3 coord) {
    return m_tiles.at(coord.x, coord.y, coord.z).getColor().a;
}

unsigned int TileGroupData::getGroupOpacity() const {
    return m_opacity;
}

void TileGroupData::resetOpacityOf(const Vector3 coord) {
    setTileOpacity(coord, 255);
}

void TileGroupData::setTileTilesetX(const Vector3 coord, unsigned int x) {
    frameTile(m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z),
              Vector2(x,
                      m_config.at(coord.x, coord.y, coord.z)));
}
