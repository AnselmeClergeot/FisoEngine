#ifndef DRAWINGFUNCS_H
#define DRAWINGFUNCS_H

#include "Vector2.h"
#include "ScreenInfos.h"

//Function to know if an element is visible to the screen
bool isVisible(const Vector2 position, const Vector2 elementSize, ScreenInfos &screenInfos);

#endif // DRAWINGFUNCS_H
