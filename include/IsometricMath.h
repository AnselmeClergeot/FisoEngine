#ifndef ISOMETRICMATH_H
#define ISOMETRICMATH_H

#include "../ExternClasses/Vector2.h"
#include "../ExternClasses/Vector3.h"
#include "MData.h"

//This file offers many functions essentials for the isometric calculations

//To calculate an isometric position from a map-relative tile coordinates
Vector2 toIsometricPosition(const Vector3 coord, const MData &map_data);
//To get the map-relative tile coordinates from a raw screen pixel coordinates
Vector2 getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer, const MData &map_data);
#endif // ISOMETRICMATH_H
