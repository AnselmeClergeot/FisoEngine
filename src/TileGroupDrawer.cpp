#include "TileGroupDrawer.h"

TileGroupDrawer::TileGroupDrawer(MData &mapData, TileGroupData &data) : m_mapData(mapData), m_data(data)
{

}

bool TileGroupDrawer::tileIsVisible(const Vector3 coord, sf::RenderTarget &target) const
{
    return (m_data.spriteAt(m_data.getConfig().get3dIter(coord.x, coord.y, coord.z)).
            getPosition().x+m_mapData.getTileSize().x>0 &&
            m_data.spriteAt(m_data.getConfig().get3dIter(coord.x, coord.y, coord.z)).
            getPosition().y+m_mapData.getTileSize().y>0 &&
            m_data.spriteAt(m_data.getConfig().get3dIter(coord.x, coord.y, coord.z)).
            getPosition().x < target.getSize().x &&
            m_data.spriteAt(m_data.getConfig().get3dIter(coord.x, coord.y, coord.z)).
            getPosition().y < target.getSize().y);
}

void TileGroupDrawer::draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer) const
{
    for(int x(0); x<m_mapData.getSize().x; x++)
            for(int y(0); y<m_mapData.getSize().x; y++)
    {
        if(tileIsVisible(Vector3(x, y, layer), target))
            target.draw(m_data.spriteAt(m_data.getConfig().get3dIter(x, y, layer)));
    }
}
