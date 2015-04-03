#ifndef TILEGROUPDATA_H
#define TILEGROUPDATA_H

#include <SFML/Graphics.hpp>

#include "../ExternClasses/Matrix3d.h"
#include "MData.h"
#include "IsometricMath.h"

class TileGroupData
{
    public:
        TileGroupData(MData &mapData);

        //Accessors for the loader
        sf::Texture &getTileset();
        std::vector<sf::Sprite> &getTiles();
        unsigned int getTileNumber() const;

        //Set the config from a temporary one
        void setConfiguration(Matrix3d &config);

        //To set a number in config from particular coordinates
        void setTileAt(const Vector3 coord, const unsigned int index);

        //To get a reference to a certain tile sprite
        sf::Sprite &spriteAt(const Vector3 coord);
        sf::Sprite &spriteAt(const unsigned int index);

        //To update the tilegroup global position
        void updateTileGroupPosition();

        //To set a particular tile position
        void setTilePosition(const Vector3 coord);

        //To update a particular tile appearance from the configuration matrix
        void updateTileFromConfig(const unsigned int index);

        //To set a particular tile tileset-frame
        void frameTile(const unsigned int index, const Vector2 coord);

        //To set the opacity of a specific tile
        void setSpecificOpacity(const unsigned int index, const unsigned int opacity);
        //To set a global tile number opacity
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);
        //To set the all tiles same opacity
        void setGroupOpacity(const unsigned int opacity);
        //To apply the tilegroup opacity to all tiles
        void applyGroupOpacity();

        //To get specific tile opacity
        unsigned int getTileOpacity(const unsigned int index) const;
        //To get group opacity
        unsigned int getGroupOpacity() const;

    private:
        //The tileset texture
        sf::Texture m_tileset;
        //The vector of tiles
        std::vector<sf::Sprite> m_tiles;
        //Reference to the matrix configuration
        Matrix3d m_config;
        //Reference to MData to get essential data
        MData &m_mapData;
        //Group opacity
        unsigned int m_opacity;
};

#endif // TILEGROUPDATA_H
