#ifndef MDATA_H
#define MDATA_H

#include "../ExternClasses/Matrix3d.h"
#include "../ExternClasses/Vector2.h"
#include <algorithm>

//This class warps all the map data, such as size, tile size, etc.
class MData
{
    public:
        //The default constructor
        MData();

        //To set the map dimensions
        void setSize(const Vector2 size);

        //To set the map position
        void setPosition(const Vector2 position);

        //To move the map position
        void move(const Vector2 rate);

        //To set the tile size
        void setTileSize(const Vector2 size);

        //To set the tile base height
        void setTileBaseHeight(const unsigned int h);

        //To set the invisible tile number
        void setInvisibleTile(const unsigned int tile);

        //To add a translucent tile to the list
        void addTranslucentTile(const unsigned int tile);

        //To get the temporary configuration
        Matrix3d &getTempConf();

        //To get the permanent configuration
        Matrix3d &getPermConf();

        //To get the map dimensions
        Vector2 getSize() const;

        //To get the map position
        Vector2 getPosition() const;

        //To get the tile size
        Vector2 getTileSize() const;

        //To get the tile base height
        unsigned int getTileBaseHeight() const;

        //To get the invisible tile
        unsigned int getInvisibleTile() const;

        //To know if a tile number corresponds to a translucent tile
        bool isTranslucent(const unsigned int tile) const;

    private:
        //The temporary configuration, used for drawing purpose
        Matrix3d m_tempConf;
        //The permanent configuration, used for saving the map for example
        Matrix3d m_permConf;

        //The map dimensions
        Vector2 m_size;
        //The map position
        Vector2 m_position;

        //The tile size
        Vector2 m_tileSize;
        //The tile base height
        unsigned int m_tileBaseHeight;
        //The invisible tile number
        unsigned int m_invisibleTile;
        //The list of translucent tile numbers
        std::vector<unsigned int> m_translucentTiles;
};

#endif // MDATA_H
