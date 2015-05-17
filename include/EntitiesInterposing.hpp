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
 * \file EntitiesInterposing.hpp
 * \brief Definition of EntitiesInterposing class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * EntitiesInterposing.hpp defines the EntitiesInterposing class
 *
 */

#ifndef ENTITIESINTERPOSING_HPP
#define ENTITIESINTERPOSING_HPP
#include "EntitiesContainer.hpp"

namespace fe {
/**
 * \class EntitiesInterposing
 * \brief Class that interposes the entities into the map tiles
 *
 * This class is charged to interposes the user entities between the map tiles of the TileGroup.
 */
class EntitiesInterposing
{
    public:
        /**
        * \fn EntitiesInterposing(fe::EntitiesContainer &container)
        * \brief The class constructor
        *
        * \param container Reference to the entities container to access the entities
        */
        EntitiesInterposing(fe::EntitiesContainer &container);

        /**
        * \fn void interpose(fe::Vector3 coord, sf::RenderTarget& target) const
        * \brief This function is called at each map drawing to draw each entity of the map
                  at the right moment, before certain tiles and after others.
        *
        * \param coord The drawing tile coordinate
        * \param target The target to draw the entities on. [SPECIFIC TO SFML]
        * \return void
        */
        void interpose(fe::Vector3 coord, sf::RenderTarget& target) const;

    private:
        //The entity container, to access all the entities
        fe::EntitiesContainer &m_container; /* !< Reference to the EntitiesContainer to access the entities*/
};
}

#endif // ENTITIESINTERPOSING_HPP
