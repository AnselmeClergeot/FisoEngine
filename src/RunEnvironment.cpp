#include "RunEnvironment.h"

RunEnvironment::RunEnvironment() : m_windowRes(1980, 1080)
{}

void RunEnvironment::setWindowResolution(const Vector2 res) {
    m_windowRes = res;
}

void RunEnvironment::setWindowResolution(const unsigned int w, const unsigned int h) {
    setWindowResolution(Vector2(w, h));
}

Vector2 RunEnvironment::getWindowResolution() const {
    return m_windowRes;
}
