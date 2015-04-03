#include "ShadowsInterface.h"

ShadowsInterface::ShadowsInterface(SInitializer &initializer, SStates &states, TileGroup &tilegroup)
 : m_initializer(initializer), m_states(states), m_tilegroup(tilegroup)
{}

void ShadowsInterface::setTileset(const std::string path) {
    m_tilegroup.setTilesetPath(path);
}

void ShadowsInterface::setOpacity(const unsigned int opacity) {
    m_tilegroup.setGroupOpacity(opacity);
}

void ShadowsInterface::init() {
    m_initializer.initialize();
    m_tilegroup.initialize();
}

void ShadowsInterface::setOn(bool on) {
    m_states.setOn(on);
}
