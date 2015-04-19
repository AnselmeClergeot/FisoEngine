#include "TileAnimData.h"

TileAnimData::TileAnimData() : m_kind(Global), m_direction(Right),
                               m_x(0), m_status(false), m_length(0)
{

}

void TileAnimData::setKind(const AnimKind kind) {
    m_kind = kind;
    if(m_kind==Single)
        m_status = false;
    if(m_kind==Global)
        m_status = true;
}

void TileAnimData::setDirection(const AnimDirection direction) {
    m_direction = direction;
    if(direction==Left)
        m_x = m_length-1;
    if(direction==Right)
        m_x = 0;
}

void TileAnimData::setStatus(const bool status) {
    m_status = status;
}

void TileAnimData::setLength(const unsigned int length) {
    m_length = length;
}

void TileAnimData::setX(const unsigned int x) {
    m_x = x;
}

void TileAnimData::increaseX() {
    m_x++;
}

void TileAnimData::decreaseX() {
    m_x--;
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