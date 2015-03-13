#ifndef MDATA_H
#define MDATA_H

#include "../ExternClasses/Matrix3d.h"
#include "../ExternClasses/Vector2.h"

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

        //Accessors
        Matrix3d &getTempConf();
        Matrix3d &getPermConf();

        Vector2 getSize() const;
        Vector2 getPosition() const;

        Vector2 getTileSize() const;
        unsigned int getTileBaseHeight() const;

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
};

#endif // MDATA_H
