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

#include "DrawingFuncs.h"

using namespace fe;

bool fe::isVisible(const Vector2 position, const Vector2 elementSize, Camera &camera) {
    return (position.x+elementSize.x + camera.getViewDimensions().x/2-camera.getViewCenter().x >0 &&
            position.y+elementSize.y + camera.getViewDimensions().y/2-camera.getViewCenter().y >0 &&
            position.x + camera.getViewDimensions().x/2-camera.getViewCenter().x < camera.getViewDimensions().x &&
            position.y + camera.getViewDimensions().y/2-camera.getViewCenter().y < camera.getViewDimensions().y);
}
