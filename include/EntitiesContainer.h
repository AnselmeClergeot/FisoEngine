#ifndef ENTITIESCONTAINER_H
#define ENTITIESCONTAINER_H

#include "MapData.h"
#include "ScreenInfos.h"
#include "Entity.h"

//EntitiesContainer is the class that warps all the entities into a vector and create/delete them.
class EntitiesContainer
{
    public:
        //The only constructor
        EntitiesContainer(MapData &mapData, ScreenInfos &screenInfos);

        //To add an entity to the list
        void createEntity();

        //To remove an entity from the list
        void removeEntity(const unsigned int iter);

        //To get a reference to an entity of the list
        Entity &entityAt(const unsigned int iter);

        //To get the total entities number
        unsigned int getEntitiesNumber() const;

    private:
        //The list of Entities
        std::vector<std::unique_ptr<Entity>> m_entities;
        //Reference to MData to initialize new Entity
        MapData &m_mapData;
        //Reference to RunEnvironment to get window size for culling purpose
        ScreenInfos &m_screenInfos;
};

#endif // ENTITIESCONTAINER_H
