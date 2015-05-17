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
 * \file IsometricMath.hpp
 * \brief Isometric functions
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * IsometricMath.hpp offers useful isometric functions/calculations
 *
 */

#ifndef ISOMETRICMATH_HPP
#define ISOMETRICMATH_HPP
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "MapData.hpp"
#include "Camera.hpp"

namespace fe {

/**
* \fn Vector2 toIsometricPosition(const Vector3 coord, const MapData &map_data)
* \brief To get the tile screen position from its map-coordinates
*
* \param coord The tile map-coordinates
* \param map_data The reference to the MapData to get useful data
* \return The screen position of the tile
*/
Vector2 toIsometricPosition(const Vector3 coord, const MapData &map_data);

/**
* \fn fe::Vector2 getTileCoordAtPixels(const fe::Vector2 pixels,
                             const unsigned int layer,
                             const fe::MapData &map_data,
                             const fe::Camera *camera = 0)
* \brief To get the map-coordinates pointed by 2D screen coordinates
*
* \param pixels The screen coordinates
* \param layer The layer to base on for calculations
* \param map_data The reference to the MapData to get useful data
* \param camera The pointer to the map Camera
* \return The map tile coordinates
*/
fe::Vector2 getTileCoordAtPixels(const fe::Vector2 pixels,
                             const unsigned int layer,
                             const fe::MapData &map_data,
                             const fe::Camera *camera = 0);

}

#endif // ISOMETRICMATH_HPP
