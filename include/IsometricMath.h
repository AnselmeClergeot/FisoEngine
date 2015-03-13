#ifndef ISOMETRICMATH_H
#define ISOMETRICMATH_H

#include "../ExternClasses/Vector2.h"
#include "../ExternClasses/Vector3.h"
#include "MData.h"

//This file offers many functions essentials for the isometric calculations
Vector2 toIsometricPosition(const Vector3 coord, const MData &map_data);
#endif // ISOMETRICMATH_H
