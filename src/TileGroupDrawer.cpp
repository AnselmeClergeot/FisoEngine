#include "TileGroupDrawer.h"
//To access drawing usefull functions such as knowing if an element is visible
#include "DrawingFuncs.h"

TileGroupDrawer::TileGroupDrawer(MData &mapData, TileGroupData &data,
                                 RunEnvironment &environment) : m_mapData(mapData),
                                                                m_data(data),
                                                                m_environment(environment)
{}

void TileGroupDrawer::draw(sf::RenderTarget& target, const unsigned int layer,
                     const EntitiesInterposing *interposing) const {
    for(int x(0); x<m_mapData.getSize().x; x++)
        for(int y(0); y<m_mapData.getSize().x; y++)
    {
        if(isVisible(toIsometricPosition(Vector3(x, y, layer), m_mapData),
                             m_mapData.getTileSize(), m_environment))
        {
            target.draw(m_data.spriteAt(Vector3(x, y, layer)));
        }

        //If the tilegroup is a map tilegroup and that entities have to be interpose, then
        if(interposing!=0)
        {
            interposing->interpose(Vector3(x, y, layer), target);
        }
    }
}
