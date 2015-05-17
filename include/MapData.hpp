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
 * \file MapData.hpp
 * \brief Definition of MapData class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * MapData.hpp defines the MapData class
 *
 */

#ifndef MAPDATA_HPP
#define MAPDATA_HPP
#include "Matrix3d.hpp"
#include "Vector2.hpp"
#include <algorithm>

namespace fe {
/**
 * \class MapData
 * \brief This class is the container of all map data
 *
 * MapData is used by the engine to store the map data such as size, tile dimensions, and the configurations.
 */
class MapData
{
    public:

        /**
        * \fn MapData()
        * \brief The class constructor
        *
        */
        MapData();

        /**
        * \fn void setSize(const fe::Vector2 size)
        * \brief To set the map dimensions
        *
        * \param size The width and the layer number of the map
        * \return void
        */
        void setSize(const fe::Vector2 size);

        /**
        * \fn void setPosition(const fe::Vector2 position)
        * \brief To set the map position
        *
        * \param position The map position in pixels
        * \return void
        */
        void setPosition(const fe::Vector2 position);

        /**
        * \fn void move(const fe::Vector2 rate)
        * \brief To move the map position relatively to its position
        *
        * \param rate The move rate in pixels
        * \return void
        */
        void move(const fe::Vector2 rate);

        /**
        * \fn void setTileSize(const fe::Vector2 size)
        * \brief To set the map tiles dimensions
        *
        * \param size The tile dimensions in pixels
        * \return void
        */
        void setTileSize(const fe::Vector2 size);

        /**
        * \fn void setTileBaseHeight(const unsigned int h)
        * \brief To set the map tiles base height
        *
        * \param h The tile base height in pixel
        * \return void
        */
        void setTileBaseHeight(const unsigned int h);

        /**
        * \fn void setInvisibleTile(const unsigned int tile)
        * \brief To set the map invisible tile number
        *
        * \param tile The invisible tile number
        * \return void
        */
        void setInvisibleTile(const unsigned int tile);

        /**
        * \fn void addTranslucentTile(const unsigned int tile)
        * \brief To add a translucent tile to the list from its number
        *
        * \param tile The translucent tile number
        * \return void
        */
        void addTranslucentTile(const unsigned int tile);

        /**
        * \fn void removeTranslucentTile(const unsigned int tile)
        * \brief To remove a translucent tile from the list from its number
        *
        * \param tile The translucent tile number
        * \return void
        */
        void removeTranslucentTile(const unsigned int tile);

        /**
        * \fn fe::Matrix3d<unsigned int> &getTempConf()
        * \brief To get a reference to the temporary configuration of the map
        *
        * \return The temporary configuration
        */
        fe::Matrix3d<unsigned int> &getTempConf();

        /**
        * \fn fe::Matrix3d<unsigned int> &getPermConf()
        * \brief To get a reference to the permanent configuration of the map
        *
        * \return The permanent configuration
        */
        fe::Matrix3d<unsigned int> &getPermConf();

        /**
        * \fn fe::Vector2 getSize() const
        * \brief To get the map size
        *
        * \return The width and the layer number of the map
        */
        fe::Vector2 getSize() const;

        /**
        * \fn fe::Vector2 getPosition() const
        * \brief To get the map position
        *
        * \return The map position in pixels
        */
        fe::Vector2 getPosition() const;

        /**
        * \fn fe::Vector2 getTileSize() const
        * \brief To get the map tiles dimensions
        *
        * \return The map tiles dimensions in pixels
        */
        fe::Vector2 getTileSize() const;

        /**
        * \fn unsigned int getTileBaseHeight() const
        * \brief To get the map tiles base height
        *
        * \return The map tiles base height in pixel
        */
        unsigned int getTileBaseHeight() const;

        /**
        * \fn unsigned int getInvisibleTile() const
        * \brief To get the map invisible tile number
        *
        * \return The map invisible tile number
        */
        unsigned int getInvisibleTile() const;

        /**
        * \fn bool isTranslucent(const unsigned int tile) const
        * \brief To know if a tile is considered as translucent, from its number
        *
        * \return True if the tile is translucent, false otherwise
        */
        bool isTranslucent(const unsigned int tile) const;

    private:

        fe::Matrix3d<unsigned int> m_tempConf; /*!< The temporary Map configuration,
                                                used for map appearance purpose (shadows, etc.)*/

        fe::Matrix3d<unsigned int> m_permConf; /*!< The permanent Map configuration,
                                                the one used for saving and loading the map */

        fe::Vector2 m_size; /*!< The map dimensions */

        fe::Vector2 m_position; /*!< The map position */

        fe::Vector2 m_tileSize; /*!< The map tiles dimensions */

        unsigned int m_tileBaseHeight; /*!< The map tiles base height */

        unsigned int m_invisibleTile; /*!< The map invisible tile number */

        std::vector<unsigned int> m_translucentTiles; /*!< The list of translucent tiles number */
};
}

#endif // MAPDATA_HPP
