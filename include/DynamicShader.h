/**
 * \file DynamicShader.h
 * \brief Definition of DynamicShader class
 * \author AnselmeClergeot
 * \version beta
 * \date 24/04/15
 *
 * DynamicShader.h defines the DynamicShader class
 *
 */

#ifndef DYNAMICSHADER_H
#define DYNAMICSHADER_H
#include "MapData.h"
#include "TileGroup.h"
#include "Vector3.h"

/**
 * \class DynamicShader
 * \brief Class that shades the map dynamically
 *
 * This class is charged to dynamically shades the map by acting on the shadows TileGroup.
 */
class DynamicShader
{
    public:

        /**
        * \fn DynamicShader(MapData &mapData, TileGroup &mapTg, TileGroup &shadowsTg)
        * \brief The class constructor
        *
        * \param mapData Reference to the MapData to get needed data
        * \param mapTg Reference to the map TileGroup to get tiles informations
        * \param shadowsTg Reference to the shadows TileGroup to modify
        */
        DynamicShader(MapData &mapData, TileGroup &mapTg, TileGroup &shadowsTg);

        /**
        * \fn void updateShading(const Vector3 coord)
        * \brief To update the shading of a specific map tile
        *
        * \param coord The tile coordinates
        * \return void
        */
        void updateShading(const Vector3 coord);

        /**
        * \fn void updateShadingOfAll()
        * \brief To update the shading of all the map
        *
        * \return void
        */
        void updateShadingOfAll();

        /**
        * \fn void updateOpacityOfAll()
        * \brief To update the shadows from the tiles opacity of all the map
        *
        * \return void
        */
        void updateOpacityOfAll();

        /**
        * \fn void updateOpacityOfType(const unsigned int type)
        * \brief To update the shadows of a specific tile number, to update shadows opacity
        *
        * \param type The tile type from its number
        * \return void
        */
        void updateOpacityOfType(const unsigned int type);

        /**
        * \fn void updateOpacityOfSpecific(const Vector3 coord)
        * \brief To update the shadows of a specific type, to update shadow opacity
        *
        * \param coord The tile coordinates
        * \return void
        */
        void updateOpacityOfSpecific(const Vector3 coord);

        /**
        * \fn void updateTileFromAnim(const Vector3 tileCoord, const unsigned int animX)
        * \brief To update the shadow of a specific tile to link with the animation state of this tile
        *
        * \param tileCoord The tile coordinates
        * \param animX The animation frame of the tile
        * \return void
        */
        void updateTileFromAnim(const Vector3 tileCoord, const unsigned int animX);

    private:

        /**
        * \fn unsigned int getShadowZ(const Vector3 tileCoord)
        * \brief To get the shadow z coordinate from a specific tile coordinates
        *
        * \param tileCoord The tile coordinates
        * \return The z coordinate of the engendered shadow in an unsigned int
        */
        unsigned int getShadowZ(const Vector3 tileCoord);

        /**
        * \fn bool haveShadowVisible(const Vector3 tileCoord)
        * \brief To know if a tile have a shadow taking in account the depth
        *
        * \param tileCoord The tile coordinates
        * \return True if the tile have a shadow, false otherwise
        */
        bool haveShadowVisible(const Vector3 tileCoord);

        MapData &m_mapData; /*!< The reference to the MapData to get needed data*/

        TileGroup &m_mapTg; /*!< The reference to the map TileGroup to access tile images data*/

        TileGroup &m_shadowsTg; /*!< The reference to the shadows TileGroup to modify*/
};

#endif // DYNAMICSHADER_H
