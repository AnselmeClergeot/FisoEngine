/**
 * \file TileGroupLoader.h
 * \brief Definition of TileGroupLoader class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * TileGroupLoader.h defines the TileGroupLoader class
 *
 */

#ifndef TILEGROUPLOADER_H
#define TILEGROUPLOADER_H
#include <iostream>
#include <fstream>
#include "TileGroupData.h"

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
        * \fn TileGroupLoader(TileGroupData &data, MapData &mapData)
        * \brief The class constructor
        *
        * \param data Reference to the TileGroupData to load
        * \param mapData Reference to the MapData to load
        */
        TileGroupLoader(TileGroupData &data, MapData &mapData);

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
        * \fn void setTilesTileset()
        * \brief To set the tileset to all the tiles in the list
        *
        * \return void
        */
        void setTilesTileset();

        MapData &m_mapData; /*!<  Reference to the MapData */

        std::string m_tilesetPath; /*!<  The tileset fille path */

        TileGroupData &m_data; /*!<  The reference to the TileGroupData to load */
};

#endif // TILEGROUPLOADER_H
