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
 * \file ShadowsSystemStates.h
 * \brief Definition of ShadowsSystemStates class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ShadowsSystemStates.h defines the ShadowsSystemStates class
 *
 */

#ifndef SHADOWSSYSTEMSTATES_H
#define SHADOWSSYSTEMSTATES_H

namespace fe {
/**
 * \class ShadowsSystemStates
 * \brief This class is the state container of the shadows system.
 *
 * This class is used by the engine to store the different shadows system states like on/off, initialized, etc.
 */
class ShadowsSystemStates
{
    public:

        /**
        * \fn ShadowsSystemStates()
        * \brief The default class constructor
        *
        */
        ShadowsSystemStates();

        /**
        * \fn void setOn(bool on)
        * \brief To set the shadows system on/off
        *
        * \param on True for on and false for off
        * \return void
        */
        void setOn(bool on);

        /**
        * \fn void setInitialized()
        * \brief To set the shadows system initialized state to true
        *
        * \return void
        */
        void setInitialized();

        /**
        * \fn bool isOn() const
        * \brief To know if the shadows system is on or off
        *
        * \return True for on and false for off
        */
        bool isOn() const;

        /**
        * \fn bool isInitialized() const
        * \brief To know if the shadows system is initialized or not
        *
        * \return True for initialized and false otherwise
        */
        bool isInitialized() const;

    private:

        bool m_on, /*!< The on/off state */

        m_initialized; /*!< The initialized or not state */
};
}

#endif // SHADOWSSYSTEMSTATES_H
