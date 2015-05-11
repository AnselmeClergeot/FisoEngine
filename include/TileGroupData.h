/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
#include "Camera.h"
#include "Matrix3d.h"
#include "IsometricMath.h"
#include "DrawingFuncs.h"

namespace fe {
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
        * \fn TileGroupData(MapData &mapData, Camera &camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param camera Reference to the map camera
        */
        TileGroupData(MapData &mapData, Camera &camera);

        /**
        * \fn sf::Texture &getTileset()
        * \brief To get the tileset texture [SPECIFIC TO SFML]
        *
        * \return The tileset texture
        */
        sf::Texture &getTileset();

        /**
        * \fn Matrix3d<sf::Sprite> &getTiles()
        * \brief To get the list of tiles [SPECIFIC TO SFML]
        *
        * \return The vector of sprites
        */
        Matrix3d<sf::Sprite> &getTiles();

        /**
        * \fn Matrix3d<unsigned int> &getOpacities()
        * \brief To get a reference to the tile opacities values
        *
        * \return The Matrix3d of opacities values
        */
        Matrix3d<unsigned int> &getOpacities();

        /**
        * \fn unsigned int getTileNumber() const
        * \brief To get the total tile number of the TileGroup
        *
        * \return The total number of tiles
        */
        unsigned int getTileNumber() const;

        /**
        * \fn void configureWith(Matrix3d<unsigned int> &config)
        * \brief To set the TileGroup configuration Matrix3d
        *
        * \param config The reference to the TileGroup configuration Matrix3d
        * \return void
        */
        void configureWith(Matrix3d<unsigned int> &config);

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
        * \fn void frameTile(const Vector3 coord, const Vector2 tilesetCoord)
        * \brief To frame a specific tile with 2D tileset coordinates
        *
        * \param coord The 3D tile coordinates
        * \param tilesetCoord The tileset coordinates in tiles
        * \return void
        */
        void frameTile(const Vector3 coord, const Vector2 tilesetCoord);

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
        * \fn void applyOpacityOn(const Vector3 coord)
        * \brief To apply the opacity value of the Matrix3d on a tile
        *
        * \param coord The tile 3D coordinates
        * \return void
        */
        void applyOpacityOn(const Vector3 coord);

        /**
        * \fn void checkForOpacity(const Vector3 coord, const unsigned int tile)
        * \brief To eventually set the opacity of the tile which was set
        *
        * \param coord The tile 3D coordinates
        * \param tile The tile number
        * \return void
        */
        void checkForOpacity(const Vector3 coord, const unsigned int tile);

        /**
        * \fn void reloadOpacities()
        * \brief To reload the opacities from the types list
        *
        * \return void
        */
        void reloadOpacities();

        /**
        * \fn unsigned int getTileOpacity(const Vector3 coord)
        * \brief To get the opacity of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return The opacity value of the tile, from 0 to 255
        */
        unsigned int getTileOpacity(const Vector3 coord);

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
        * \fn void setTileTilesetX(const Vector3 coord, Vector2 tilesetCoord)
        * \brief To set the X tileset coordinate of a specific tile from its coordinates
        *
        * \param coord The 3D coordinate of the tile
        * \param tilesetCoord The tileset coordinates
        * \return void
        */
        void setTileTilesetX(const Vector3 coord, Vector2 tilesetCoord);

        /**
        * \fn unsigned int getOpacityOfType(const unsigned int type) const
        * \brief To get the opacity of a specific tile type
        *
        * \param type The tile type from its number
        * \return void
        */
        unsigned int getOpacityOfType(const unsigned int type) const;

    private:

        sf::Texture m_tileset; /*!< The tileset texture [SPECIFIC TO SFML] */

        Matrix3d<sf::Sprite> m_tiles;  /*!<  The Matrix3d of tile sprites [SPECIFIC TO SFML]*/

        MapData &m_mapData;  /*!< Reference to the MapData to get useful map data*/

        Camera &m_camera; /*!< Reference to the map camera */

        Matrix3d<unsigned int> m_tilesOpacities; /*!< The Matrix3d of tiles opacities values*/

        std::vector<Vector2> m_typesOpacities; /*!< The tile types opacities values list */

        unsigned int m_opacity; /*!< The global opacity (if set) */
};
}

#endif // TILEGROUPDATA_H
