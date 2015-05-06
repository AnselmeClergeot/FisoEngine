/**
 * \file EntitiesContainer.h
 * \brief Definition of EntitiesContainer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * EntitiesContainer.h defines the EntitiesContainer class
 *
 */

#ifndef ENTITIESCONTAINER_H
#define ENTITIESCONTAINER_H
#include "MapData.h"
#include "ScreenInfos.h"
#include "Entity.h"

/**
 * \class EntitiesContainer
 * \brief Class that contains the map entities and cares of adding/deleting entities
 *
 * This class is the user interface to add/delete/access entities of the map.
 * It is also for other classes the container of the entities.
 */
class EntitiesContainer
{
    public:

        /**
        * \fn EntitiesContainer(MapData &mapData, ScreenInfos &screenInfos)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param screenInfos Reference to the ScreenInfos of the user to get useful screen data
        */
        EntitiesContainer(MapData &mapData, ScreenInfos &screenInfos);

        /**
        * \fn void createEntity()
        * \brief To add an entity to the list
        *
        * \return void
        */
        void createEntity();

        /**
        * \fn void removeEntity(const unsigned int iter)
        * \brief To remove an entity from the list
        *
        * \param iter The entity index to delete
        * \return void
        */
        void removeEntity(const unsigned int iter);

        /**
        * \fn void removeAll()
        * \brief To remove all the entities of the map
        *
        * \return void
        */
        void removeAll();

        /**
        * \fn Entity &entityAt(const unsigned int iter)
        * \brief To get a reference to an entity from its index
        *
        * \param iter The entity index
        * \return The wanted entity (Entity)
        */
        Entity &entityAt(const unsigned int iter);

        /**
        * \fn unsigned int getEntitiesNumber() const
        * \brief To get the total entities number
        *
        * \return The entities number in an unsigned int
        */
        unsigned int getEntitiesNumber() const;

    private:

        std::vector<std::unique_ptr<Entity>> m_entities; /*!< The entities vector */

        MapData &m_mapData; /*!< The reference to the MapData to get useful data */

        ScreenInfos &m_screenInfos; /*!< The reference to the user ScreenInfos to get useful screen data */
};

#endif // ENTITIESCONTAINER_H
