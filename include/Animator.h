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
 * \file Animator.h
 * \brief Definition of Animator class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Animator.h defines the Animator class
 *
 */

#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <vector>
#include "MapData.h"
#include "TileAnimData.h"
#include "Timer.h"
#include "Vector3.h"
#include "DynamicShader.h"
#include "ShadowsSystemStates.h"
#include "DrawingFuncs.h"

/**
 * \class Animator
 * \brief Class that animates the map tiles
 *
 * This class is the user interface to the animations system.
 * It is also charged to animates world tiles and shadows.
 */
class Animator
{
    friend class Map;

    public:
        /**
        * \fn Animator(MapData &mapData, TileGroup &mapTilegroup, DynamicShader &shader,
                 ShadowsSystemStates &shadowsStates, Camera &camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param mapTilegroup Reference to the map tilegroup to animate its tiles
        * \param shader Reference to the map dynamic shader to animate shadows
        * \param shadowsStates Reference to the ShadowsSystemStates
        * \param camera Reference to the map camera
        */
        Animator(MapData &mapData, TileGroup &mapTilegroup, DynamicShader &shader,
                 ShadowsSystemStates &shadowsStates, Camera &camera);

        /**
        * \fn void resizeTileAnimDataList()
        * \brief To resize the TileAnimData Matrix3d from the map Matrix3d
        *
        * \return void
        */
        void resizeTileAnimDataList();

        /**
        * \fn void setAnimation(const unsigned tile, const unsigned int length)
        * \brief To set a new tile animation
        *
        * \param tile The tile concerned by the animation, from its number
        * \param length The length of the animation
        * \return void
        */
        void setAnimation(const unsigned tile, const unsigned int length);

        /**
        * \fn void setSpeed(const unsigned int speed)
        * \brief To set the animations speed
        *
        * \param speed The speed of the animations in milliseconds between each animation frame
        * \return void
        */
        void setSpeed(const unsigned int speed);

        /**
        * \fn void next()
        * \brief To make the animations timer progress. Have to be called at each frame.
        *
        * \return void
        */
        void next();

        /**
        * \fn void setSingleAnimKind(const unsigned int tile)
        * \brief To set the animation type of all tiles of the same number to "Single"
        *
        * \param tile The tile concerned from its number
        * \return void
        */
        void setSingleAnimKind(const unsigned int tile);

        /**
        * \fn void setGlobalAnimKind(const unsigned int tile)
        * \brief To set the animation type of all tiles of the same number to "Global"
        *
        * \param tile The tile concerned from its number
        * \return void
        */
        void setGlobalAnimKind(const unsigned int tile);

        /**
        * \fn void setDirectionOf(const Vector3 coord, const AnimDirection direction)
        * \brief To set the direction of the animation of a tile at specific coordinates
        *
        * \param coord The tile coordinates
        * \param direction The animation direction
        * \return void
        */
        void setDirectionOf(const Vector3 coord, const AnimDirection direction);

        /**
        * \fn void setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z,
                                  const AnimDirection direction)
        * \brief To set the direction of the animation of a tile at specific coordinates
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \param direction The animation direction
        * \return void
        */
        void setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z,
                            const AnimDirection direction);

        /**
        * \fn void setKindOf(const Vector3 coord, const AnimKind kind)
        * \brief To set the animation kind of the tile at specific coordinates
        *
        * \param coord The tile coordinates
        * \param kind The animation kind
        * \return void
        */
        void setKindOf(const Vector3 coord, const AnimKind kind);

        /**
        * \fn void setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, const AnimKind kind)
        * \brief To set the animation kind of the tile at specific coordinates
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \param kind The animation kind
        * \return void
        */
        void setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, const AnimKind kind);

        /**
        * \fn void launchAnimation(const Vector3 coord)
        * \brief To launch the animation of a tile at specific coordinates
        *
        * \param coord The tile coordinates
        * \return void
        */
        void launchAnimation(const Vector3 coord);

        /**
        * \fn void launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To launch the animation of a tile at specific coordinates
        *
        * \param x The x tile coordinate
        * \param y The y tile coordinate
        * \param z The z tile coordinate
        * \return void
        */
        void launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn void stopAnimation(const Vector3 coord)
        * \brief To stop the animation of a tile at specific coordinates
        *
        * \param coord The tile coordinates
        * \return void
        */
        void stopAnimation(const Vector3 coord);

        /**
        * \fn void stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To stop the animation of a tile at specific coordinates
        *
        * \param x The x tile coordinate
        * \param y The y tile coordinate
        * \param z The z tile coordinate
        * \return void
        */
        void stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn unsigned int getSpeed() const
        * \brief To get the animations speed
        *
        * \return The animations speed in milliseconds between each animation frame into an unsigned int
        */
        unsigned int getSpeed() const;

        /**
        * \fn unsigned int getFrameAt(const Vector3 coord)
        * \brief To get the animation frame of a specific tile
        *
        * \param coord The tile 3D coordinates
        * \return The animation frame of the tile
        */
        unsigned int getFrameAt(const Vector3 coord);

        /**
        * \fn unsigned int getFrameAt(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the animation frame of a specific tile
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \return The animation frame of the tile
        */
        unsigned int getFrameAt(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn bool getStatusAt(const Vector3 coord)
        * \brief To get the animation status of a specific tile
        *
        * \param coord The tile 3D coordinates
        * \return The animation status of the tile
        */
        bool getStatusAt(const Vector3 coord);

        /**
        * \fn bool getStatusAt(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the animation status of a specific tile
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \return The animation status of the tile
        */
        bool getStatusAt(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn AnimKind getKindAt(const Vector3 coord)
        * \brief To get the animation kind of a specific tile
        *
        * \param coord The tile 3D coordinates
        * \return The animation kind of the tile
        */
        AnimKind getKindAt(const Vector3 coord);

        /**
        * \fn AnimKind getKindAt(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the animation kind of a specific tile
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \return The animation kind of the tile
        */
        AnimKind getKindAt(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn AnimDirection getDirectionAt(const Vector3 coord)
        * \brief To get the animation direction of a specific tile
        *
        * \param coord The tile 3D coordinates
        * \return The animation direction of the tile
        */
        AnimDirection getDirectionAt(const Vector3 coord);

        /**
        * \fn AnimDirection getDirectionAt(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the animation direction of a specific tile
        *
        * \param x The tile x coordinate
        * \param y The tile y coordinate
        * \param z The tile z coordinate
        * \return The animation direction of the tile
        */
        AnimDirection getDirectionAt(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn unsigned int getAnimLengthOfTile(const unsigned int tile) const
        * \brief To get the length of the animation of a specific tile type
        *
        * \param tile The tile type from its number
        * \return The animation length
        */
        unsigned int getAnimLengthOfTile(const unsigned int tile) const;

        /**
        * \fn AnimKind getAnimKindOfTile(const unsigned int tile) const
        * \brief To get the kind of the animation of a specific tile type
        *
        * \param tile The tile type from its number
        * \return The animation kind
        */
        AnimKind getAnimKindOfTile(const unsigned int tile) const;

    private:

        /**
        * \fn void apply()
        * \brief To apply the animations to the shadows and map tilegroups
        *
        * \return void
        */
        void apply();


        /**
        * \fn void updateTileAt(const Vector3 coord)
        * \brief To update the TileAnimData concerned by map 3D coordinates (if tile number has changed)
        *
        * \param coord The tile coordinate to update
        * \return void
        */
        void updateTileAt(const Vector3 coord);

        /**
        * \fn bool tileIsAnimated(const unsigned int tile) const
        * \brief To know if an animation has been set for a specific tile type
        *
        * \param tile The tile type from its number
        * \return True if the tile is animated, false otherwise
        */
        bool tileIsAnimated(const unsigned int tile) const;

        Matrix3d<TileAnimData> m_tileAnimationsData; /*!< The TileAnimData Matrix3d */

        MapData &m_mapData; /*!< The reference to the MapData to get needed data */

        Timer m_timer; /*!< The animations timer */

        unsigned int m_speed; /*!< The animations speed */

        std::vector<Vector3> m_animations; /*!< The container of the global animations data*/

        TileGroup &m_mapTilegroup; /*!< The reference to the map tilegroup to animate */

        DynamicShader &m_shader; /*!< The reference to the dynamic shader to call shadows animation */

        ShadowsSystemStates &m_shadowsStates; /*!< The reference to the ShadowsSystemStates */

        Camera &m_camera; /*!< The reference to the map camera */
};

#endif // ANIMATOR_H
