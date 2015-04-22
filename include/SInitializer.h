#ifndef SINITIALIZER_H
#define SINITIALIZER_H

#include "TileGroup.h"
#include "SStates.h"
#include "MapData.h"
#include "Matrix3d.h"

//This class calculates the shadows configuration in a matrix to send to the TileGroup.
class SInitializer
{
    public:
        //The only constructor
        SInitializer(TileGroup &tilegroup, SStates &states, MapData &mapData);

        //the root function that calls the functions below
        void initialize();

        //To resize the configuration matrix
        void resizeMatrix(Matrix3d &tempConf);

        //The function that call calculateShadowInConf() for all the tiles
        void fillMatrix(Matrix3d &tempConf);

        //TO calculate the shadow position generated from tile coordinates and put it into configuration
        void calculateShadowInConf(const Vector3 coord, Matrix3d &tempConf);

    private:
        //Reference to the shadows tilegroup to load
        TileGroup &m_tileGroup;
        //A reference to MData to get needed informations
        MapData &m_mapData;
        //A reference to the shadows system states, to set initialized when calculating finished
        SStates &m_states;
};

#endif // SINITIALIZER_H
