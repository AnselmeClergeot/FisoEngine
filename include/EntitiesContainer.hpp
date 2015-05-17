/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * \file EntitiesContainer.hpp
 * \brief Definition of EntitiesContainer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * EntitiesContainer.hpp defines the EntitiesContainer class
 *
 */

#ifndef ENTITIESCONTAINER_HPP
#define ENTITIESCONTAINER_HPP
#include "MapData.hpp"
#include "Camera.hpp"
#include "Entity.hpp"

namespace fe {
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
        * \fn EntitiesContainer(fe::MapData &mapData, fe::Camera &camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param camera Reference to the map camera
        */
        EntitiesContainer(fe::MapData &mapData, fe::Camera &camera);

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
        * \fn fe::Entity &entityAt(const unsigned int iter)
        * \brief To get a reference to an entity from its index
        *
        * \param iter The entity index
        * \return The wanted entity (Entity)
        */
        fe::Entity &entityAt(const unsigned int iter);

        /**
        * \fn unsigned int getEntitiesNumber() const
        * \brief To get the total entities number
        *
        * \return The entities number in an unsigned int
        */
        unsigned int getEntitiesNumber() const;

    private:

        std::vector<std::unique_ptr<fe::Entity>> m_entities; /*!< The entities vector */

        fe::MapData &m_mapData; /*!< The reference to the MapData to get useful data */

        fe::Camera &m_camera; /*!< The reference to the map camera */
};
}

#endif // ENTITIESCONTAINER_HPP
