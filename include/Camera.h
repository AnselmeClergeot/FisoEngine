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
 * \file Camera.h
 * \brief Definition of Camera class
 * \author AnselmeClergeot
 * \version beta
 * \date 07/05/15
 *
 * Camera.h defines the Camera class
 *
 */

#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2.h"

/**
 * \class Camera
 * \brief This class is the class instantiated by the user to handle a world camera
 *
 * Camera class is the class manipulated by the user and used by the map to simulate a camera-view on the isometric   map.
 */
class Camera
{
    public:

        /**
        * \fn Camera()
        * \brief The class default constructor
        *
        */
        Camera();

        /**
        * \fn Camera(const unsigned int viewW, const unsigned int viewH)
        * \brief The constructor with camera view size
        *
        * \param viewW The view width
        * \param viewH The view height
        */
        Camera(const unsigned int viewW, const unsigned int viewH);

        /**
        * \fn void setViewDimensions(const Vector2 dim)
        * \brief To set the camera view width and height
        *
        * \param dim The camera dimensions
        * \return void
        */
        void setViewDimensions(const Vector2 dim);

        /**
        * \fn void setViewDimensions(const unsigned int w, const unsigned int h)
        * \brief To set the camera view width and height
        *
        * \param w The camera view width in pixels
        * \param h The camera view height in pixels
        * \return void
        */
        void setViewDimensions(const unsigned int w, const unsigned int h);

        /**
        * \fn Vector2 getViewDimensions() const
        * \brief To get the camera view dimensions
        *
        * \return The camera view dimensions in pixels
        */
        Vector2 getViewDimensions() const;

    private:

        Vector2 m_viewDimensions; /*!< The camera view dimensions */
};

#endif // CAMERA_H
