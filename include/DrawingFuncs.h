/**
 * \file DrawingFuncs.h
 * \brief Drawing functions
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * DrawingFuncs.h offers functions linked with drawing things on screen
 *
 */

#ifndef DRAWINGFUNCS_H
#define DRAWINGFUNCS_H
#include "Vector2.h"
#include "ScreenInfos.h"

/**
* \fn bool isVisible(const Vector2 position, const Vector2 elementSize, ScreenInfos &screenInfos)
* \brief To know if an element is visible on the screen
*
* \param position Position of the element
* \param elementSize Dimensions of the element
* \param screenInfos Reference to the map screenInfos to get needed data like window size
* \return true if visible or false if not visible
*/
bool isVisible(const Vector2 position, const Vector2 elementSize, ScreenInfos &screenInfos);

#endif // DRAWINGFUNCS_H
