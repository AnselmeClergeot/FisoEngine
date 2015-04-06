#ifndef ENTITIESINTERFACE_H
#define ENTITIESINTERFACE_H

#include "EntitiesContainer.h"

//This class is the interface used by the user to interact with any entity.
class EntitiesInterface
{
    public:
        //The only constructor
        EntitiesInterface(EntitiesContainer &container);

        //To create an entity and add it to the list
        void createEntity();

        //To remove an entity from the entity list
        void removeEntity(const unsigned int iter);

        //To set the dimensions of an entity
        void setDimensionsOf(const unsigned int iter, const Vector2 dim);

        //To set the base coordinates of an entity
        void setBaseCoordOf(const unsigned int iter, const Vector2 coord);

        //To update the position of an entity
        void updatePixelPositionOf(const unsigned int iter, const Vector2 pos);

        //To move an entity
        void move(const unsigned int iter, const Vector2 rate);

        //To set the sprite image path of an entity
        void setImagePathOf(const unsigned int iter, const std::string path);

        //To set the draw state of an entity
        void setDrawStateOf(const unsigned int iter, const bool set);

        //To set layer of an entity
        void setLayerOf(const unsigned int iter, const unsigned int layer);

        //To get the sprite of an entity
        sf::Sprite &getSpriteOf(const unsigned int iter);

        //To get the tile position of an entity
        Vector3 getTilePositionOf(const unsigned int iter);

        //To get the base coord of an entity
        Vector2 getBaseCoordOf(const unsigned int iter);

        //To get the draw state of an entity
        bool getDrawStateOf(const unsigned int iter);

        //To get the dimensions of an entity
        Vector2 getDimensionsOf(const unsigned int iter);

    private:
        //Reference to the EntityContainer to interact with the entities
        EntitiesContainer &m_container;
};

#endif // ENTITIESINTERFACE_H
