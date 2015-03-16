#ifndef MAP_H
#define MAP_H

#include "MData.h"
#include "MDataLoader.h"

#include "TileGroup.h"

#include <SFML/Graphics.hpp>

//This class is the user interface
class Map : public sf::Drawable
{
    public:
        Map();

        //Method to start map "creation" or save it
        void init();
        void save();

        //All these methods are indirect setters
        void addLayerFile(const std::string path);
        void setTileset(const std::string path);
        void setTileSize(const Vector2 size);
        void setTileSize(const unsigned int w, const unsigned int h);
        void setTileBaseHeight(const unsigned int h);

        //To set a tile at specific world coordinate
        void setTileAt(const Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw);
        void setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                       bool modifConf, bool modifDraw);

        //Positioning methods
        void setPosition(const Vector2 pos);
        void setPosition(const unsigned int x, const unsigned int y);

        void move(const Vector2 rate);
        void move(const unsigned int rx, const unsigned int ry);

        //Draw method
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //Accessors useful for user
        Vector3 getDimensions() const;
        Vector2 getPosition() const;
        Vector2 getTileSize() const;
        unsigned int getTileBaseHeight() const;
        unsigned int getTileAt(const Vector3 coord);
        unsigned int getTileAt(const unsigned int x, const unsigned int y, const unsigned int z);

    private:
        //Map data loading and container
        MData m_data;
        MDataLoader m_dataLoader;
        //The map TileGroup
        TileGroup m_tileGroup;

};

#endif // MAP_H
