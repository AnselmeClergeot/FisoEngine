#include "EntitiesContainer.h"

EntitiesContainer::EntitiesContainer(MData &mapData) : m_entities(), m_mapData(mapData)
{}

void EntitiesContainer::add() {
    m_entities.push_back(Entity(m_mapData));
}

void EntitiesContainer::remove(const unsigned int iter) {
    m_entities.erase(m_entities.begin()+iter);
}

Entity &EntitiesContainer::entityAt(const unsigned int iter) {
    return m_entities[iter];
}
