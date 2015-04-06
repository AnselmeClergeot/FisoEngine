#ifndef TILEGROUPDRAWER_H
#define TILEGROUPDRAWER_H

#include <SFML/Graphics.hpp>

#include "MData.h"
#include "TileGroupData.h"
#include "RunEnvironment.h"

#include "EntitiesInterposing.h"

//This class draws the layer of the tilegroup
class TileGroupDrawer
{
    public:
        //The only constructor, called by TileGroup class
        TileGroupDrawer(MData &mapData, TileGroupData &data, RunEnvironment &environment);

        //Method to draw a specific layer (and to interpose entities between tiles)
        void draw(sf::RenderTarget& target, const unsigned int layer,
                  const EntitiesInterposing *interposing = 0) const;

    private:
        //Reference to MData, to get needed informations
        MData &m_mapData;
        //Reference to TileGroupData to get the sprites to draw
        TileGroupData &m_data;
        //Reference to RunEnvironment, to get screen informations
        RunEnvironment &m_environment;
};

#endif // TILEGROUPDRAWER_H
