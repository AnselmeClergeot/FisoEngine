#ifndef TILEGROUPDRAWER_H
#define TILEGROUPDRAWER_H

#include <SFML/Graphics.hpp>

#include "RunEnvironment.h"

#include "MData.h"
#include "TileGroupData.h"

#include "EntitiesInterposing.h"

class TileGroupDrawer
{
    public:
        TileGroupDrawer(MData &mapData, TileGroupData &data, RunEnvironment &environment);

        //To know if a particular tile is visible on the screen
        bool tileIsVisible(const Vector3 coord) const;

        //Method to draw a specific layer
        void draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer,
                     const EntitiesInterposing *interposing = 0) const;

    private:
        //Reference to MData to get essential data
        MData &m_mapData;
        //Reference to the TileGroupData to get sprites to draw
        TileGroupData &m_data;
        //Reference to RunEnvironment
        RunEnvironment &m_environment;
};

#endif // TILEGROUPDRAWER_H
