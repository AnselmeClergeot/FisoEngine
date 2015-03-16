#ifndef TILEGROUPDATA_H
#define TILEGROUPDATA_H

#include <SFML/Graphics.hpp>
#include "../ExternClasses/Matrix3d.h"
#include "MData.h"
#include "IsometricMath.h"

class TileGroupData
{
    public:
        TileGroupData(Matrix3d &config, MData &mapData);

        //Accessors for the loader
        sf::Texture &getTileset();
        std::vector<sf::Sprite> &getTiles();
        Matrix3d &getConfig();
        unsigned int getSize() const;

        //To get a reference to a certain tile sprite
        sf::Sprite &spriteAt(const unsigned int index);

        //To update the global position
        void updatePosition();

        //To set a certain tile position
        void setTilePosition(const Vector3 coord);

        //To update a certain tile appearance from the config
        void updateTile(const unsigned int index);

        //To set a certain tile rect
        void frameTile(const unsigned int index, const Vector2 coord);
    private:
        //The tileset texture
        sf::Texture m_tileset;
        //The vector of tiles
        std::vector<sf::Sprite> m_tiles;
        //Reference to the matrix configuration
        Matrix3d &m_config;
        //Reference to MData to get essential data
        MData &m_mapData;
};

#endif // TILEGROUPDATA_H
