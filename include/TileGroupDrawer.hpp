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
 * \file TileGroupDrawer.hpp
 * \brief Definition of TileGroupDrawer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupDrawer.hpp defines the TileGroupDrawer class
 *
 */

#ifndef TILEGROUPDRAWER_HPP
#define TILEGROUPDRAWER_HPP
#include <SFML/Graphics.hpp>
#include "MapData.hpp"
#include "TileGroupData.hpp"
#include "Camera.hpp"
#include "EntitiesInterposing.hpp"

namespace fe {
/**
 * \class TileGroupDrawer
 * \brief This class is charged to draw the TileGroup
 *
 * TileGroupDrawer class uses TileGroupData stuff (tile images, etc.) to draw the TileGroup on screen.
 */
class TileGroupDrawer
{
    public:

        /**
        * \fn TileGroupDrawer(fe::MapData &mapData, fe::TileGroupData &data, fe::Camera &camera,
                              fe::TileGroupColors &colors)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param data Reference to the TileGroupData to get needed data to draw
        * \param camera Reference to the map camera
        * \param colors Reference to the TileGroupColors
        */
        TileGroupDrawer(fe::MapData &mapData, fe::TileGroupData &data, fe::Camera &camera, fe::TileGroupColors &colors);

        /**
        * \fn void draw(sf::RenderTarget& target, const unsigned int layer,
                  const fe::EntitiesInterposing *interposing = 0) const
        * \brief To draw a specific layer of the TileGroup
        *
        * \param target The target on which to draw the tiles [SPECIFIC SFML]
        * \param layer The layer number to draw
        * \param interposing The pointer to the EntitiesInterposing class to
                 interpose entities if the TileGroup is the map tiles TileGroup
        * \return void
        */
        void draw(sf::RenderTarget& target, const unsigned int layer,
                  const fe::EntitiesInterposing *interposing = 0) const;

    private:

        fe::MapData &m_mapData; /*!< Reference to the MapData to get useful map data */

        fe::TileGroupData &m_data; /*!< Reference to the TileGroupData to get needed data to draw */

        fe::Camera &m_camera; /*!< Reference to the map camera */

        fe::TileGroupColors &m_colors; /*!< Reference to the TileGroupColors */
};
}

#endif // TILEGROUPDRAWER_HPP
