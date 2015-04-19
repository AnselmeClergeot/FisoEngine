#include "Animator.h"

Animator::Animator(MData &mapData, TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, DynamicShader &shader)
: m_tileAnimationsData(), m_mapData(mapData), m_timer(), m_speed(150), m_x(0), m_maxLength(0),
m_mapTilegroup(mapTilegroup), m_shadowsTilegroup(shadowsTilegroup), m_shader(shader) {}

void Animator::resizeAnimationsDataList() {
    m_tileAnimationsData.resize(m_mapData.getTempConf().getSize());
}

void Animator::setAnimation(const unsigned tile, const unsigned int length) {
    if(length>m_maxLength)
        m_maxLength = length;

    for(int i(0); i<m_tileAnimationsData.size(); i++)
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

        updateX();


        for(int i(0); i<m_tileAnimationsData.size(); i++)
        {
            if(m_tileAnimationsData[i].getStatus()==true)
            {
                if(m_tileAnimationsData[i].getLength()>1)
                {
                    //RIGHT DIRECTION ANIMATION------------------------------------------------
                    if(m_tileAnimationsData[i].getDirection()==Right)
                    {
                        if(m_tileAnimationsData[i].getX()+1<m_tileAnimationsData[i].getLength())
                            m_tileAnimationsData[i].increaseX();
                        else
                        {
                            m_tileAnimationsData[i].setX(0);
                            if(m_tileAnimationsData[i].getKind()==Single)
                                m_tileAnimationsData[i].setStatus(false);
                        }

                    }

                    //LEFT DIRECTION ANIMATION-------------------------------------------------
                    if(m_tileAnimationsData[i].getDirection()==Left)
                    {
                        if(m_tileAnimationsData[i].getX()>0)
                            m_tileAnimationsData[i].decreaseX();
                        else
                        {
                            m_tileAnimationsData[i].setX(m_tileAnimationsData[i].getLength()-1);
                            if(m_tileAnimationsData[i].getKind()==Single)
                                m_tileAnimationsData[i].setStatus(false);
                        }

                    }
                }
            }
        }
        apply();
    }
}

void Animator::setSingleAnimKind(const unsigned int tile) {
    for(int i(0); i<m_tileAnimationsData.size(); i++)
    {
        if(m_mapData.getTempConf().at(i)==tile)
            m_tileAnimationsData[i].setKind(Single);
    }
}

void Animator::setDirectionOf(const Vector3 coord, AnimDirection direction) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setDirection(direction);
}

void Animator::setKindOf(const Vector3 coord, AnimKind kind) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setKind(kind);
}

void Animator::setAnimStatus(const Vector3 coord, bool status) {
    m_tileAnimationsData[m_mapData.getTempConf().get3dIter(coord.x, coord.y, coord.z)].setStatus(status);
}

const TileAnimData &Animator::animAt(const unsigned int iter) const {
    return m_tileAnimationsData[iter];
}

void Animator::updateX() {
    if(m_x<m_maxLength)
            m_x++;
    else
        m_x = 0;
}

void Animator::apply() {
    for(int i(0); i<m_tileAnimationsData.size(); i++)
    {
        m_mapTilegroup.setTileSpritesheetX(i, m_tileAnimationsData[i].getX());
    }
}
