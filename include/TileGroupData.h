#ifndef TILEGROUPDATA_H
#define TILEGROUPDATA_H

#include <SFML/Graphics.hpp>

#include "MapData.h"
#include "Matrix3d.h"
#include "IsometricMath.h"

//This class warps the TileGroupData such as tile list, texture, etc.
class TileGroupData
{
    public:
        //The only constructor
        TileGroupData(MapData &mapData);

        //To get the tileset texture, for the loader
        sf::Texture &getTileset();

        //To get the tile list, for loader
        std::vector<sf::Sprite> &getTiles();

        //To get the total tile number
        unsigned int getTileNumber() const;

        //Set the tilegroup tile-configuration
        void setConfiguration(Matrix3d &config);

        //To set a specific tile of the tilegroup
        void setTileAt(const Vector3 coord, const unsigned int index);

        //To get a reference to a particular tile sprite from 3D coordinates
        sf::Sprite &spriteAt(const Vector3 coord);

        //To get a reference to a particular tile sprite from global index
        sf::Sprite &spriteAt(const unsigned int index);

        //To update the tilegroup position
        void updateTileGroupPosition();

        //To set a specific tile position
        void setTilePosition(const Vector3 coord);

        //To update a tile appearance from the configuration matrix
        void updateTileFromConfig(const unsigned int index);

        //To set the tileset frame of a particular tile
        void frameTile(const unsigned int index, const Vector2 coord);

        //To set the opacity of a specific tile
        void setSpecificOpacity(const unsigned int index, const unsigned int opacity);

        //To set the opacity of all the tiles of same type
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);

        //To set the opacity of all the tiles
        void setGroupOpacity(const unsigned int opacity);

        //To apply the tilegroup opacity to all the tiles
        void applyGroupOpacity();

        //To get specific tile opacity
        unsigned int getTileOpacity(const unsigned int index) const;

        //To get the tilegroup opacity
        unsigned int getGroupOpacity() const;

        //To reset a tile opacity to 255 value
        void resetOpacity(const Vector3 coord);

        //To set the tile X spritesheet coordinate
        void setTileSpritesheetX(const unsigned int iter, unsigned int x);

    private:
        //The tileset texture
        sf::Texture m_tileset;
        //The list of tiles (sprites)
        std::vector<sf::Sprite> m_tiles;
        //The tilegroup configuration
        Matrix3d m_config;
        //Reference to MData to get needed informations
        MapData &m_mapData;
        //The tilegroup opacity
        unsigned int m_opacity;
};

#endif // TILEGROUPDATA_H
