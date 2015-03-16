#include "Map.h"

Map::Map() : m_data(), m_dataLoader(m_data),
             m_tileGroup(m_data.getTempConf(), m_data)
{

}

void Map::init()
{
    m_dataLoader.load();
    m_tileGroup.initialize();
}

void Map::save()
{
    m_dataLoader.save();
}

void Map::addLayerFile(const std::string path)
{
    m_dataLoader.addLoadFile(path);
}

void Map::setTileset(const std::string path)
{
    m_tileGroup.setTilesetPath(path);
}

void Map::setTileSize(const Vector2 size)
{
    m_data.setTileSize(size);
}

void Map::setTileSize(const unsigned int w, const unsigned int h)
{
    setTileSize(Vector2(w, h));
}

void Map::setTileBaseHeight(const unsigned int h)
{
    m_data.setTileBaseHeight(h);
}

void Map::setTileAt(const Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw)
{
    if(modifConf)
        m_data.getPermConf().at(coord.x, coord.y, coord.z) = tile;

    if(modifDraw)
    {
        m_data.getTempConf().at(coord.x, coord.y, coord.z) = tile;
        m_tileGroup.updateTile(m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z));
    }
}

void Map::setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                    bool modifConf, bool modifDraw)
{
    setTileAt(Vector3(x, y, z), tile, modifConf, modifDraw);
}

void Map::setPosition(const Vector2 pos)
{
    m_data.setPosition(pos);
    m_tileGroup.updatePosition();
}

void Map::setPosition(const unsigned int x, const unsigned int y)
{
    setPosition(Vector2(x, y));
}

void Map::move(const Vector2 rate)
{
    m_data.move(rate);
    m_tileGroup.updatePosition();
}

void Map::move(const unsigned int rx, const unsigned int ry)
{
    move(Vector2(rx, ry));
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int layer(0); layer<m_data.getSize().y; layer++)
        m_tileGroup.draw(target, states, layer);
}

Vector3 Map::getDimensions() const
{
    return Vector3(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y);
}

Vector2 Map::getPosition() const
{
    return m_data.getPosition();
}

Vector2 Map::getTileSize() const
{
    return m_data.getTileSize();
}

unsigned int Map::getTileBaseHeight() const
{
    return m_data.getTileBaseHeight();
}

unsigned int Map::getTileAt(const Vector3 coord)
{
    return m_data.getPermConf().at(coord.x, coord.y, coord.z);
}

unsigned int Map::getTileAt(const unsigned int x, const unsigned int y, const unsigned int z)
{
    return getTileAt(Vector3(x, y, z));
}
