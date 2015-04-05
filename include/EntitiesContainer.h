#ifndef ENTITIESCONTAINER_H
#define ENTITIESCONTAINER_H

#include "Entity.h"

#include "MData.h"

class EntitiesContainer
{
    public:
        EntitiesContainer(MData &mapData);

        //To add an entity to the list
        void add();

        //To remove an entity from the list
        void remove(const unsigned int iter);

        //To get a reference to an entity of the list
        Entity &entityAt(const unsigned int iter);
    private:
        std::vector<Entity> m_entities;
        //Reference to MData for the Entity constructor
        MData &m_mapData;
};

#endif // ENTITIESCONTAINER_H
