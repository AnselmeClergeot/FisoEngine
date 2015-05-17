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
 * \file DynamicShader.hpp
 * \brief Definition of DynamicShader class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * DynamicShader.hpp defines the DynamicShader class
 *
 */

#ifndef DYNAMICSHADER_HPP
#define DYNAMICSHADER_HPP
#include "MapData.hpp"
#include "TileGroup.hpp"
#include "Vector3.hpp"

namespace fe {
/**
 * \class DynamicShader
 * \brief Class that shades the map dynamically
 *
 * This class is charged to dynamically shades the map by acting on the shadows TileGroup.
 */
class DynamicShader
{
    public:

        /**
        * \fn DynamicShader(fe::MapData &mapData, fe::TileGroup &mapTg, fe::TileGroup &shadowsTg)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param mapTg Reference to the map TileGroup to get tiles informations
        * \param shadowsTg Reference to the shadows TileGroup to modify
        */
        DynamicShader(fe::MapData &mapData, fe::TileGroup &mapTg, fe::TileGroup &shadowsTg);

        /**
        * \fn void updateShading(const fe::Vector3 coord)
        * \brief To update the shading of a specific map tile
        *
        * \param coord The tile coordinates
        * \return void
        */
        void updateShading(const fe::Vector3 coord);

        /**
        * \fn void updateShadingOfAll()
        * \brief To update the shading of all the map
        *
        * \return void
        */
        void updateShadingOfAll();

        /**
        * \fn void updateOpacityOfAll()
        * \brief To update the shadows from the tiles opacity of all the map
        *
        * \return void
        */
        void updateOpacityOfAll();

        /**
        * \fn void updateOpacityOfType(const unsigned int type)
        * \brief To update the shadows of a specific tile number, to update shadows opacity
        *
        * \param type The tile type from its number
        * \return void
        */
        void updateOpacityOfType(const unsigned int type);

        /**
        * \fn void updateOpacityOfSpecific(const fe::Vector3 coord)
        * \brief To update the shadows of a specific type, to update shadow opacity
        *
        * \param coord The tile coordinates
        * \return void
        */
        void updateOpacityOfSpecific(const fe::Vector3 coord);

        /**
        * \fn void updateTileFromAnim(const fe::Vector3 tileCoord, const unsigned int animX)
        * \brief To update the shadow of a specific tile to link with the animation state of this tile
        *
        * \param tileCoord The tile coordinates
        * \param animX The animation frame of the tile
        * \return void
        */
        void updateTileFromAnim(const fe::Vector3 tileCoord, const unsigned int animX);

    private:

        /**
        * \fn unsigned int getShadowZ(const fe::Vector3 tileCoord)
        * \brief To get the shadow z coordinate from a specific tile coordinates
        *
        * \param tileCoord The tile coordinates
        * \return The z coordinate of the engendered shadow in an unsigned int
        */
        unsigned int getShadowZ(const fe::Vector3 tileCoord);

        /**
        * \fn bool haveShadowVisible(const fe::Vector3 tileCoord)
        * \brief To know if a tile have a shadow taking in account the depth
        *
        * \param tileCoord The tile coordinates
        * \return True if the tile have a shadow, false otherwise
        */
        bool haveShadowVisible(const fe::Vector3 tileCoord);

        fe::MapData &m_mapData; /*!< The reference to the MapData to get needed data*/

        fe::TileGroup &m_mapTg; /*!< The reference to the map TileGroup to access tile images data*/

        fe::TileGroup &m_shadowsTg; /*!< The reference to the shadows TileGroup to modify*/
};
}

#endif // DYNAMICSHADER_HPP
