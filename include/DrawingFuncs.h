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
#include "Camera.h"

namespace fe {

/**
* \fn bool isVisible(const fe::Vector2 position, const fe::Vector2 elementSize, fe::Camera &camera)
* \brief To know if an element is visible on the screen
*
* \param position Position of the element
* \param elementSize Dimensions of the element
* \param camera Reference to the map camera
* \return true if visible or false if not visible
*/
bool isVisible(const fe::Vector2 position, const fe::Vector2 elementSize, fe::Camera &camera);

}

#endif // DRAWINGFUNCS_H
