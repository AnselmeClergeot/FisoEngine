#include "EntitiesContainer.h"

EntitiesContainer::EntitiesContainer(MapData &mapData, ScreenInfos &screenInfos) : m_entities(),
                                                                                   m_mapData(mapData),
                                                                                   m_screenInfos(screenInfos)
{

}

void EntitiesContainer::createEntity() {
    m_entities.push_back(std::unique_ptr<Entity>(new Entity(m_mapData, m_screenInfos)));
}

void EntitiesContainer::removeEntity(const unsigned int iter) {
    m_entities.erase(m_entities.begin()+iter);
}

Entity &EntitiesContainer::entityAt(const unsigned int iter) {
    assert(iter<m_entities.size());
    return *m_entities[iter];
}

unsigned int EntitiesContainer::getEntitiesNumber() const {
    return m_entities.size();
}
