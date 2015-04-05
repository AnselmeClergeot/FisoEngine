#ifndef ENTITIESINTERPOSING_H
#define ENTITIESINTERPOSING_H

#include "EntitiesContainer.h"

class EntitiesInterposing
{
    public:
        EntitiesInterposing(EntitiesContainer &container);
        void interpose(Vector3 coord, sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        EntitiesContainer &m_container;
};

#endif // ENTITIESINTERPOSING_H
