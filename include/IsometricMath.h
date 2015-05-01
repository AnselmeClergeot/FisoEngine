/**
 * \file IsometricMath.h
 * \brief Isometric functions
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * IsometricMath.h offers useful isometric functions/calculations
 *
 */

#ifndef ISOMETRICMATH_H
#define ISOMETRICMATH_H
#include "Vector2.h"
#include "Vector3.h"
#include "MapData.h"

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
* \fn Vector2 getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer, const MapData &map_data)
* \brief To get the map-coordinates pointed by 2D screen coordinates
*
* \param pixels The screen coordinates
* \param layer The layer to base on for calculations
* \param map_data The reference to the MapData to get useful data
* \return The map tile coordinates
*/
Vector2 getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer, const MapData &map_data);

#endif // ISOMETRICMATH_H
