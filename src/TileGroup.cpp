#include "TileGroup.h"

TileGroup::TileGroup(Matrix3d &config, MData &mapData) : m_data(config, mapData),
                                                         m_loader(m_data),
                                                         m_drawer(mapData, m_data)
{

}

void TileGroup::setTilesetPath(const std::string path)
{
    m_loader.setTilesetPath(path);
}

void TileGroup::initialize()
{
    m_loader.initialize();
}

void TileGroup::updatePosition()
{
    m_data.updatePosition();
}

void TileGroup::updateTile(const unsigned int index)
{
    m_data.updateTile(index);
}

void TileGroup::frameTile(const unsigned int index, const Vector2 coord)
{
    m_data.frameTile(index, coord);
}

void TileGroup::draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer) const
{
    m_drawer.draw(target, states, layer);
}
