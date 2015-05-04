#include "DynamicShader.h"

DynamicShader::DynamicShader(MapData &mapData,
                             TileGroup &mapTg,
                             TileGroup &shadowsTg) : m_mapData(mapData),
                                                     m_mapTg(mapTg),
                                                     m_shadowsTg(shadowsTg)
{ }

void DynamicShader::updateShading(const Vector3 coord) {
    for(int z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
        {
            m_shadowsTg.setTileAt(Vector3(coord.x, coord.y, z),
                                  m_mapData.getTempConf().at(coord.x, coord.y, coord.z));

            updateOpacityOfSpecific(coord);

            break;
        }

        else
            m_shadowsTg.setTileAt(Vector3(coord.x, coord.y, z), m_mapData.getInvisibleTile());
    }

    for(int z(coord.z+1); z<m_mapData.getSize().y; z++)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
            updateShading(Vector3(coord.x, coord.y, z));
    }
}

void DynamicShader::updateShadingOfAll() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                updateShading(Vector3(x, y, z));
}

void DynamicShader::updateOpacityOfAll() {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                updateOpacityOfSpecific(Vector3(x, y, z));
}

void DynamicShader::updateOpacityOfType(const unsigned int type) {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                if(m_mapData.getTempConf().at(x, y, z)==type)
                {
                    updateOpacityOfSpecific(Vector3(x, y, z));
                }
}

void DynamicShader::updateOpacityOfSpecific(const Vector3 coord) {
    if(haveShadowVisible(coord))
        m_shadowsTg.setTileOpacity(Vector3(coord.x, coord.y, getShadowZ(coord)),
                            (int)((float)m_mapTg.getTileOpacity(coord)/(float)255*m_shadowsTg.getGroupOpacity()));
}

unsigned int DynamicShader::getShadowZ(const Vector3 tileCoord) {
    assert(haveShadowVisible(tileCoord));

    for(int z(tileCoord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, z)))
            return z;
    }
}

bool DynamicShader::haveShadowVisible(const Vector3 tileCoord) {
    if(tileCoord.z==0)
        return false;

    for(int z(tileCoord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, z)))
            return true;
    }
    return false;
}

void DynamicShader::updateTileFromAnim(const Vector3 tileCoord, const unsigned int animX) {
    if(haveShadowVisible(tileCoord))
        m_shadowsTg.setTileTilesetX(Vector3(tileCoord.x, tileCoord.y, getShadowZ(tileCoord)),
                                    Vector2(animX,
                                            m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, tileCoord.z)));
}
