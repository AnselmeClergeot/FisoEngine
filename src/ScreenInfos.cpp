#include "ScreenInfos.h"

ScreenInfos::ScreenInfos() : m_windowRes(1980, 1080)
{

}

ScreenInfos::ScreenInfos(const unsigned int screenW, const unsigned int screenH) : m_windowRes(screenW, screenH)
{

}

void ScreenInfos::setWindowResolution(const Vector2 res) {
    m_windowRes = res;
}

void ScreenInfos::setWindowResolution(const unsigned int w, const unsigned int h) {
    setWindowResolution(Vector2(w, h));
}

Vector2 ScreenInfos::getWindowResolution() const {
    return m_windowRes;
}
