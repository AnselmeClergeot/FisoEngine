#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "../ExternClasses/Vector2.h"
#include "../ExternClasses/Vector3.h"

#include "MData.h"

class Entity
{
    public:
        Entity(MData &mapData);
        //To know if a file exists
        bool fileExists(const std::string path);

        //To set the entity dimensions
        void setDimensions(const Vector2 dim);

        //To set the base coord
        void setBaseCoord(const Vector2 coord);

        //To update the pixel position
        void updatePixelPosition(const Vector2 pos);

        //To set the sprite image path and load it
        void setImagePath(const std::string path);

        //To draw this entity
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //To know if this entity is visible
        bool isVisible(sf::RenderTarget &target) const;

        //To set to draw or not
        void setDrawState(const bool set);

        //To calculate the tile position from the pixel position
        void calculateTilePosition();

        //To set the layer
        void setLayer(const unsigned int layer);

    private:
        //The corresponding tile position
        Vector3 m_tilePosition;
        //The pixel position
        Vector2 m_pixelPosition;
        //The entity dimensions
        Vector2 m_dimensions;
        //The base coord of the entity
        Vector2 m_baseCoord;
        //The entity image
        sf::Sprite m_sprite;
        //The entity texture;
        sf::Texture m_texture;
        //If the entity has to be drawn
        bool m_drawState;
        //Reference to the MData
        MData *m_mapData;
};

#endif // ENTITY_H
