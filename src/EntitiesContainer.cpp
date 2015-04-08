#include "EntitiesContainer.h"

EntitiesContainer::EntitiesContainer(MData &mapData, RunEnvironment &environment) : m_entities(), m_mapData(mapData),
                                                                                    m_environment(environment)
{}

EntitiesContainer::~EntitiesContainer() {
    for(int i(0); i<m_entities.size(); i++)
        delete(m_entities[i]);
}

void EntitiesContainer::createEntity() {
    m_entities.push_back(new Entity(m_mapData, m_environment));
}

void EntitiesContainer::removeEntity(const unsigned int iter) {
    m_entities.erase(m_entities.begin()+iter);
}

Entity &EntitiesContainer::entityAt(const unsigned int iter) {
    return *m_entities[iter];
}

unsigned int EntitiesContainer::getEntitiesNumber() const {
    return m_entities.size();
}
