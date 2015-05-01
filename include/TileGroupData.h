/**
 * \file TileGroupData.h
 * \brief Definition of TileGroupData class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupData.h defines the TileGroupData class
 *
 */

#ifndef TILEGROUPDATA_H
#define TILEGROUPDATA_H
#include <SFML/Graphics.hpp>
#include "MapData.h"
#include "Matrix3d.h"
#include "IsometricMath.h"

/**
 * \class TileGroupData
 * \brief This class stores all the TileGroup stuff
 *
 * TileGroupData class is the data container of TileGroup. It contains all data from configuration to tile images, etc.
 * The class is also charged of setting tile positions, framing tiles and handling their opacities.
 */
class TileGroupData
{
    public:

        /**
        * \fn TileGroupData(MapData &mapData)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        */
        TileGroupData(MapData &mapData);

        /**
        * \fn sf::Texture &getTileset()
        * \brief To get the tileset texture [SPECIFIC TO SFML]
        *
        * \return The tileset texture
        */
        sf::Texture &getTileset();

        /**
        * \fn std::vector<sf::Sprite> &getTiles()
        * \brief To get the list of tiles [SPECIFIC TO SFML]
        *
        * \return The vector of sprites
        */
        std::vector<sf::Sprite> &getTiles();

        /**
        * \fn unsigned int getTileNumber() const
        * \brief To get the total tile number of the TileGroup
        *
        * \return The total number of tiles
        */
        unsigned int getTileNumber() const;

        /**
        * \fn void setConfiguration(Matrix3d<unsigned int> &config)
        * \brief To set the TileGroup configuration Matrix3d
        *
        * \param config The reference to the TileGroup configuration Matrix3d
        * \return void
        */
        void setConfiguration(Matrix3d<unsigned int> &config);

        /**
        * \fn void setTileAt(const Vector3 coord, const unsigned int index)
        * \brief To set the tile at 3D coordinates with a tileset coordinate
        *
        * \param coord The tile coordinates
        * \param index The tileset Y index
        * \return void
        */
        void setTileAt(const Vector3 coord, const unsigned int index);

        /**
        * \fn sf::Sprite &spriteAt(const Vector3 coord)
        * \brief To get a reference to a specific tile sprite from tile 3D coordinates[SPECIFIC TO SFML]
        *
        * \param coord The tile coordinates
        * \return The reference to the asked tile sprite
        */
        sf::Sprite &spriteAt(const Vector3 coord);

        /**
        * \fn sf::Sprite &spriteAt(const unsigned int index)
        * \brief To get a reference to a specific tile sprite from tile 1D coordinate [SPECIFIC TO SFML]
        *
        * \param index The tile 1D coordinate
        * \return The reference to the asked tile sprite
        */
        sf::Sprite &spriteAt(const unsigned int index);

        /**
        * \fn void updatePosition()
        * \brief To update the TileGroup position from the MapData position
        *
        * \return void
        */
        void updatePosition();

        /**
        * \fn void setTilePosition(const Vector3 coord)
        * \brief To calculate the position of a specific tile of the TileGrouo
        *
        * \param coord The coordinates of the tile to place
        * \return void
        */
        void setTilePosition(const Vector3 coord);

        /**
        * \fn void updateTileFromConfig(const unsigned int index)
        * \brief To update a specific tile appearance from the TileGroup configuration
        *
        * \param index The 1D tile coordinate
        * \return void
        */
        void updateTileFromConfig(const unsigned int index);

        /**
        * \fn void frameTile(const unsigned int index, const Vector2 coord)
        * \brief To frame a specific tile with 2D tileset coordinates
        *
        * \param index The 1D tile coordinate
        * \param coord The tileset coordinates in tiles
        * \return void
        */
        void frameTile(const unsigned int index, const Vector2 coord);

        /**
        * \fn void setTileOpacity(const Vector3 coord, const unsigned int opacity)
        * \brief To set the opacity of a specific tile from 1D index
        *
        * \param coord The tile 3D coordinates
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setTileOpacity(const Vector3 coord, const unsigned int opacity);

        /**
        * \fn void setTypeOpacity(const unsigned int tile, const unsigned int opacity)
        * \brief To set the opacity of all the tiles of the same type
        *
        * \param tile The tile number
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);

        /**
        * \fn void setGroupOpacity(const unsigned int opacity)
        * \brief To set the opacity of all the tiles of the TileGroup
        *
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setGroupOpacity(const unsigned int opacity);

        /**
        * \fn void applyGroupOpacity();
        * \brief To apply the entire TileGroup opacity to each tile
        *
        * \return void
        */
        void applyGroupOpacity();

        /**
        * \fn unsigned int getTileOpacity(const Vector3 coord) const
        * \brief To get the opacity of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return The opacity value of the tile, from 0 to 255
        */
        unsigned int getTileOpacity(const Vector3 coord) const;

        /**
        * \fn unsigned int getGroupOpacity() const
        * \brief To get the opacity of the entire TileGroup if set
        *
        * \return The opacity value of the entire TileGroup, from 0 to 255
        */
        unsigned int getGroupOpacity() const;

        /**
        * \fn void resetOpacityOf(const Vector3 coord)
        * \brief To reset the opacity of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return void
        */
        void resetOpacityOf(const Vector3 coord);

        /**
        * \fn void setTileTilesetX(const Vector3 coord, const unsigned int x)
        * \brief To set the X tileset coordinate of a specific tile from its coordinates
        *
        * \param coord The 3D coordinate of the tile
        * \param x The x tileset coordinate of the tile
        * \return void
        */
        void setTileTilesetX(const Vector3 coord, unsigned int x);

    private:

        sf::Texture m_tileset; /*!< The tileset texture [SPECIFIC TO SFML] */

        std::vector<sf::Sprite> m_tiles;  /*!<  The vector of tile sprites [SPECIFIC TO SFML]*/

        Matrix3d<unsigned int> m_config;  /*!< The TileGroup configuration*/

        MapData &m_mapData;  /*!< Reference to the MapData to get useful map data*/

        unsigned int m_opacity;  /*!< The TileGroup opacity set*/
};

#endif // TILEGROUPDATA_H
