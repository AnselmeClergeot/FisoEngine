#ifndef SINITIALIZER_H
#define SINITIALIZER_H

#include "MData.h"
#include "SStates.h"
#include "TileGroup.h"
#include "../ExternClasses/Matrix3d.h"

class SInitializer
{
    public:
        SInitializer(TileGroup &tilegroup, SStates &states, MData &mapData);

        //to start calculating the config vector
        void initialize();

        //To resize the config
        void resizeMatrix(Matrix3d &tempConf);

        //To fill the matrix
        void fillMatrix(Matrix3d &tempConf);

        //Calculate shade render from tile coordinates
        void calculateShadowInConf(const Vector3 coord, Matrix3d &tempConf);

    private:
        //Reference to the shadows tilegroup
        TileGroup &m_tileGroup;
        //A reference to MData
        MData &m_mapData;
        //A reference to the states
        SStates &m_states;

};

#endif // SINITIALIZER_H
