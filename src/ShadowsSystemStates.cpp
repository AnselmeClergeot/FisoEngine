#include "ShadowsSystemStates.h"

ShadowsSystemStates::ShadowsSystemStates() : m_on(false),
                                             m_initialized(false)
{ }

void ShadowsSystemStates::setOn(bool on) {
    if(m_initialized)
        m_on = on;
}

void ShadowsSystemStates::setInitialized() {
    m_initialized = true;
}

bool ShadowsSystemStates::isOn() const {
    return m_on;
}

bool ShadowsSystemStates::isInitialized() const {
    return m_initialized;
}
