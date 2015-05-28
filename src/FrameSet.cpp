#include "FrameSet.hpp"

fe::FrameSet::FrameSet() : m_length(0), m_frameSize(0, 0), m_speed(0), m_frameCoords()
{

}

void fe::FrameSet::setSpeed(const unsigned int speed) {
    m_speed = speed;
}

void fe::FrameSet::addFrameCoord(const fe::Vector2 coord) {
    m_frameCoords.push_back(coord);
}

void fe::FrameSet::addFrameCoord(const unsigned int x, const unsigned int y) {
    addFrameCoord(fe::Vector2(x, y));
}

void fe::FrameSet::setFrameSize(const fe::Vector2 size) {
    m_frameSize = size;
}

void fe::FrameSet::setFrameSize(const unsigned int w, const unsigned int h) {
    setFrameSize(fe::Vector2(w, h));
}

unsigned int fe::FrameSet::getLength() const {
    return m_frameCoords.size();
}

fe::Vector2 fe::FrameSet::getFrameSize() const {
    return m_frameSize;
}

unsigned int fe::FrameSet::getSpeed() const {
    return m_speed;
}

fe::Vector2 fe::FrameSet::getFrameCoordAt(const unsigned int frameNumber) const {
    assert(frameNumber<m_frameCoords.size());
    return m_frameCoords[frameNumber];
}
