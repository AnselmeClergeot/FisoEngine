#ifndef TILEGROUPDRAWER_H
#define TILEGROUPDRAWER_H

#include <SFML/Graphics.hpp>

#include "MData.h"
#include "TileGroupData.h"

class TileGroupDrawer
{
    public:
        TileGroupDrawer(MData &mapData, TileGroupData &data);

        //Method to draw if a tile is visible
        bool tileIsVisible(const Vector3 coord, sf::RenderTarget &target) const;

        //Method to draw a specific layer
        void draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer) const;

    private:
        //Reference to MData to get essential data
        MData &m_mapData;
        //Reference to the TileGroupData to get sprites, etc
        TileGroupData &m_data;
};

#endif // TILEGROUPDRAWER_H
