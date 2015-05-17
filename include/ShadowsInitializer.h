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
 * \file ShadowsInitializer.h
 * \brief Definition of ShadowsInitializer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ShadowsInitializer.h defines the ShadowsInitializer class
 *
 */

#ifndef SHADOWSINITIALIZER_H
#define SHADOWSINITIALIZER_H
#include "TileGroup.h"
#include "ShadowsSystemStates.h"
#include "MapData.h"
#include "Matrix3d.h"
#include "DynamicShader.h"

namespace fe {
/**
 * \class ShadowsInitializer
 * \brief This class calculates the shadows configuration at start of the system
 *
 * This class calculates the position of the shadows in a Matrix3d at the shadows system start.
 * Then this Matrix3d is sent to the shadows TileGroup to set it for drawing.
 */
class ShadowsInitializer
{
    public:

        /**
        * \fn ShadowsInitializer(fe::TileGroup &tilegroup,
                                 fe::ShadowsSystemStates &states,
                                 fe::MapData &mapData,
                                 fe::DynamicShader &shader)
        * \brief The class constructor
        *
        * \param tilegroup Reference to the shadows TileGroup to send condifuration
        * \param states Reference to the ShadowsSystemStates to modify states
        * \param mapData Reference to the MapData to get useful map data
        * \param shader Reference to the DynamicShader
        */
        ShadowsInitializer(fe::TileGroup &tilegroup,
                           fe::ShadowsSystemStates &states,
                           fe::MapData &mapData,
                           fe::DynamicShader &shader);

        /**
        * \fn void initialize()
        * \brief To call shadows system first calculation
        *
        * \return void
        */
        void initialize();

    private:

        /**
        * \fn void resizeMatrix(fe::Matrix3d<unsigned int> &tempConf)
        * \brief To resize the temporary shadows configuration
        *
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void resizeMatrix(fe::Matrix3d<unsigned int> &tempConf);

        /**
        * \fn void fillMatrix(fe::Matrix3d<unsigned int> &tempConf)
        * \brief To call filling the temporary configuration with calculated values
        *
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void fillMatrix(fe::Matrix3d<unsigned int> &tempConf);

        /**
        * \fn void calculateShadowInConf(const fe::Vector3 coord, fe::Matrix3d<unsigned int> &tempConf)
        * \brief To calculate a generated shadow from a map tile coordinates
        *
        * \param coord The tile coordinates
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void calculateShadowInConf(const fe::Vector3 coord, fe::Matrix3d<unsigned int> &tempConf);

        fe::TileGroup &m_tileGroup; /*!< The reference to the shadows TileGroup */

        fe::MapData &m_mapData; /*!< The reference to the MapData to access useful map data */

        fe::ShadowsSystemStates &m_states; /*!< The reference to the ShadowsSystemStates  */

        fe::DynamicShader &m_shader; /*!< The reference to the DynamicShader  */
};
}

#endif // SHADOWSINITIALIZER_H
