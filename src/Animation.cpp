#include "Animation.hpp"

fe::Animation::Animation() : m_spriteSheet(nullptr), m_timer(), m_currentFrameSet(nullptr), m_currentFrame(0),
                             m_playing(fe::Status::On)
{ }

fe::Animation::~Animation() {
    m_spriteSheet.release();
    m_currentFrameSet.release();
}

void fe::Animation::setSpriteSheet(sf::Sprite &spriteSheet) {
    m_spriteSheet.release();
    m_spriteSheet = std::unique_ptr<sf::Sprite>(&spriteSheet);
}

void fe::Animation::setCurrentFrameSet(fe::FrameSet &frameSet) {
    m_currentFrameSet.release();
    m_currentFrameSet = std::unique_ptr<fe::FrameSet>(&frameSet);

    frameSprite();
}

void fe::Animation::animate() {
    if(m_timer.getElapsedTime()>m_currentFrameSet->getSpeed() && m_playing==fe::Status::On)
    {
        if(m_currentFrame+1<m_currentFrameSet->getLength())
            m_currentFrame++;
        else
            m_currentFrame = 0;

        m_timer.restart();

        frameSprite();


    }
}

void fe::Animation::frameSprite() {
    m_spriteSheet->setTextureRect(sf::IntRect(m_currentFrameSet->getFrameCoordAt(m_currentFrame).x,
                                                  m_currentFrameSet->getFrameCoordAt(m_currentFrame).y,
                                                  m_currentFrameSet->getFrameSize().x,
                                                  m_currentFrameSet->getFrameSize().y));
}

void fe::Animation::setStatus(const fe::Status status) {
    if(status==fe::Status::Off)
    {
        m_currentFrame = 0;
        frameSprite();
    }
    m_playing = status;
}

unsigned int fe::Animation::getCurrentFrame() const {
    return m_currentFrame;
}

fe::Status fe::Animation::getStatus() const {
    return m_playing;
}
