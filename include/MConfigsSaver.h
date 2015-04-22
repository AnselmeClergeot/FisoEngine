#ifndef MCONFIGSSAVER_H
#define MCONFIGSSAVER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MapData.h"

//This class save the map permanent configuration into the loading files.
class MConfigsSaver
{
    public:
        //The only constructor
        MConfigsSaver(MapData &data);

        //To add layer loading file path        void addLoadFile(const std::string path);

        //To reset loading file list
        void resetLayerList();

        //Function to save the map permanent configuration into the loading files
        void save();

    private:
        //Reference to MData to get the configuration
        MapData &m_data;
        //The list of loading files path
        std::vector<std::string> m_paths;
};

#endif // MCONFIGSSAVER_H
