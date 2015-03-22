#ifndef SDATA_H
#define SDATA_H

#include "../ExternClasses/Matrix3d.h"
#include "../ExternClasses/Vector3.h"
#include "MData.h"
#include "TileGroup.h"

class SData
{
    public:
        SData(MData &mapData);
        //To set on
        void setOn(bool on);
        //To set initialized
        void setInitialized();

        //To get a reference to the matrix
        Matrix3d &getMatrix();

        //To update shading from new tile coord
        void setNewTile(const Vector3 coord, TileGroup &tilegroup);

        //To get initialized/on states
        bool isOn() const;
        bool isInitialized() const;


    private:
        //Reference to the MData
        MData &m_mapData;
        //The configuration matrix
        Matrix3d m_matrix;
        //The initialized/on states
        bool m_on, m_initialized;
};

#endif // SDATA_H
