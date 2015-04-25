/**
 * \file ShadowsInitializer.h
 * \brief Definition of ShadowsInitializer class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * ShadowsInitializer.h defines the ShadowsInitializer class
 *
 */

#ifndef SHADOWSINITIALIZER_H
#define SHADOWSINITIALIZER_H
#include "TileGroup.h"
#include "ShadowsSystemStates.h"
#include "MapData.h"
#include "Matrix3d.h"

/**
 * \class ShadowsInitializer
 * \brief This class calculates the shadows configuration at start of the system
 *
 * This class calculates the position of the shadows in a Matrix3d at the shadows system start.
 * Then this Matrix3d is sent to the shadows TileGroup to set it for drawing.
 */
class ShadowsInitializer
{
    public:

        /**
        * \fn ShadowsInitializer(TileGroup &tilegroup, ShadowsSystemStates &states, MapData &mapData)
        * \brief The class constructor
        *
        * \param tilegroup Reference to the shadows TileGroup to send condifuration
        * \param states Reference to the ShadowsSystemStates to modify states
        * \param mapData Reference to the MapData to get useful map data
        */
        ShadowsInitializer(TileGroup &tilegroup, ShadowsSystemStates &states, MapData &mapData);

        /**
        * \fn void initialize()
        * \brief To call shadows system first calculation
        *
        * \return void
        */
        void initialize();

    private:

        /**
        * \fn void resizeMatrix(Matrix3d &tempConf)
        * \brief To resize the temporary shadows configuration
        *
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void resizeMatrix(Matrix3d &tempConf);

        /**
        * \fn void fillMatrix(Matrix3d &tempConf)
        * \brief To call filling the temporary configuration with calculated values
        *
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void fillMatrix(Matrix3d &tempConf);

        /**
        * \fn void calculateShadowInConf(const Vector3 coord, Matrix3d &tempConf)
        * \brief To calculate a generated shadow from a map tile coordinates
        *
        * \param coord The tile coordinates
        * \param tempConf The temporary Matrix3d for shadows configuration
        * \return void
        */
        void calculateShadowInConf(const Vector3 coord, Matrix3d &tempConf);

        TileGroup &m_tileGroup; /* !< The reference to the shadows TileGroup */

        MapData &m_mapData; /* !< The reference to the MapData to access useful map data */

        ShadowsSystemStates &m_states; /* !< The reference to the ShadowsSystemStates  */
};

#endif // SHADOWSINITIALIZER_H
