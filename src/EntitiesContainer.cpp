#include "EntitiesContainer.h"

EntitiesContainer::EntitiesContainer(MData &mapData) : m_entities(), m_mapData(mapData)
{}

EntitiesContainer::~EntitiesContainer() {
    for(int i(0); i<m_entities.size(); i++)
        delete(m_entities[i]);
}

void EntitiesContainer::add() {
    m_entities.push_back(new Entity(m_mapData));
}

void EntitiesContainer::remove(const unsigned int iter) {
    m_entities.erase(m_entities.begin()+iter);
}

Entity &EntitiesContainer::entityAt(const unsigned int iter) {
    return *m_entities[iter];
}

unsigned int EntitiesContainer::getEntitiesNumber() const {
    return m_entities.size();
}
