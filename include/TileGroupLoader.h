#ifndef TILEGROUPLOADER_H
#define TILEGROUPLOADER_H

#include <iostream>
#include <fstream>

#include "TileGroupData.h"
#include "../ExternClasses/Matrix3d.h"

class TileGroupLoader
{
    public:
        TileGroupLoader(TileGroupData &data);

        //To know if a file exists
        bool fileExists(const std::string path);

        //To set the tileset path
        void setTilesetPath(const std::string path);

        //To load the tileset from the path
        void loadTileset();

        //To resize the tile list
        void resizeTileList();

        //To set all tiles tileset
        void setTilesTileset();

        //To set all tiles corresponding rect
        void setTilesRect();

        //To initialize TileGroupData
        void initialize();
    private:
        //Tileset path
        std::string m_tilesetPath;
        //Reference to the data to load
        TileGroupData &m_data;
};

#endif // TILEGROUPLOADER_H
