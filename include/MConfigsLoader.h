#ifndef MCONFIGSLOADER_H
#define MCONFIGSLOADER_H
#include <fstream>

#include "MData.h"

//This class load the map configurations from loading files.
class MConfigsLoader
{
    public:
        //The only constructor
        MConfigsLoader(MData &data);

        //To add a loading file (layer)        void addLoadFile(const std::string path);

        //Root function that call functions below
        void load();

        //To resize the temporary and permanent matrices
        void resizeMatrices();

        //To set the map dimensions from files size
        void loadMapSize();

        //To fill the two matrices from the values in the loading files
        void loadMatrices();

        //To set temporary matrix as same of permanent for the start of program
        void equalizeMatrices();

    private:
        //Reference to MData to load its configurations
        MData &m_data;
        //Loading files paths list
        std::vector<std::string> m_paths;
};

#endif // MCONFIGSLOADER_H
