#include "TileGroupData.h"

TileGroupData::TileGroupData(Matrix3d &config, MData &mapData) : m_tileset(), m_tiles(), m_config(config), m_mapData(mapData)
{

}

sf::Texture &TileGroupData::getTileset()
{
    return m_tileset;
}

std::vector<sf::Sprite> &TileGroupData::getTiles()
{
    return m_tiles;
}

Matrix3d &TileGroupData::getConfig()
{
    return m_config;
}

unsigned int TileGroupData::getSize() const
{
    return m_config.getSize();
}

sf::Sprite &TileGroupData::spriteAt(const unsigned int index)
{
    return m_tiles[index];
}

void TileGroupData::updatePosition()
{
    for(int z(0); z<m_mapData.getSize().y; z++)
        for(int y(0); y<m_mapData.getSize().x; y++)
            for(int x(0); x<m_mapData.getSize().x; x++)
                setTilePosition(Vector3(x, y, z));
}

void TileGroupData::setTilePosition(const Vector3 coord)
{
    m_tiles[m_config.get3dIter(coord.x, coord.y, coord.z)].
    setPosition(toIsometricPosition(coord, m_mapData).x, toIsometricPosition(coord, m_mapData).y);
}

void TileGroupData::updateTile(const unsigned int index)
{
    frameTile(index, Vector2(0, m_config.at(index)));
}

void TileGroupData::frameTile(const unsigned int index, const Vector2 coord)
{
    m_tiles[index].setTextureRect(sf::IntRect(coord.x*m_mapData.getTileSize().x,
                                                coord.y*m_mapData.getTileSize().y,
                                                m_mapData.getTileSize().x,
                                                m_mapData.getTileSize().y));
}
