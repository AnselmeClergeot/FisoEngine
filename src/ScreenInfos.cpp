#include "ScreenInfos.h"

ScreenInfos::ScreenInfos() : m_windowRes(1980, 1080)
{}

void ScreenInfos::setWindowResolution(const Vector2 res) {
    m_windowRes = res;
}

void ScreenInfos::setWindowResolution(const unsigned int w, const unsigned int h) {
    setWindowResolution(Vector2(w, h));
}

Vector2 ScreenInfos::getWindowResolution() const {
    return m_windowRes;
}
