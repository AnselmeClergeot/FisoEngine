#include "FrameSet.hpp"

fe::FrameSet::FrameSet() : m_speed(50), m_frames()
{ }

fe::FrameSet::FrameSet(const fe::FrameSet &frameSet) : m_speed(frameSet.m_speed),
                                                       m_frames(frameSet.m_frames)
{ }

fe::FrameSet &fe::FrameSet::operator=(const fe::FrameSet &frameSet) {
    m_speed = frameSet.m_speed;
    m_frames = frameSet.m_frames;
}

void fe::FrameSet::setSpeed(const unsigned int speed) {
    m_speed = speed;
}

void fe::FrameSet::addFrame(const fe::Vector2 coord, const fe::Vector2 size) {
    std::vector<fe::Vector2> temp;
    temp.push_back(coord);
    temp.push_back(size);
    m_frames.push_back(temp);
}

void fe::FrameSet::addFrame(const unsigned int x, const unsigned int y, const unsigned int w, const unsigned int h) {
    addFrame(fe::Vector2(x, y), fe::Vector2(w, h));
}

void fe::FrameSet::resetFrames() {
    m_frames.clear();
}

unsigned int fe::FrameSet::getLength() const {
    return m_frames.size();
}

fe::Vector2 &fe::FrameSet::getFrameCoord(const unsigned int frameNumber) {
    assert(frameNumber<m_frames.size());
    return m_frames[frameNumber][0];
}

fe::Vector2 &fe::FrameSet::getFrameSize(const unsigned int frameNumber) {
    assert(frameNumber<m_frames.size());
    return m_frames[frameNumber][1];
}

unsigned int fe::FrameSet::getSpeed() const {
    return m_speed;
}
