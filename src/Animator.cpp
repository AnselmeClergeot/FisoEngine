#include "Animator.h"

Animator::Animator(MapData &mapData, TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, DynamicShader &shader)
: m_tileAnimationsData(), m_mapData(mapData), m_timer(), m_speed(150),
m_mapTilegroup(mapTilegroup), m_shadowsTilegroup(shadowsTilegroup), m_shader(shader) {}

void Animator::resizeAnimationsDataList() {
    m_tileAnimationsData.resize(m_mapData.getTempConf().getSize());
}

void Animator::setAnimation(const unsigned tile, const unsigned int length) {

    for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
        {
            m_tileAnimationsData[i].setLength(length);
            m_tileAnimationsData[i].setStatus(true);
        }
    }
}

void Animator::setSpeed(const unsigned int speed) {
    m_speed = speed;
}

void Animator::next() {

    if(m_timer.getElapsedTime() > m_speed)
    {
        m_timer.restart();

        for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
            m_tileAnimationsData[i].updateX();
    }
    apply();
}

void Animator::setSingleAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData[i].setKind(Single);
    }
}

void Animator::setGlobalAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData[i].setKind(Global);
    }
}

void Animator::setDirectionOf(const Vector3 coord, AnimDirection direction) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setDirection(direction);
}

void Animator::setKindOf(const Vector3 coord, AnimKind kind) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setKind(kind);
}

void Animator::launchAnimation(const Vector3 coord) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setStatus(true);
}

void Animator::launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    launchAnimation(Vector3(x, y, z));
}

void Animator::stopAnimation(const Vector3 coord) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setStatus(false);
}

void Animator::stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z) {
    stopAnimation(Vector3(x, y, z));
}

void Animator::apply() {
    for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
        m_mapTilegroup.setTileSpritesheetX(i, m_tileAnimationsData[i].getX());
}
