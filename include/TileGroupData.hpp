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
 * \file TileGroupData.hpp
 * \brief Definition of TileGroupData class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupData.hpp defines the TileGroupData class
 *
 */

#ifndef TILEGROUPDATA_HPP
#define TILEGROUPDATA_HPP
#include <SFML/Graphics.hpp>
#include "MapData.hpp"
#include "Camera.hpp"
#include "Matrix3d.hpp"
#include "IsometricMath.hpp"
#include "DrawingFuncs.hpp"


namespace fe {
    class TileGroupColors;
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
        * \fn TileGroupData(fe::MapData &mapData, fe::Camera &camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param camera Reference to the map camera
        */
        TileGroupData(fe::MapData &mapData, fe::Camera &camera);

        /**
        * \fn sf::Texture &getTileset()
        * \brief To get the tileset texture [SPECIFIC TO SFML]
        *
        * \return The tileset texture
        */
        sf::Texture &getTileset();

        /**
        * \fn fe::Matrix3d<sf::Sprite> &getTiles()
        * \brief To get the list of tiles [SPECIFIC TO SFML]
        *
        * \return The vector of sprites
        */
        fe::Matrix3d<sf::Sprite> &getTiles();

        /**
        * \fn unsigned int getTileNumber() const
        * \brief To get the total tile number of the TileGroup
        *
        * \return The total number of tiles
        */
        unsigned int getTileNumber() const;

        /**
        * \fn void configureWith(fe::Matrix3d<unsigned int> &config)
        * \brief To set the TileGroup configuration Matrix3d
        *
        * \param config The reference to the TileGroup configuration Matrix3d
        * \return void
        */
        void configureWith(fe::Matrix3d<unsigned int> &config);

        /**
        * \fn void setTileAt(const fe::Vector3 coord, const unsigned int index)
        * \brief To set the tile at 3D coordinates with a tileset coordinate
        *
        * \param coord The tile coordinates
        * \param index The tileset Y index
        * \return void
        */
        void setTileAt(const fe::Vector3 coord, const unsigned int index);

        /**
        * \fn sf::Sprite &spriteAt(const fe::Vector3 coord)
        * \brief To get a reference to a specific tile sprite from tile 3D coordinates[SPECIFIC TO SFML]
        *
        * \param coord The tile coordinates
        * \return The reference to the asked tile sprite
        */
        sf::Sprite &spriteAt(const fe::Vector3 coord);

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
        * \fn void setTilePosition(const fe::Vector3 coord)
        * \brief To calculate the position of a specific tile of the TileGrouo
        *
        * \param coord The coordinates of the tile to place
        * \return void
        */
        void setTilePosition(const fe::Vector3 coord);

        /**
        * \fn void frameTile(const fe::Vector3 coord, const fe::Vector2 tilesetCoord)
        * \brief To frame a specific tile with 2D tileset coordinates
        *
        * \param coord The 3D tile coordinates
        * \param tilesetCoord The tileset coordinates in tiles
        * \return void
        */
        void frameTile(const fe::Vector3 coord, const fe::Vector2 tilesetCoord);

        /**
        * \fn void setTileTilesetX(const fe::Vector3 coord, fe::Vector2 tilesetCoord)
        * \brief To set the X tileset coordinate of a specific tile from its coordinates
        *
        * \param coord The 3D coordinate of the tile
        * \param tilesetCoord The tileset coordinates
        * \return void
        */
        void setTileTilesetX(const fe::Vector3 coord, fe::Vector2 tilesetCoord);

    private:

        sf::Texture m_tileset; /*!< The tileset texture [SPECIFIC TO SFML] */

        fe::Matrix3d<sf::Sprite> m_tiles;  /*!<  The Matrix3d of tile sprites [SPECIFIC TO SFML]*/

        fe::MapData &m_mapData;  /*!< Reference to the MapData to get useful map data*/

        fe::Camera &m_camera; /*!< Reference to the map camera */
};
}

#endif // TILEGROUPDATA_HPP
