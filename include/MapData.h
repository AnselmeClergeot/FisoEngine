/**
 * \file MapData.h
 * \brief Definition of MapData class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * MapData.h defines the MapData class
 *
 */

#ifndef MAPDATA_H
#define MAPDATA_H
#include "Matrix3d.h"
#include "Vector2.h"
#include <algorithm>

/**
 * \class MapData
 * \brief This class is the container of all map data
 *
 * MapData is used by the engine to store the map data such as size, tile dimensions, and the configurations.
 */
class MapData
{
    public:

        /**
        * \fn MapData()
        * \brief The class constructor
        *
        */
        MapData();

        /**
        * \fn void setSize(const Vector2 size)
        * \brief To set the map dimensions
        *
        * \param size The width and the layer number of the map
        * \return void
        */
        void setSize(const Vector2 size);

        /**
        * \fn void setPosition(const Vector2 position)
        * \brief To set the map position
        *
        * \param position The map position in pixels
        * \return void
        */
        void setPosition(const Vector2 position);

        /**
        * \fn void move(const Vector2 rate)
        * \brief To move the map position relatively to its position
        *
        * \param rate The move rate in pixels
        * \return void
        */
        void move(const Vector2 rate);

        /**
        * \fn void setTileSize(const Vector2 size)
        * \brief To set the map tiles dimensions
        *
        * \param size The tile dimensions in pixels
        * \return void
        */
        void setTileSize(const Vector2 size);

        /**
        * \fn void setTileBaseHeight(const unsigned int h)
        * \brief To set the map tiles base height
        *
        * \param h The tile base height in pixel
        * \return void
        */
        void setTileBaseHeight(const unsigned int h);

        /**
        * \fn void setInvisibleTile(const unsigned int tile)
        * \brief To set the map invisible tile number
        *
        * \param tile The invisible tile number
        * \return void
        */
        void setInvisibleTile(const unsigned int tile);

        /**
        * \fn void addTranslucentTile(const unsigned int tile)
        * \brief To add a translucent tile to the list from its number
        *
        * \param tile The translucent tile number
        * \return void
        */
        void addTranslucentTile(const unsigned int tile);

        /**
        * \fn void removeTranslucentTile(const unsigned int tile)
        * \brief To remove a translucent tile from the list from its number
        *
        * \param tile The translucent tile number
        * \return void
        */
        void removeTranslucentTile(const unsigned int tile);

        /**
        * \fn Matrix3d &getTempConf()
        * \brief To get a reference to the temporary configuration of the map
        *
        * \return The temporary configuration
        */
        Matrix3d &getTempConf();

        /**
        * \fn Matrix3d &getPermConf()
        * \brief To get a reference to the permanent configuration of the map
        *
        * \return The permanent configuration
        */
        Matrix3d &getPermConf();

        /**
        * \fn Vector2 getSize() const
        * \brief To get the map size
        *
        * \return The width and the layer number of the map
        */
        Vector2 getSize() const;

        /**
        * \fn Vector2 getPosition() const
        * \brief To get the map position
        *
        * \return The map position in pixels
        */
        Vector2 getPosition() const;

        /**
        * \fn Vector2 getTileSize() const
        * \brief To get the map tiles dimensions
        *
        * \return The map tiles dimensions in pixels
        */
        Vector2 getTileSize() const;

        /**
        * \fn unsigned int getTileBaseHeight() const
        * \brief To get the map tiles base height
        *
        * \return The map tiles base height in pixel
        */
        unsigned int getTileBaseHeight() const;

        /**
        * \fn unsigned int getInvisibleTile() const
        * \brief To get the map invisible tile number
        *
        * \return The map invisible tile number
        */
        unsigned int getInvisibleTile() const;

        /**
        * \fn bool isTranslucent(const unsigned int tile) const
        * \brief To know if a tile is considered as translucent, from its number
        *
        * \return True if the tile is translucent, false otherwise
        */
        bool isTranslucent(const unsigned int tile) const;

    private:

        Matrix3d m_tempConf; /*!< The temporary configuration, used for map appearance purpose (shadows, etc.)*/

        Matrix3d m_permConf; /*!< The permanent configuration, the one used for saving and loading the map */

        Vector2 m_size; /*!< The map dimensions */

        Vector2 m_position; /*!< The map position */

        Vector2 m_tileSize; /*!< The map tiles dimensions */

        unsigned int m_tileBaseHeight; /*!< The map tiles base height */

        unsigned int m_invisibleTile; /*!< The map invisible tile number */

        std::vector<unsigned int> m_translucentTiles; /*!< The list of translucent tiles number */
};

#endif // MAPDATA_H
