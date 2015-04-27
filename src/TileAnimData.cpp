#include "TileAnimData.h"

TileAnimData::TileAnimData() : m_kind(Global),
                               m_direction(Right),
                               m_x(0),
                               m_status(false),
                               m_length(0)
{

}

void TileAnimData::setKind(const AnimKind kind) {
    m_kind = kind;
    if(m_kind==Single)
        m_status = false;
    if(m_kind==Global)
        m_status = true;

    resetX();
}

void TileAnimData::setDirection(const AnimDirection direction) {
    m_direction = direction;

    resetX();
}

void TileAnimData::setStatus(const bool status) {
    m_status = status;

    resetX();
}

void TileAnimData::setLength(const unsigned int length) {
    m_length = length;
}

AnimKind TileAnimData::getKind() const {
    return m_kind;
}

AnimDirection TileAnimData::getDirection() const {
    return m_direction;
}

unsigned int TileAnimData::getLength() const {
    return m_length;
}

unsigned int TileAnimData::getX() const {
    return m_x;
}

bool TileAnimData::getStatus() const {
    return m_status;
}

void TileAnimData::updateX() {
    if(m_status==true)
        if(m_length>1)
        {
            if(m_direction==Right)
            {
                if(m_x+1<m_length)
                    m_x++;
                else
                {
                    if(m_kind==Global)
                        resetX();
                    else if(m_kind==Single)
                        m_status = false;
                }

            }

            if(m_direction==Left)
            {
                if(m_x>0)
                    m_x--;
                else
                {
                    if(m_kind==Global)
                        resetX();
                    else if(m_kind==Single)
                        m_status = false;
                }

            }
        }
}

void TileAnimData::resetX() {
        if(m_direction==Left)
            m_x = m_length-1;

        if(m_direction==Right)
            m_x = 0;
}
