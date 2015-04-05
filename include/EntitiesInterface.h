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

        //To move an entity
        void move(const unsigned int iter, const Vector2 rate);

        //To set the sprite image path and load it
        void setImagePathOf(const unsigned int iter, const std::string path);

        //To set to draw or not
        void setDrawStateOf(const unsigned int iter, const bool set);

        //To set layer
        void setLayerOf(const unsigned int iter, const unsigned int layer);

        //To get the sprite of a specific object
        sf::Sprite &getSpriteOf(const unsigned int iter);

        //To get the tile position of an entity
        Vector3 getTilePositionOf(const unsigned int iter);

        //To get the base coord of a specific entity
        Vector2 getBaseCoordOf(const unsigned int iter);

        //To get the draw state of a specific entity
        bool getDrawStateOf(const unsigned int iter);

        //To get the dimensions of a specific entity
        Vector2 getDimensionsOf(const unsigned int iter);

    private:
        //Reference to the EntityContainer
        EntitiesContainer &m_container;
};

#endif // ENTITIESINTERFACE_H
