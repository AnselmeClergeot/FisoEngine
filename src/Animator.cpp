#include "Animator.h"

Animator::Animator(MapData &mapData, TileGroup &mapTilegroup, DynamicShader &shader) : m_tileAnimationsData(),                                                                                       m_mapData(mapData),
                                                                                       m_timer(),
                                                                                       m_speed(150),
                                                                                       m_animations(),
                                                                                       m_mapTilegroup(mapTilegroup),                                                                                       m_shader(shader) {}

void Animator::resizeAnimationsDataList() {
    m_tileAnimationsData.resize(m_mapData.getTempConf().getSize());
}

void Animator::setAnimation(const unsigned tile, const unsigned int length) {
    m_animations.push_back(Vector3(tile, length, 0));

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
    for(std::size_t i(0); i<m_animations.size(); i++) {
        if(m_animations[i].x==tile)
            m_animations[i].z = 1;
    }

    for(std::size_t i(0); i<m_tileAnimationsData.size(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData[i].setKind(Single);
    }
}

void Animator::setGlobalAnimKind(const unsigned int tile) {
    for(std::size_t i(0); i<m_animations.size(); i++) {
        if(m_animations[i].x==tile)
            m_animations[i].z = 0;
    }

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

unsigned int Animator::getSpeed() const {
    return m_speed;
}

void Animator::updateTileAt(const Vector3 coord) {

    for(std::size_t i(0); i<m_animations.size(); i++) {
        if(m_animations[i].x==m_mapData.getTempConf().at(coord.x, coord.y, coord.z))
        {
            if(m_animations[i].z==0)
            {
                m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
                setKind(Global);
                m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
                setStatus(true);
            }

            if(m_animations[i].z==1)
            {
                m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
                setKind(Single);
                m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
                setStatus(false);
            }
            m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            setLength(m_animations[i].y);

            m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            resetX();

            m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            setDirection(Right);

            return;
        }
    }
}
