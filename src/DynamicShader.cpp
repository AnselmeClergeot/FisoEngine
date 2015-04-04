#include "DynamicShader.h"

DynamicShader::DynamicShader(MData &mapData, TileGroup &mapTg, TileGroup &shadowsTg) : m_mapData(mapData),
                                                                                       m_mapTg(mapTg),
                                                                                       m_shadowsTg(shadowsTg)
{}

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

    for(int z(coord.z); z<m_mapData.getSize().y; z++)
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)) && z!=coord.z)
            updateShading(Vector3(coord.x, coord.y, z));
}

void DynamicShader::updateOpacityOfAll() {
    for(int z(0); z<m_mapData.getSize().y; z++)
        for(int y(0); y<m_mapData.getSize().x; y++)
            for(int x(0); x<m_mapData.getSize().x; x++)
                updateOpacityOfSpecific(Vector3(x, y, getShadowZ(Vector3(x, y, z))));
}

void DynamicShader::updateOpacityOfType(const unsigned int type) {
    for(int z(0); z<m_mapData.getSize().y; z++)
        for(int y(0); y<m_mapData.getSize().x; y++)
            for(int x(0); x<m_mapData.getSize().x; x++)
                if(m_mapData.getTempConf().at(x, y, z)==type)
                updateOpacityOfSpecific(Vector3(x, y, getShadowZ(Vector3(x, y, z))));
}

void DynamicShader::updateOpacityOfSpecific(const Vector3 coord) {
    m_shadowsTg.setSpecificOpacity(m_mapData.getTempConf().get3dIter(coord.x, coord.y, getShadowZ(coord)),
    (int)((float)m_mapTg.getTileOpacity(m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z))/
    (float)255*m_shadowsTg.getGroupOpacity()));
}

unsigned int DynamicShader::getShadowZ(const Vector3 tileCoord) {
    for(int z(tileCoord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(tileCoord.x, tileCoord.y, z)))
            return z;
    }

    return 0;
}
