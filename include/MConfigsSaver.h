#ifndef MCONFIGSSAVER_H
#define MCONFIGSSAVER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MData.h"

class MConfigsSaver
{
    public:
        MConfigsSaver(MData &data);

        //Function to know if a file exists
        bool fileExists(const std::string path);

        //add layer load file        void addLoadFile(const std::string path);

        //Function to save tile-configurations into start file
        void save();

    private:
        //Reference to MData
        MData &m_data;
        //Layer loading files list
        std::vector<std::string> m_paths;
};

#endif // MCONFIGSSAVER_H
