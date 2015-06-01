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
 * \file Animation.hpp
 * \brief Definition of Animation class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Animation.hpp defines the Animation class
 *
 */

#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Timer.hpp"
#include "FrameSet.hpp"
#include "Status.hpp"

namespace fe {

/**
 * \class Animation
 * \brief Class used by user to animate any spritesheet
 *
 * This class is the class that user uses to animate a spritesheet.
 */
class Animation
{
    public:

        /**
        * \fn Animation()
        * \brief The class constructor
        *
        */
        Animation();

        /**
        * \fn Animation(sf::Sprite &sprite)
        * \brief The class constructor with spritesheet
        *
        * \param sprite Reference to the spritesheet
        */
        Animation(sf::Sprite &sprite);

        /**
        * \fn void setSpriteSheet(sf::Sprite &spriteSheet)
        * \brief To set a reference to the spritesheet to animate
        *
        * \param spriteSheet Refrence to the spritesheet to animate
        * \return void
        */
        void setSpriteSheet(sf::Sprite &spriteSheet);

        /**
        * \fn void setCurrentFrameSet(fe::FrameSet &frameSet)
        * \brief To set a reference to the current animation FrameSet
        *
        * \param frameSet Refrence to the FrameSet
        * \return void
        */
        void setCurrentFrameSet(fe::FrameSet &frameSet);

        /**
        * \fn void animate()
        * \brief To make progress the animation at each frame
        *
        * \return void
        */
        void animate();

        /**
        * \fn void setStatus(const fe::Status status)
        * \brief To set the status playing/not playing of the animation
        *
        * \param status The animation status
        * \return void
        */
        void setStatus(const fe::Status status);

        /**
        * \fn unsigned int getCurrentFrame() const
        * \brief To get the current frame of the animation
        *
        * \return The current animation frame
        */
        unsigned int getCurrentFrame() const;

        /**
        * \fn fe::Status getStatus() const
        * \brief To get the status of the animation
        *
        * \return The current animation status
        */
        fe::Status getStatus() const;

    private:

        /**
        * \fn void frameSprite()
        * \brief To frame the spriteSheet from FrameSet and current frame informations
        *
        * \return void
        */
        void frameSprite();

        fe::Status m_playing; /*!< The playing/not playing status */

        unsigned int m_currentFrame; /*!< The current frame */

        sf::Sprite* m_spriteSheet; /*!< The pointer to the spritesheet */

        fe::Timer m_timer; /*!< The Timer of the animation */

        fe::FrameSet* m_currentFrameSet; /*!< The pointer to the current FrameSet */
};

}

#endif // ANIMATION_H
