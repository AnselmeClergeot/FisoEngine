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
 * \file ShadowsInterface.hpp
 * \brief Definition of ShadowsInterface class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ShadowsInterface.hpp defines the ShadowsInterface class
 *
 */

#ifndef SHADOWSINTERFACE_HPP
#define SHADOWSINTERFACE_HPP
#include "ShadowsInitializer.hpp"
#include "TileGroup.hpp"

namespace fe {
/**
 * \class ShadowsInterface
 * \brief This class is the user interface with the shadows system
 *
 * This class is the user interface to operate with the shadows system.
 */
class ShadowsInterface
{
    public:

        /**
        * \fn ShadowsInterface(fe::ShadowsInitializer &loader,
                               fe::ShadowsSystemStates &states,
                               fe::TileGroup &tilegroup)
        * \brief The class constructor
        *
        * \param loader Reference to the ShadowsInitializer to call shadows calculation
        * \param states Reference to the ShadowsSystemStates to modify the states
        * \param tilegroup Reference to the shadows TileGroup to act on it
        */
        ShadowsInterface(fe::ShadowsInitializer &loader,
                         fe::ShadowsSystemStates &states,
                         fe::TileGroup &tilegroup);

        /**
        * \fn void setTileset(const std::string path)
        * \brief To set the shadows tileset image path
        *
        * \param path The tileset image path
        * \return void
        */
        void setTileset(const std::string path);

        /**
        * \fn void setOpacity(const unsigned int opacity)
        * \brief To set the opacity of the shadows
        *
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setOpacity(const unsigned int opacity);

        /**
        * \fn void init()
        * \brief To call shadows calculation
        *
        * \return void
        */
        void init();

        /**
        * \fn void setStatus(const fe::Status status)
        * \brief To set the shadows on
        *
        * \param status The on/off status
        * \return void
        */
        void setStatus(const fe::Status status);

        /**
        * \fn unsigned int getOpacity() const
        * \brief To get the shadows opacity
        *
        * \return The shadows opacity
        */
        unsigned int getOpacity() const;

        /**
        * \fn fe::Status getStatus() const
        * \brief To get the shadows system on/off status
        *
        * \return The shadows system status
        */
        fe::Status getStatus() const;

    private:

        fe::ShadowsInitializer &m_initializer; /*!< Reference to the ShadowsInitializer to call initialization*/

        fe::ShadowsSystemStates &m_states; /*!< Reference to the ShadowsSystemStates to change states */

        fe::TileGroup &m_tilegroup; /*!< Reference to the shadows TileGroup  to act directly on it when needed*/
};
}

#endif // SHADOWSINTERFACE_HPP
