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
 * \file ScreenInfos.h
 * \brief Definition of ScreenInfos class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ScreenInfos.h defines the ScreenInfos class
 *
 */

#ifndef SCREENINFOS_H
#define SCREENINFOS_H
#include "Vector2.h"

/**
 * \class ScreenInfos
 * \brief This class is used to inform environment screen data
 *
 * The user have to instantiate an instance of this class and informs some screen parameters: dimensions, etc.
 * The instance of the class will be useful for different Map aspects. (Drawing)
 */
class ScreenInfos
{
    public:

        /**
        * \fn ScreenInfos()
        * \brief The class default constructor
        *
        */
        ScreenInfos();

        /**
        * \fn ScreenInfos(const unsigned int screenW, const unsigned int screenH)
        * \brief The constructor with windows dimensions
        *
        * \param screenW The window width
        * \param screenH The windows height
        */
        ScreenInfos(const unsigned int screenW, const unsigned int screenH);

        /**
        * \fn void setWindowResolution(const Vector2 res)
        * \brief To set the run window dimensions
        *
        * \param res The window resolution
        * \return void
        */
        void setWindowResolution(const Vector2 res);

        /**
        * \fn void setWindowResolution(const unsigned int w, const unsigned int h)
        * \brief To set the run window dimensions
        *
        * \param w The window width in pixels
        * \param h The window height in pixels
        * \return void
        */
        void setWindowResolution(const unsigned int w, const unsigned int h);

        /**
        * \fn Vector2 getWindowResolution() const
        * \brief To get the run window dimensions
        *
        * \return The window dimensions in pixels
        */
        Vector2 getWindowResolution() const;

    private:

        Vector2 m_windowRes; /*!< The window resolution in pixels */
};

#endif // SCREENINFOS_H
