#ifndef ENTITIESCONTAINER_H
#define ENTITIESCONTAINER_H

#include "Entity.h"
#include "RunEnvironment.h"
#include "MData.h"

class EntitiesContainer
{
    public:
        EntitiesContainer(MData &mapData, RunEnvironment &environment);
        ~EntitiesContainer();

        //To add an entity to the list
        void add();

        //To remove an entity from the list
        void remove(const unsigned int iter);

        //To get a reference to an entity of the list
        Entity &entityAt(const unsigned int iter);

        //To get the total entities number
        unsigned int getEntitiesNumber() const;
    private:
        std::vector<Entity*> m_entities;
        //Reference to MData for the Entity constructor
        MData &m_mapData;
        //Reference to RunEnvironment
        RunEnvironment &m_environment;
};

#endif // ENTITIESCONTAINER_H
