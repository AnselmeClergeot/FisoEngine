#ifndef TILEGROUPLOADER_H
#define TILEGROUPLOADER_H

#include <iostream>
#include <fstream>

#include "TileGroupData.h"

//This class loads and configure the TileGroup drawing stuff such as the tile list, etc.
class TileGroupLoader
{
    public:
        //The only constructor, called by TileGroup class
        TileGroupLoader(TileGroupData &data);

        //To set the path of the tileset
        void setTilesetPath(const std::string path);

        //To load the tileset image from the path
        void loadTileset();

        //To resize the tile list of TileGroupData
        void resizeTileList();

        //To set the tileset to all the tiles in the list of TileGroupData
        void setTilesTileset();

        //To set the good tileset frame of all the tiles in the list of TileGroupData
        void setTilesRect();

        //The root function that call all above functions
        void initialize();

    private:
        //The tileset path
        std::string m_tilesetPath;
        //A reference to the TileGroupData to load
        TileGroupData &m_data;
};

#endif // TILEGROUPLOADER_H
