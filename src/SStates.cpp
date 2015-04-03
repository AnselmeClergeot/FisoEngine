#include "SStates.h"

SStates::SStates() : m_on(false), m_initialized(false)
{}

void SStates::setOn(bool on) {
    if(m_initialized)
        m_on = on;
}

void SStates::setInitialized() {
    m_initialized = true;
}

bool SStates::isOn() const {
    return m_on;
}

bool SStates::isInitialized() const {
    return m_initialized;
}
