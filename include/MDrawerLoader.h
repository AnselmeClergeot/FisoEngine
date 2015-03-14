#ifndef MDRAWERLOADER_H
#define MDRAWERLOADER_H

#include <fstream>

#include "MDrawer.h"

//This class will load the map drawer data
class MDrawerLoader
{
    public:
        MDrawerLoader(MDrawer &drawer, MData &data);

        //Start loading
        void load();

        //Check if file exists
        bool fileExists(const std::string path);

        //Set spritesheet path
        void setSpritesheetPath(const std::string path);

        //To load spritesheet
        void loadTexture();

        //Setting spritesheet to all tiles
        void setTilesTex();

        //Setting good tileFrame to all tiles
        void setTilesRect();

        //Resize the drawer sprite list (tiles)
        void resizeTileList();

    private:
        //Reference to the class to modify
        MDrawer &m_drawer;
        //Reference to MData to get some essential data
        MData &m_data;
        //Spritesheet path
        std::string m_path;
};

#endif // MDRAWERLOADER_H
