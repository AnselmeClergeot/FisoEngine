#ifndef MCONFIGSLOADER_H
#define MCONFIGSLOADER_H
#include <fstream>

#include "MData.h"
//This class will load all the map data
class MConfigsLoader
{
    public:
        MConfigsLoader(MData &data);

        //Function to know if a file exists
        bool fileExists(const std::string path);

        //add layer load file        void addLoadFile(const std::string path);

        //Base function to load all stuff
        void load();

        //To prepare matrices of filling
        void resizeMatrices();

        //Set map size
        void loadMapSize();

        //Fill permanent configuration matrix
        void loadMatrices();

        //To set temporary matrix as same of permanent for the start of program
        void equalizeMatrices();

    private:
        //Reference to the class to modify
        MData &m_data;
        //Layer loading files list
        std::vector<std::string> m_paths;
};

#endif // MCONFIGSLOADER_H
