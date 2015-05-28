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
 * \file FrameSet.hpp
 * \brief Definition of FrameSet class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * FrameSet.hpp defines the FrameSet class
 *
 */

#ifndef FRAMESET_H
#define FRAMESET_H
#include <vector>
#include <assert.h>
#include "Vector2.hpp"

namespace fe {

/**
 * \class FrameSet
 * \brief Class used by user to prepare a set of frame
 *
 * This class is used by the user to prepare a set of frame. Thus, a FrameSet represents an animation state
 * using a group of frame : for example idle/walking/walking down, etc. It is used after by the Animation class.
 */
class FrameSet
{
    public:

        /**
        * \fn FrameSet()
        * \brief The class constructor
        *
        */
        FrameSet();

        /**
        * \fn void setSpeed(const unsigned int speed)
        * \brief To set the time delay between each frame
        *
        * \param speed The time delay between each frames, in milliseconds
        * \return void
        */
        void setSpeed(const unsigned int speed);

        /**
        * \fn void addFrameCoord(const fe::Vector2 coord)
        * \brief To add a frame to the FrameSet from its spritesheet coordinates
        *
        * \param coord The coordinates of the frame in pixels
        * \return void
        */
        void addFrameCoord(const fe::Vector2 coord);

        /**
        * \fn void addFrameCoord(const unsigned int x, const unsigned int y)
        * \brief To add a frame to the FrameSet from its spritesheet coordinates
        *
        * \param x The x coordinate of the frame in pixels
        * \param y The y coordinate of the frame in pixels
        * \return void
        */
        void addFrameCoord(const unsigned int x, const unsigned int y);

        /**
        * \fn void setFrameSize(const fe::Vector2 size)
        * \brief To set the dimensions of the frames
        *
        * \param size The dimensions of a frame in pixels
        * \return void
        */
        void setFrameSize(const fe::Vector2 size);

        /**
        * \fn void setFrameSize(const unsigned int w, const unsigned int h)
        * \brief To set the dimensions of the frames
        *
        * \param w The width of a frame in pixels
        * \param h The height of a frame in pixels
        * \return void
        */
        void setFrameSize(const unsigned int w, const unsigned int h);

        /**
        * \fn unsigned int getLength() const
        * \brief To get the length of the FrameSet in frames
        *
        * \return The length of the FrameSet in frames
        */
        unsigned int getLength() const;

        /**
        * \fn fe::Vector2 getFrameSize() const
        * \brief To get the frames dimensions
        *
        * \return The dimensions of the FrameSet in pixels
        */
        fe::Vector2 getFrameSize() const;

        /**
        * \fn unsigned int getSpeed() const
        * \brief To get the speed of the FrameSet
        *
        * \return The speed of the FrameSet, in milliseconds between each frame
        */
        unsigned int getSpeed() const;

        /**
        * \fn fe::Vector2 getFrameCoordAt(const unsigned int frameNumber) const
        * \brief To get the spritesheet-coordinates of a specific frame
        *
        * \param frameNumber The frame number
        * \return The spritesheet-coordinates of the frame in pixels
        */
        fe::Vector2 getFrameCoordAt(const unsigned int frameNumber) const;

    private:

        unsigned int m_length; /*!< The FrameSet length in frames */

        fe::Vector2 m_frameSize; /*!< The frame dimensions in pixels */

        unsigned int m_speed; /*!< The FrameSet speed in milliseconds between each frame */

        std::vector<fe::Vector2> m_frameCoords; /*!< The FrameSet frames coordinates */
};

}

#endif // FRAMESET_H
