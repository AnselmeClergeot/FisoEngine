#include "EntitiesInterposing.h"

EntitiesInterposing::EntitiesInterposing(EntitiesContainer &container) : m_container(container)
{}

void EntitiesInterposing::interpose(Vector3 coord, sf::RenderTarget& target) const {
    for(int i(0); i<m_container.getEntitiesNumber(); i++)
        if(m_container.entityAt(i).getTilePosition()==coord && m_container.entityAt(i).getDrawingState())
            m_container.entityAt(i).draw(target);
}
