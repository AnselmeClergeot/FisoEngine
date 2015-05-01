/**
 * \file EntitiesInterposing.h
 * \brief Definition of EntitiesInterposing class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * EntitiesInterposing.h defines the EntitiesInterposing class
 *
 */

#ifndef ENTITIESINTERPOSING_H
#define ENTITIESINTERPOSING_H
#include "EntitiesContainer.h"

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
        * \fn EntitiesInterposing(EntitiesContainer &container)
        * \brief The class constructor
        *
        * \param container Reference to the entities container to access the entities
        */
        EntitiesInterposing(EntitiesContainer &container);

        /**
        * \fn void interpose(Vector3 coord, sf::RenderTarget& target) const
        * \brief This function is called at each map drawing to draw each entity of the map
                  at the right moment, before certain tiles and after others.
        *
        * \param coord The drawing tile coordinate
        * \param target The target to draw the entities on. [SPECIFIC TO SFML]
        * \return void
        */
        void interpose(Vector3 coord, sf::RenderTarget& target) const;

    private:
        //The entity container, to access all the entities
        EntitiesContainer &m_container; /* !< Reference to the EntitiesContainer to access the entities*/
};

#endif // ENTITIESINTERPOSING_H
