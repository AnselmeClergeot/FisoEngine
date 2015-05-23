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
 * \file TileAnimData.hpp
 * \brief Definition of TileAnimData class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileAnimData.hpp defines the TileAnimData class
 *
 */

#ifndef TILEANIMDATA_HPP
#define TILEANIMDATA_HPP

#include "Vector2.hpp"
#include "Status.hpp"

namespace fe {

/*!  AnimKind defines the tile animation type*/
enum AnimKind {Global /*!< A global animation kind like water, etc. */,
               Single /*!< A single animation kind like door, explosion, etc. */ };

/*!  AnimDirection defines the tile animation direction*/
enum AnimDirection {Right /*!< Right direction animation */,
                    Left /*!< Left direction animation */ };

/**
 * \class TileAnimData
 * \brief This class represents a tile animation
 *
 * This class represent one animation for one tile.
 * It contains all animation data: direction, length, etc.
 */
class TileAnimData
{
    public:

        /**
        * \fn TileAnimData()
        * \brief The default constructor
        *
        */
        TileAnimData();

        /**
        * \fn void setKind(const fe::AnimKind kind)
        * \brief To set the kind of the animation
        *
        * \param kind The animation kind
        * \return void
        */
        void setKind(const fe::AnimKind kind);

        /**
        * \fn void setDirection(const fe::AnimDirection direction)
        * \brief To set the animation direction
        *
        * \param direction The animation direction
        * \return void
        */
        void setDirection(const fe::AnimDirection direction);

        /**
        * \fn void setLength(const unsigned int length)
        * \brief To set the animation length
        *
        * \param length The animation length in frames
        * \return void
        */
        void setLength(const unsigned int length);

        /**
        * \fn void setStatus(const fe::Status status)
        * \brief To set the animation status (playing/not playing)
        *
        * \param status The playing status
        * \return void
        */
        void setStatus(const fe::Status status);

        /**
        * \fn void updateX()
        * \brief To make progress the present animation frame, taking in account direction, etc.
        *
        * \return void
        */
        void updateX();

        /**
        * \fn void resetX()
        * \brief To reset the present frame
        *
        * \return void
        */
        void resetX();

        /**
        * \fn fe::AnimKind getKind() const
        * \brief To get the kind of the animation
        *
        * \return The animation kind
        */
        fe::AnimKind getKind() const;

        /**
        * \fn fe::AnimDirection getDirection() const
        * \brief To get the direction of the animation
        *
        * \return The animation direction
        */
        fe::AnimDirection getDirection() const;

        /**
        * \fn unsigned int getLength() const
        * \brief To get the animation length
        *
        * \return The animation length in frames
        */
        unsigned int getLength() const;

        /**
        * \fn unsigned int getX() const
        * \brief To get the animation present frame
        *
        * \return The animation present frame
        */
        unsigned int getX() const;

        /**
        * \fn fe::Status getStatus() const
        * \brief To get the animation playing status
        *
        * \return The animation playing status
        */
        fe::Status getStatus() const;

    private:

        fe::AnimKind m_kind; /*!< The kind of the animation */

        fe::AnimDirection m_direction; /*!< The direction of the animation */

        unsigned int m_x; /*!< The present frame of the animation */

        fe::Status m_status; /*!< The playing status of the animation */

        fe::Status m_waitStatus; /*!< The waiting playing status for the next frame */

        unsigned int m_length; /*!< The length of the animation in frames*/
};
}

#endif // TILEANIMDATA_HPP
