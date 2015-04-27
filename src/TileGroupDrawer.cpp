#include "TileGroupDrawer.h"
#include "DrawingFuncs.h"

TileGroupDrawer::TileGroupDrawer(MapData &mapData, TileGroupData &data, ScreenInfos &screenInfos)
    : m_mapData(mapData),
      m_data(data),
      m_screenInfos(screenInfos)
{

}

void TileGroupDrawer::draw(sf::RenderTarget& target, const unsigned int layer,
                           const EntitiesInterposing *interposing) const {
    for(std::size_t x(0); x<m_mapData.getSize().x; x++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
    {
        if(isVisible(toIsometricPosition(Vector3(x, y, layer), m_mapData),m_mapData.getTileSize(), m_screenInfos) &&
           m_mapData.getTempConf().at(x, y, layer)!=m_mapData.getInvisibleTile() &&
           m_data.getTileOpacity(m_mapData.getTempConf().get3dIter(x, y, layer))>0)
        {
            target.draw(m_data.spriteAt(Vector3(x, y, layer)));
        }

        //If the TileGroup is the map main TileGroup
        if(interposing!=0)
            interposing->interpose(Vector3(x, y, layer), target);
    }
}
