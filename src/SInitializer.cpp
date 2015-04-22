#include "SInitializer.h"

SInitializer::SInitializer(TileGroup &tilegroup, SStates &states, MapData &mapData) : m_tileGroup(tilegroup),
                                                                                    m_mapData(mapData),
                                                                                    m_states(states)
{}

void SInitializer::initialize() {
    Matrix3d tempConf;

    resizeMatrix(tempConf);
    fillMatrix(tempConf);
    m_states.setInitialized();
    m_tileGroup.setConfiguration(tempConf);
}

void SInitializer::resizeMatrix(Matrix3d &tempConf) {
    tempConf.resize(m_mapData.getSize().x, m_mapData.getSize().x, m_mapData.getSize().y,
                    m_mapData.getInvisibleTile());
}

void SInitializer::fillMatrix(Matrix3d &tempConf) {
    for(std::size_t z(0); z<m_mapData.getSize().y; z++)
        for(std::size_t y(0); y<m_mapData.getSize().x; y++)
            for(std::size_t x(0); x<m_mapData.getSize().x; x++)
                calculateShadowInConf(Vector3(x, y, z), tempConf);
}

void SInitializer::calculateShadowInConf(const Vector3 coord, Matrix3d &tempConf) {
    for(std::size_t z(coord.z-1); z>-1; z--)
    {
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)))
        {
            tempConf.at(coord.x, coord.y, z) = m_mapData.getTempConf().at(coord.x, coord.y, coord.z);
            break;
        }
        else
        {
            tempConf.at(coord.x, coord.y, z) = m_mapData.getInvisibleTile();
        }
    }

    for(std::size_t z(coord.z); z<m_mapData.getSize().y; z++)
        if(!m_mapData.isTranslucent(m_mapData.getTempConf().at(coord.x, coord.y, z)) && z!=coord.z)
            calculateShadowInConf(Vector3(coord.x, coord.y, z), tempConf);
}
