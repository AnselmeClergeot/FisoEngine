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
#include <memory>
#include "Vector2.h"

namespace fe {

class TileGroup;
class EntitiesContainer;

/**
 * \class Camera
 * \brief This class is the class instantiated by the user to handle a world camera
 *
 * Camera class is the class manipulated by the user and used by the map to simulate a camera-view on the isometric   map.
 */
class Camera
{
    friend class Map;

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
        * \fn void setViewCenter(const Vector2 center)
        * \brief To set the camera view center coordinates
        *
        * \param center The camera view center in pixels
        * \return void
        */
        void setViewCenter(const Vector2 center);

        /**
        * \fn void setViewCenter(const unsigned int centerX, const unsigned int centerY)
        * \brief To set the camera view center coordinates
        *
        * \param centerX The camera view center X coordinate
        * \param centerY The camera view center Y coordinate
        * \return void
        */
        void setViewCenter(const unsigned int centerX, const unsigned int centerY);

        /**
        * \fn void moveViewCenter(const Vector2 rate)
        * \brief To move the view center
        *
        * \param rate The move rate in pixels
        * \return void
        */
        void moveViewCenter(const Vector2 rate);

        /**
        * \fn void moveViewCenter(const unsigned int rx, const unsigned int ry)
        * \brief To move the view center
        *
        * \param rx The x move rate in pixels
        * \param ry The y move rate in pixels
        * \return void
        */
        void moveViewCenter(const unsigned int rx, const unsigned int ry);

        /**
        * \fn Vector2 getViewDimensions() const
        * \brief To get the camera view dimensions
        *
        * \return The camera view dimensions in pixels
        */
        Vector2 getViewDimensions() const;

        /**
        * \fn Vector2 getViewCenter() const
        * \brief To get the camera view center coordinates
        *
        * \return The camera view center coordinates in pixels
        */
        Vector2 getViewCenter() const;

    private:

        /**
        * \fn void setTileGroups(TileGroup &map, TileGroup &shadows)
        * \brief To set the TileGroups pointers
        *
        * \param map reference to the map TileGroup
        * \param shadows reference to the shadows TileGroup
        * \return void
        */
        void setTileGroups(TileGroup &map, TileGroup &shadows);

        /**
        * \fn void setEntitiesContainer(EntitiesContainer &container)
        * \brief To set the EntitiesContainer pointer
        *
        * \param container reference to the map EntitiesContainer
        * \return void
        */
        void setEntitiesContainer(EntitiesContainer &container);

        Vector2 m_viewDimensions; /*!< The camera view dimensions */

        Vector2 m_viewCenter; /*!< The center of the camera view */

        std::unique_ptr<TileGroup> m_mapTilegroup, /*!< The pointer to the map TileGroup */
                                   m_shadowsTilegroup; /*!< The pointer to the shadows TileGroup */

        std::unique_ptr<EntitiesContainer> m_entitiesContainer; /*!< The pointer to the map EntitiesContainer */
};
}

#endif // CAMERA_H
