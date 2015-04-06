#ifndef ENTITIESINTERPOSING_H
#define ENTITIESINTERPOSING_H

#include "EntitiesContainer.h"

//This class checks at each frame if an entity of the list has to be drawn on this specific tile coordinates.
class EntitiesInterposing
{
    public:
        //The only constructor
        EntitiesInterposing(EntitiesContainer &container);

        //To interpose entities corresponding to the tile coordinates
        void interpose(Vector3 coord, sf::RenderTarget& target) const;

    private:
        //The entity container, to access all the entities
        EntitiesContainer &m_container;
};

#endif // ENTITIESINTERPOSING_H
