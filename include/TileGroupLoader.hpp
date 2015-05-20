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
 * \file TileGroupLoader.hpp
 * \brief Definition of TileGroupLoader class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupLoader.hpp defines the TileGroupLoader class
 *
 */

#ifndef TILEGROUPLOADER_HPP
#define TILEGROUPLOADER_HPP
#include <iostream>
#include <fstream>
#include "TileGroupData.hpp"
#include "TileGroupColors.hpp"

namespace fe {
/**
 * \class TileGroupLoader
 * \brief This class is charged to load TileGroupData stuff
 *
 * TileGroupLoader is charged to load the TileGroupData stuff such as the tileset, and setting it to all tiles, etc.
 * It also frames the tiles before the first drawing call.
 */
class TileGroupLoader
{
    public:

        /**
        * \fn TileGroupLoader(fe::TileGroupData &data, fe::MapData &mapData, fe::TileGroupColors &colors)
        * \brief The class constructor
        *
        * \param data Reference to the TileGroupData to load
        * \param mapData Reference to the MapData to load
        * \param colors Reference to the TileGroupColors
        */
        TileGroupLoader(fe::TileGroupData &data, fe::MapData &mapData, fe::TileGroupColors &colors);

        /**
        * \fn void setTilesetPath(const std::string path)
        * \brief To set the tileset image of the TileGroup
        *
        * \param path The image file path
        * \return void
        */
        void setTilesetPath(const std::string path);

        /**
        * \fn void initialize()
        * \brief To call TileGroupData loading
        *
        * \return void
        */
        void initialize();

    private:

        /**
        * \fn void loadTileset()
        * \brief To load the tileset image from the path informed
        *
        * \return void
        */
        void loadTileset();

        /**
        * \fn void resizeTileList()
        * \brief To resize the tile list
        *
        * \return void
        */
        void resizeTileList();

        /**
        * \fn void resizeOpacitiesMatrix3d()
        * \brief To resize the Matrix3d tile opacities values
        *
        * \return void
        */
        void resizeOpacitiesMatrix3d();

        /**
        * \fn void setTilesTileset()
        * \brief To set the tileset to all the tiles in the list
        *
        * \return void
        */
        void setTilesTileset();

        fe::MapData &m_mapData; /*!<  Reference to the MapData */

        std::string m_tilesetPath; /*!<  The tileset fille path */

        fe::TileGroupData &m_data; /*!<  The reference to the TileGroupData to load */

        fe::TileGroupColors &m_colors; /*!<  The reference to the TileGroupColors */
};
}

#endif // TILEGROUPLOADER_HPP
