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
 * \file TileGroupDrawer.h
 * \brief Definition of TileGroupDrawer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupDrawer.h defines the TileGroupDrawer class
 *
 */

#ifndef TILEGROUPDRAWER_H
#define TILEGROUPDRAWER_H
#include <SFML/Graphics.hpp>
#include "MapData.h"
#include "TileGroupData.h"
#include "ScreenInfos.h"
#include "EntitiesInterposing.h"

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
        * \fn TileGroupDrawer(MapData &mapData, TileGroupData &data, ScreenInfos &screenInfos)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param data Reference to the TileGroupData to get needed data to draw
        * \param screenInfos Reference to the user ScreenInfos to get useful window data
        */
        TileGroupDrawer(MapData &mapData, TileGroupData &data, ScreenInfos &screenInfos);

        /**
        * \fn void draw(sf::RenderTarget& target, const unsigned int layer,
                  const EntitiesInterposing *interposing = 0) const
        * \brief To draw a specific layer of the TileGroup
        *
        * \param target The target on which to draw the tiles [SPECIFIC SFML]
        * \param layer The layer number to draw
        * \param interposing The pointer to the EntitiesInterposing class to
                 interpose entities if the TileGroup is the map tiles TileGroup
        * \return void
        */
        void draw(sf::RenderTarget& target, const unsigned int layer,
                  const EntitiesInterposing *interposing = 0) const;

    private:

        MapData &m_mapData; /*!< Reference to the MapData to get useful map data */

        TileGroupData &m_data; /*!< Reference to the TileGroupData to get needed data to draw */

        ScreenInfos &m_screenInfos; /*!< Reference to the user ScreenInfos to get useful window data */
};

#endif // TILEGROUPDRAWER_H
