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

#include "Camera.h"

Camera::Camera() : m_viewDimensions(1980, 1080)
{ }

Camera::Camera(const unsigned int viewW, const unsigned int viewH) : m_viewDimensions(viewW, viewH)
{ }

void Camera::setViewDimensions(const Vector2 dim) {
    m_viewDimensions = dim;
}

void Camera::setViewDimensions(const unsigned int w, const unsigned int h) {
    setViewDimensions(Vector2(w, h));
}

Vector2 Camera::getViewDimensions() const {
    return m_viewDimensions;
}
