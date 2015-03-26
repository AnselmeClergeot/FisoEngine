#ifndef MDATA_H
#define MDATA_H

#include "../ExternClasses/Matrix3d.h"
#include "../ExternClasses/Vector2.h"
#include <algorithm>

//This class is the map that contains all the map data, size, etc
class MData
{
    public:
        MData();

        //Setters
        void setSize(const Vector2 size);
        void setPosition(const Vector2 position);
        void move(const Vector2 rate);

        void setTileSize(const Vector2 size);
        void setTileBaseHeight(const unsigned int h);
        void setInvisibleTile(const unsigned int tile);
        void addTranslucentTile(const unsigned int tile);

        //Accessors
        Matrix3d &getTempConf();
        Matrix3d &getPermConf();

        Vector2 getSize() const;
        Vector2 getPosition() const;

        Vector2 getTileSize() const;
        unsigned int getTileBaseHeight() const;
        unsigned int getInvisibleTile() const;
        bool isTranslucent(const unsigned int tile) const;

    private:
        //Tile-configurations classes
        Matrix3d m_tempConf;
        Matrix3d m_permConf;

        //Map global data
        Vector2 m_size;
        Vector2 m_position;

        //Tile global data
        Vector2 m_tileSize;
        unsigned int m_tileBaseHeight;
        unsigned int m_invisibleTile;
        std::vector<unsigned int> m_translucentTiles;
};

#endif // MDATA_H
