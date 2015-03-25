#include "SData.h"

SData::SData(MData &data) : m_mapData(data), m_matrix(), m_on(false), m_initialized(false)
{

}

void SData::setOn(bool on)
{
    if(m_initialized)
        m_on = on;
}

void SData::setInitialized()
{
    m_initialized = true;
}

Matrix3d &SData::getMatrix()
{
    return m_matrix;
}

void SData::setNewTile(const Vector3 coord, TileGroup &mapTg, TileGroup &shadowsTg)
{
    for(int z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
        {
            m_matrix.at(coord.x, coord.y, z) = m_mapData.getTempConf().at(coord.x, coord.y, coord.z);
            shadowsTg.updateTile(m_matrix.get3dIter(coord.x, coord.y, z));

            shadowsTg.setSpecificOpacity(m_matrix.get3dIter(coord.x, coord.y, z),
            (int)((float)mapTg.getTileOpacity(m_matrix.get3dIter(coord.x, coord.y, coord.z))/
            (float)255*shadowsTg.getGroupOpacity()));
            break;
        }
        else
        {
            m_matrix.at(coord.x, coord.y, z) = m_mapData.getInvisibleTile();
            mapTg.updateTile(m_matrix.get3dIter(coord.x, coord.y, z));
        }
    }

    for(int z(coord.z); z<m_mapData.getSize().y; z++)
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)) && z!=coord.z)
            setNewTile(Vector3(coord.x, coord.y, z), mapTg, shadowsTg);
}

void SData::setNewTile(const Vector3 coord)
{
    for(int z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
        {
            m_matrix.at(coord.x, coord.y, z) = m_mapData.getTempConf().at(coord.x, coord.y, coord.z);
            break;
        }
        else
        {
            m_matrix.at(coord.x, coord.y, z) = m_mapData.getInvisibleTile();
        }
    }

    for(int z(coord.z); z<m_mapData.getSize().y; z++)
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)) && z!=coord.z)
            setNewTile(Vector3(coord.x, coord.y, z));
}

bool SData::isOn() const
{
    return m_on;
}

bool SData::isInitialized() const
{
    return m_initialized;
}
