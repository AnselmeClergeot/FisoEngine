#ifndef MDRAWER_H
#define MDRAWER_H

#include <SFML/Graphics.hpp>

#include "MData.h"
#include "IsometricMath.h"

//This class is charged of drawing the map and all related events. It is inherited from sf::Drawable.
class MDrawer : public sf::Drawable
{
    public:
        MDrawer(MData &data);

        //To resize tile list
        void resizeTileList(const unsigned int s);

        //Getting sprite texture
        sf::Texture &getTexture();

        //To get a reference of the sprite at iter i
        sf::Sprite &tileAt(const unsigned int i);

        //Update tile rect from the temp matrix
        void updateAt(const unsigned int i);

        //Update the entire map position
        void updatePosition();

        //To set a specific tile position
        void setTilePosition(const Vector3 coord);

        //To set the rect of a tile to modify its appearance
        void frameTile(const Vector2 coord, const unsigned int i);

        //Method to draw all the tiles
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //Method to know if a specific tile is visible on screen
        bool tileIsVisible(const Vector3 coord, sf::RenderTarget &target) const;

    private:
        //Screen-draw data
        sf::Texture m_texture;
        std::vector<sf::Sprite> m_tileSprites;


        //Reference to classes for getting essential data
        MData &m_data;
};

#endif // MDRAWER_H
