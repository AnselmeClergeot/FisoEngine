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
 * \file TileGroup.hpp
 * \brief Definition of TileGroup class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroup.hpp defines the TileGroup class
 *
 */

#ifndef TILEGROUP_HPP
#define TILEGROUP_HPP
#include "Camera.hpp"
#include "TileGroupData.hpp"
#include "TileGroupLoader.hpp"
#include "TileGroupDrawer.hpp"
#include "TileGroupColors.hpp"

namespace fe {
/**
 * \class TileGroup
 * \brief This class offers an isometric tile-map manipulation
 *
 * TileGroup class offers 3D isometric group of tiles handling and all functionalities linked with.
 * The class also offers useful functionalities like tile opacity, positioning, etc.
 */
class TileGroup
{
    public:

        /**
        * \fn TileGroup(fe::MapData &mapData, fe::Camera &camera)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param camera Reference to the map camera
        */
        TileGroup(fe::MapData &mapData, fe::Camera &camera);

        /**
        * \fn void setTilesetPath(const std::string path)
        * \brief To set the tileset image of the TileGroup
        *
        * \param path The image file path
        * \return void
        */
        void setTilesetPath(const std::string path);

        /**
        * \fn void configureWith(fe::Matrix3d<unsigned int> &config)
        * \brief To set the TileGroup configuration Matrix3d
        *
        * \param config The reference to the TileGroup configuration Matrix3d
        * \return void
        */
        void configureWith(fe::Matrix3d<unsigned int> &config);

        /**
        * \fn void setTileAt(const fe::Vector3 coord, const unsigned int index)
        * \brief To set the tile at 3D coordinates with a tileset coordinate
        *
        * \param coord The tile coordinates
        * \param index The tileset Y index
        * \return void
        */
        void setTileAt(const fe::Vector3 coord, const unsigned int index);

        /**
        * \fn void initialize()
        * \brief To call initialization of the TileGroup
        *
        * \return void
        */
        void initialize();

        /**
        * \fn void updatePosition()
        * \brief To update the TileGroup position from the MapData position
        *
        * \return void
        */
        void updatePosition();

        /**
        * \fn void setTileColor(const fe::Vector3 coord, const fe::Color color)
        * \brief To set the color of a specific tile from 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \param color The color
        * \return void
        */
        void setTileColor(const fe::Vector3 coord, const fe::Color color);

        /**
        * \fn void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity)
        * \brief To set the opacity of a specific tile from 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \param opacity The opacity value
        * \return void
        */
        void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity);

        /**
        * \fn void setTypeColor(const unsigned int tile, const fe::Color color)
        * \brief To set the color of all the tiles of the same type
        *
        * \param tile The tile number
        * \param color The color
        * \return void
        */
        void setTypeColor(const unsigned int tile, const fe::Color color);

        /**
        * \fn void setGroupColor(const fe::Color color)
        * \brief To set the color of all the tiles of the TileGroup
        *
        * \param color The color
        * \return void
        */
        void setGroupColor(const fe::Color color);

        /**
        * \fn fe::Color getGroupColor() const
        * \brief To get the group color
        *
        * \return The color
        */
        fe::Color getGroupColor() const;

        /**
        * \fn void reloadColors()
        * \brief To reload the colors from the types list
        *
        * \return void
        */
        void reloadColors();

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

        /**
        * \fn fe::Color getTileColor(const fe::Vector3 coord)
        * \brief To get the color of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return The color of the tile
        */
        fe::Color getTileColor(const fe::Vector3 coord);

        /**
        * \fn void setTileTilesetX(const fe::Vector3 coord, fe::Vector2 tilesetCoord)
        * \brief To set the X tileset coordinate of a specific tile from its coordinates
        *
        * \param coord The 3D coordinate of the tile
        * \param tilesetCoord The tileset coordinates
        * \return void
        */
        void setTileTilesetX(const fe::Vector3 coord, fe::Vector2 tilesetCoord);

        /**
        * \fn fe::Color getColorOfType(const unsigned int type) const
        * \brief To get the opacity of a specific tile type
        *
        * \param type The tile color
        * \return void
        */
        fe::Color getColorOfType(const unsigned int type) const;

    private:

        fe::TileGroupData m_data; /*!< The TileGroupData */

        fe::TileGroupLoader m_loader; /*!< The TileGroupLoader */

        fe::TileGroupDrawer m_drawer; /*!< The TileGroupDrawer */

        fe::TileGroupColors m_colors; /*!< The TileGroupColors */
};
}

#endif // TILEGROUP_HPP
