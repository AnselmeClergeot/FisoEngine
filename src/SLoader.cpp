#include "SLoader.h"

SLoader::SLoader(SData &data, MData &mapData) : m_data(data), m_mapData(mapData)
{

}

void SLoader::initialize()
{
    resizeMatrix();
    calculateMatrix();
    m_data.setInitialized();
}

void SLoader::resizeMatrix()
{
    m_data.getMatrix().resize(m_mapData.getSize().x, m_mapData.getSize().x, m_mapData.getSize().y, m_mapData.getInvisibleTile());
}

void SLoader::calculateMatrix()
{
    for(unsigned int z(0); z<m_mapData.getSize().y; z++)
        for(unsigned int y(0); y<m_mapData.getSize().x; y++)
            for(unsigned int x(0); x<m_mapData.getSize().x; x++)
            {
                if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(x, y, z)))
                    for(unsigned int layerOffset(z+1); layerOffset<m_mapData.getSize().y; layerOffset++)
                    {
                        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(x, y, layerOffset)))
                            m_data.getMatrix().at(x, y, z)=m_mapData.getTempConf().at(x, y, layerOffset);
                    }
            }
}
