#ifndef ENTITIESINTERFACE_H
#define ENTITIESINTERFACE_H

#include "EntitiesContainer.h"

class EntitiesInterface
{
    public:
        EntitiesInterface(EntitiesContainer &container);

        //To add an entity
        void createEntity();

        //To remove an entity
        void removeEntity(const unsigned int iter);

        //To set the entity dimensions
        void setDimensionsOf(const unsigned int iter, const Vector2 dim);

        void setBaseCoordOf(const unsigned int iter, const Vector2 coord);

        //To update the pixel position
        void updatePixelPositionOf(const unsigned int iter, const Vector2 pos);

        //To set the sprite image path and load it
        void setImagePathOf(const unsigned int iter, const std::string path);

        //To set to draw or not
        void setDrawStateOf(const unsigned int iter, const bool set);

        //To set layer
        void setLayerOf(const unsigned int iter, const unsigned int layer);

    private:
        //Reference to the EntityContainer
        EntitiesContainer &m_container;
};

#endif // ENTITIESINTERFACE_H
