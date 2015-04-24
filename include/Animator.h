/**
 * \file Animator.h
 * \brief Definition of Animator class
 * \author AnselmeClergeot
 * \version beta
 * \date 24/04/15
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
        * \fn Animator(MapData &mapData, TileGroup &mapTilegroup, DynamicShader &shader)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param mapTilegroup Reference to the map tilegroup to animate its tiles
        * \param shader Reference to the map dynamic shader to animate shadows
        */
        Animator(MapData &mapData, TileGroup &mapTilegroup, DynamicShader &shader);

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

    private:

        /**
        * \fn void apply()
        * \brief To apply the animations to the shadows and map tilegroups
        *
        * \return void
        */
        void apply();

        /**
        * \fn void resizeAnimationsDataList()
        * \brief To resize the TileAnimData vector
        *
        * \return void
        */
        void resizeAnimationsDataList();

        /**
        * \fn void updateTileAt(const Vector3 coord)
        * \brief To update the TileAnimData concerned by map 3D coordinates (if tile number has changed)
        *
        * \return void
        */
        void updateTileAt(const Vector3 coord);

        std::vector<TileAnimData> m_tileAnimationsData; /*!< The TileAnimData list */

        MapData &m_mapData; /*!< The reference to the MapData to get needed data */

        Timer m_timer; /*!< The animations timer */

        unsigned int m_speed; /*!< The animations speed */

        std::vector<Vector3> m_animations; /*!< The container of the global animations data*/

        TileGroup &m_mapTilegroup; /*!< The reference to the map tilegroup to animate */

        DynamicShader &m_shader; /*!< The reference to the dynamic shader to call shadows animation */
};

#endif // ANIMATOR_H
