#ifndef SLOADER_H
#define SLOADER_H

#include "MData.h"
#include "SData.h"
#include "../ExternClasses/Matrix3d.h"

class SLoader
{
    public:
        SLoader(SData &data, MData &mapData);

        //to start calculating the config vector
        void initialize();

        //To resize the config
        void resizeMatrix();

        //To fill the matrix
        void calculateMatrix();

    private:
        //Reference to the SData to load
        SData &m_data;
        //A reference to MData
        MData &m_mapData;

};

#endif // SLOADER_H
