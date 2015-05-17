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
 * \file Map.h
 * \brief Definition of Map class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Map.h defines the Map class
 *
 */

#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "MapData.h"
#include "ConfigsLoader.h"
#include "ConfigsSaver.h"
#include "TileGroup.h"
#include "ShadowsInterface.h"
#include "ShadowsInitializer.h"
#include "ShadowsSystemStates.h"
#include "DynamicShader.h"
#include "EntitiesContainer.h"
#include "EntitiesInterposing.h"
#include "IsometricMath.h"
#include "Animator.h"

namespace fe {
/**
 * \class Map
 * \brief Class used by user to manipulate an isometric map
 *
 * Map is the class that user instantiates to handle and draw an isometric map.
 * It gives access to different other map events like animations, entity system...
 */
class Map : public sf::Drawable
{
    public:

        /**
        * \fn Map(fe::Camera &camera)
        * \brief Map class constructor
        *
        * \param camera Reference to the map camera
        */
        Map(fe::Camera &camera);

        /**
        * \fn void create()
        * \brief Function called by user to create the map
        *
        * \return void
        */
        void create();

        /**
        * \fn void reload()
        * \brief Function called by user to reload the map from new configuration
        *
        * \return void
        */
        void reload();

        /**
        * \fn void save()
        * \brief Function called by user to save the map configuration into layer files
        *
        * \return void
        */
        void save();

        /**
        * \fn void addLayerFile(const std::string path)
        * \brief To add a layer to the map, from a file
        *
        * \param path The path of the layer file
        * \return void
        */
        void addLayerFile(const std::string path);

        /**
        * \fn void resetLayerFiles()
        * \brief To reset the layer files list
        *
        * \return void
        */
        void resetLayerFiles();

        /**
        * \fn setTileset(const std::string path)
        * \brief To set the map tileset
        *
        * \param path The path of the tileset image
        * \return void
        */
        void setTileset(const std::string path);

        /**
        * \fn void setTileSize(const Vector2 size)
        * \brief To set the tile dimensions
        *
        * \param size The dimensions of the tile
        * \return void
        */
        void setTileSize(const Vector2 size);

        /**
        * \fn void setTileSize(const unsigned int w, const unsigned int h)
        * \brief To set the tile dimensions
        *
        * \param w The width of the tile
        * \param h The height of the tile
        * \return void
        */
        void setTileSize(const unsigned int w, const unsigned int h);

        /**
        * \fn void setTileBaseHeight(const unsigned int h)
        * \brief To set the tile base height
        *
        * \param h The base height
        * \return void
        */
        void setTileBaseHeight(const unsigned int h);

        /**
        * \fn void setInvisibleTile(const unsigned int tile)
        * \brief To set the invisible tile number
        *
        * \param tile The invisible tile number
        * \return void
        */
        void setInvisibleTile(const unsigned int tile);

        /**
        * \fn void addTranslucentTile(const unsigned int tile)
        * \brief To add a translucent tile to the map from its number
        *
        * \param tile The translucent tile number
        * \return void
        */
        void addTranslucentTile(const unsigned int tile);

        /**
        * \fn void removeTranslucentTile(const unsigned int tile)
        * \brief To remove a translucent tile of the map from its number
        *
        * \param tile The translucent tile number to remove
        * \return void
        */
        void removeTranslucentTile(const unsigned int tile);

        /**
        * \fn void setTileAt(const fe::Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw)
        * \brief To set the tile at specific map coordinates from a tile number
        *
        * \param coord The coordinate of the tile
        * \param tile The tile number
        * \param modifConf If the map configuration has to be modified?
        * \param modifDraw If the map appearance has to be modified?
        * \return void
        */
        void setTileAt(const fe::Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw);

        /**
        * \fn void setTileAt(const unsigned int x, const unsigned int y, const unsigned int z,
                             const unsigned int tile, bool modifConf, bool modifDraw)
        * \brief To set the tile at specific map coordinates from a tile number
        *
        * \param x The x coordinate of the tile
        * \param y The y coordinate of the tile
        * \param z The z coordinate of the tile
        * \param tile The tile number
        * \param modifConf If the map configuration has to be modified?
        * \param modifDraw If the map appearance has to be modified?
        * \return void
        */
        void setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                       bool modifConf, bool modifDraw);

        /**
        * \fn void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity)
        * \brief To set the opacity of a specific tile
        *
        * \param coord The 3D coordinates of the tile
        * \param opacity The opacity from 0 to 255
        * \return void
        */
        void setTileOpacity(const fe::Vector3 coord, const unsigned int opacity);

        /**
        * \fn void setTileOpacity(const unsigned int x,const unsigned int y,const unsigned int z,
                                const unsigned int opacity)
        * \brief To set the opacity of a specific tile
        *
        * \param x The x coordinate of the tile
        * \param y The y coordinate of the tile
        * \param z The z coordinate of the tile
        * \param opacity The opacity from 0 to 255
        * \return void
        */
        void setTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z,
                                const unsigned int opacity);

        /**
        * \fn void setOpacityOfType(const unsigned int tile, const unsigned int opacity)
        * \brief To set the opacity of all tiles of a specific number
        *
        * \param tile The tile number
        * \param opacity The opacity from 0 to 255
        * \return void
        */
        void setOpacityOfType(const unsigned int tile, const unsigned int opacity);

        /**
        * \fn void setMapOpacity(const unsigned int opacity)
        * \brief To set the opacity of the map tiles
        *
        * \param opacity The opacity from 0 to 255
        * \return void
        */
        void setMapOpacity(const unsigned int opacity);

        /**
        * \fn void setPosition(const fe::Vector2 pos)
        * \brief To set the map position
        *
        * \param pos The position of the map relatively to the top-left screen corner
        * \return void
        */
        void setPosition(const fe::Vector2 pos);

        /**
        * \fn void setPosition(const unsigned int x, const unsigned int y)
        * \brief To set the map position
        *
        * \param x The x position of the map relatively to the left screen border
        * \param y The y position of the map relatively to the top screen border
        * \return void
        */
        void setPosition(const unsigned int x, const unsigned int y);

        /**
        * \fn void move(const fe::Vector2 rate)
        * \brief To move the map relatively to its position
        *
        * \param rate The move rate in pixels
        * \return void
        */
        void move(const fe::Vector2 rate);

        /**
        * \fn void move(const unsigned int rx, const unsigned int ry)
        * \brief To move the map relatively to its position
        *
        * \param rx The x move rate in pixels
        * \param ry The y move rate in pixels
        * \return void
        */
        void move(const unsigned int rx, const unsigned int ry);

        /**
        * \fn void draw(sf::RenderTarget& target, sf::RenderStates states) const
        * \brief To draw the entire map and eventually the entities inside
        *
        * \param target The environment to draw on [SPECIFIC TO SFML]
        * \param states The drawing states [SPECIFIC TO SFML]
        * \return void
        */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        /**
        * \fn fe::Vector3 getDimensions() const
        * \brief To get the map dimensions
        *
        * \return map dimensions in a Vector3
        */
        fe::Vector3 getDimensions() const;

        /**
        * \fn fe::Vector2 getPosition() const
        * \brief To get the map position
        *
        * \return map position in a Vector2
        */
        fe::Vector2 getPosition() const;

        /**
        * \fn fe::Vector2 getTileSize() const
        * \brief To get the map tiles dimensions
        *
        * \return tile dimensions in a Vector2
        */
        fe::Vector2 getTileSize() const;

        /**
        * \fn unsigned int getTileBaseHeight() const
        * \brief To get the map tiles base height
        *
        * \return the base height of the tiles in an unsigned int
        */
        unsigned int getTileBaseHeight() const;

        /**
        * \fn unsigned int getInvisibleTile() const
        * \brief To get the map invisible tile number
        *
        * \return the invisible tile number in an unsigned int
        */
        unsigned int getInvisibleTile() const;

        /**
        * \fn bool isTranslucent(const unsigned int tile) const
        * \brief To know if a tile number is considered as translucent
        *
        * \param tile The number of the tile
        * \return true if the tile is translucent or false is it is not translucent
        */
        bool isTranslucent(const unsigned int tile) const;

        /**
        * \fn unsigned int getTileAt(const fe::Vector3 coord)
        * \brief To get the number of a map tile at specific coordinates
        *
        * \param coord The coordinates of the tile
        * \return The number of the tile in an unsigned int
        */
        unsigned int getTileAt(const fe::Vector3 coord);

        /**
        * \fn unsigned int getTileAt(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the number of a map tile at specific coordinates
        *
        * \param x The x coordinate of the tile
        * \param y The y coordinate of the tile
        * \param z The z coordinate of the tile
        * \return The number of the tile in an unsigned int
        */
        unsigned int getTileAt(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn unsigned int getMapOpacity() const
        * \brief To get the opacity of the map if set
        *
        * \return The opacity of the map in an unsigned int, value from 0 to 255
        */
        unsigned int getMapOpacity() const;

        /**
        * \fn unsigned int getTileOpacity(const fe::Vector3 coord)
        * \brief To get the opacity of a map tile at specific coordinates
        *
        * \param coord The coordinates of the tile
        * \return The opacity of the tile in an unsigned int, value from 0 to 255
        */
        unsigned int getTileOpacity(const fe::Vector3 coord);

        /**
        * \fn unsigned int getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the opacity of a map tile at specific coordinates
        *
        * \param x The x coordinate of the tile
        * \param y The y coordinate of the tile
        * \param z The z coordinate of the tile
        * \return The opacity of the tile in an unsigned int, value from 0 to 255
        */
        unsigned int getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn unsigned int getOpacityOfType(const unsigned int type) const
        * \brief To get the opacity of a specific tile type
        *
        * \param type The tile type from its number
        * \return void
        */
        unsigned int getOpacityOfType(const unsigned int type) const;

        /**
        * \fn fe::Vector2 getTileCoordAtPixels(const fe::Vector2 pixels, const unsigned int layer) const
        * \brief To get the map-relative tile coordinates pointed by 2D screen coordinates
        *
        * \param pixels The screen coordinates
        * \param layer The map layer number to base on to process calculations
        * \return The map-relative tile coordinates in a Vector2
        */
        fe::Vector2 getTileCoordAtPixels(const fe::Vector2 pixels, const unsigned int layer) const;

        /**
        * \fn fe::Vector2 getTileCoordAtPixels(const unsigned int px, const unsigned int py,
                                           const unsigned int layer) const
        * \brief To get the map-relative tile coordinates pointed by 2D screen coordinates
        *
        * \param px The x screen coordinate
        * \param py The y screen coordinate
        * \param layer The map layer number to base on to process calculations
        * \return The map-relative tile coordinates in a Vector2
        */
        fe::Vector2 getTileCoordAtPixels(const unsigned int px, const unsigned int py, const unsigned int layer) const;

        /**
        * \fn fe::ShadowsInterface &shadows()
        * \brief To access the shadows system interface
        *
        * \return A reference to the shadows system interface
        */
        fe::ShadowsInterface &shadows();

        /**
        * \fn fe::EntitiesContainer &entities()
        * \brief To access the entities container to add/delete/access objects
        *
        * \return A reference to the entities container
        */
        fe::EntitiesContainer &entities();

        /**
        * \fn fe::Animator &animator()
        * \brief To access the map tiles animator to operate with the system
        *
        * \return A reference to the map animator
        */
        fe::Animator &animator();

    private:

        fe::Camera &m_camera; /*!< The pointer to the map camera */

        fe::MapData m_data; /*!< The map data container */

        fe::ConfigsLoader m_configsLoader; /*!< The map configuration loader */

        fe::ConfigsSaver m_configsSaver; /*!< The map configuration saver */

        fe::TileGroup m_tileGroup; /*!< The map base tilegroup (map tiles only) */

        fe::TileGroup m_shadowsTilegroup; /*!< The map shadows tilegroup (shadows images only) */

        fe::ShadowsSystemStates m_shadowsStates; /*!< The shadows system states container */

        fe::DynamicShader m_dynamicShader; /*!< The map dynamic shader */

        fe::ShadowsInitializer m_shadowsInitializer; /*!< The shadows system initializer */

        fe::ShadowsInterface m_shadowsInterface; /*!< The shadows system interface for user */

        fe::EntitiesContainer m_entityContainer; /*!< The entities container to add/create/access entities */

        fe::EntitiesInterposing m_interposing; /*!< The class that interposes entities into the map */

        fe::Animator m_animator; /*!< The map tiles animator */
};
}

#endif // MAP_H
