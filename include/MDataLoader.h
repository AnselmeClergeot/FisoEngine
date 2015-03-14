#ifndef MDATALOADER_H
#define MDATALOADER_H

#include <fstream>

#include "MData.h"
//This class will load all the map data
class MDataLoader
{
    public:
        MDataLoader(MData &data);

        //Function to know if a file exists
        bool fileExists(const std::string path);

        //add layer load file        void addLoadFile(const std::string path);

        //Base function to load all stuff
        void load();

        //Function to save tile-configurations into start file
        void save();

        //To prepare matrices of filling
        void resizeMatrices();

        //Set map size
        void loadMapSize();

        //Fill permanent configuration matrix
        void loadMatrices();

        //To set temporary matrix as same of permanent for the start of program
        void equalizeMatrices();

    private:

        //Layer loading files list
        std::vector<std::string> m_paths;
        //Reference to the class to modify
        MData &m_data;
};

#endif // MDATALOADER_H
