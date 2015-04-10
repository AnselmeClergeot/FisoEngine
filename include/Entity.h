#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "../ExternClasses/Vector2.h"
#include "../ExternClasses/Vector3.h"

#include "RunEnvironment.h"
#include "MData.h"

//Entity is used for interposing graphical elements in the map.
class Entity
{
    friend class EntitiesInterposing;
    public:
        //The only constructor
        Entity(MData &mapData, RunEnvironment &environment);

        //To set the entity dimensions
        void setDimensions(const Vector2 dim);
        //To set the entity dimensions
        void setDimensions(const unsigned int w, const unsigned int h);

        //To set the base coord
        void setBaseCoord(const Vector2 coord);

        //To set the base coord
        void setBaseCoord(const unsigned int x, const unsigned int y);

        //To move the entity
        void move(const Vector2 rate);

        //To move the entity
        void move(const unsigned int x, const unsigned int y);

        //To set the entity image path and load it
        void setImagePath(const std::string path);

        //To set to draw or not
        void setDrawState(const bool set);

        //To set the layer on which the entity is on
        void setLayer(const unsigned int layer);

        //Get the tile position of this entity
        Vector3 getTilePosition() const;

        //To get the base coord
        Vector2 getBaseCoord() const;

        //To get the dimensions of the entity
        Vector2 getDimensions() const;

        //To get a reference to the sprite
        sf::Sprite &getSprite();

        //To get the drawing state
        bool getDrawingState() const;

        //To update the entity position
        void setPixelPosition(const Vector2 pos);

        //To update the entity position
        void setPixelPosition(const unsigned int x, const unsigned int y);

        //To calculate the tile position from the pixel position
        void calculateTilePosition();

    private:

        //To draw this entity
        void draw(sf::RenderTarget& target) const;

        //The corresponding tile position
        Vector3 m_tilePosition;
        //The entity screen position
        Vector2 m_pixelPosition;
        //The entity dimensions
        Vector2 m_dimensions;
        //The base coord of the entity
        Vector2 m_baseCoord;
        //The entity texture;
        sf::Texture m_texture;
        //The entity image
        sf::Sprite m_sprite;
        //If the entity has to be drawn
        bool m_drawState;
        //Pointer to the MData
        MData *m_mapData;
        //Pointer to RunEnvironment
        RunEnvironment *m_environment;
};

#endif // ENTITY_H
