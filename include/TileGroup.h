/**
 * \file TileGroup.h
 * \brief Definition of TileGroup class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroup.h defines the TileGroup class
 *
 */

#ifndef TILEGROUP_H
#define TILEGROUP_H
#include "ScreenInfos.h"
#include "TileGroupData.h"
#include "TileGroupLoader.h"
#include "TileGroupDrawer.h"

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
        * \fn TileGroup(MapData &mapData, ScreenInfos &screenInfos)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get useful map data
        * \param screenInfos Reference to the user ScreenInfos to get useful window data
        */
        TileGroup(MapData &mapData, ScreenInfos &screenInfos);

        /**
        * \fn void setTilesetPath(const std::string path)
        * \brief To set the tileset image of the TileGroup
        *
        * \param path The image file path
        * \return void
        */
        void setTilesetPath(const std::string path);

        /**
        * \fn void setConfiguration(Matrix3d<unsigned int> &matrix)
        * \brief To set the TileGroup configuration Matrix3d
        *
        * \param matrix The TileGroup configuration Matrix3d
        * \return void
        */
        void setConfiguration(Matrix3d<unsigned int> &matrix);

        /**
        * \fn void setTileAt(const Vector3 coord, const unsigned int index)
        * \brief To set the tile at 3D coordinates with a tileset coordinate
        *
        * \param coord The tile coordinates
        * \param index The tileset Y index
        * \return void
        */
        void setTileAt(const Vector3 coord, const unsigned int index);

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
        * \fn void setTileOpacity(const Vector3 coord, const unsigned int opacity)
        * \brief To set the opacity of a specific tile from 1D index
        *
        * \param coord The tile 3D coordinates
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setTileOpacity(const Vector3 coord, const unsigned int opacity);

        /**
        * \fn void setTypeOpacity(const unsigned int tile, const unsigned int opacity)
        * \brief To set the opacity of all the tiles of the same type
        *
        * \param tile The tile number
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);

        /**
        * \fn void setGroupOpacity(const unsigned int opacity)
        * \brief To set the opacity of all the tiles of the TileGroup
        *
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setGroupOpacity(const unsigned int opacity);

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

        /**
        * \fn unsigned int getTileOpacity(const Vector3 coord) const
        * \brief To get the opacity of a specific tile at 3D coordinates
        *
        * \param coord The tile 3D coordinates
        * \return The opacity value of the tile, from 0 to 255
        */
        unsigned int getTileOpacity(const Vector3 coord);

        /**
        * \fn unsigned int getGroupOpacity() const
        * \brief To get the opacity of the entire TileGroup if set
        *
        * \return The opacity value of the entire TileGroup, from 0 to 255
        */
        unsigned int getGroupOpacity() const;

        /**
        * \fn void setTileTilesetX(const Vector3 coord, const unsigned int x)
        * \brief To set the X tileset coordinate of a specific tile from its coordinates
        *
        * \param coord The 3D coordinate of the tile
        * \param x The x tileset coordinate of the tile
        * \return void
        */
        void setTileTilesetX(const Vector3 coord, const unsigned int x);

    private:

        TileGroupData m_data; /*!< The TileGroupData */

        TileGroupLoader m_loader; /*!< The TileGroupLoader */

        TileGroupDrawer m_drawer; /*!< The TileGroupDrawer */
};

#endif // TILEGROUP_H
