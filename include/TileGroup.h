#ifndef TILEGROUP_H
#define TILEGROUP_H

#include "TileGroupData.h"
#include "TileGroupLoader.h"
#include "TileGroupDrawer.h"

class TileGroup
{
    public:
        TileGroup(Matrix3d &config, MData &mapData);

        //To set the tileset path
        void setTilesetPath(const std::string path);

        //To start initializing all the TileGroupData stuff
        void initialize();

        //To update the global tile-group position
        void updatePosition();

        //To update a tile appearance from the configuration matrix
        void updateTile(const unsigned int index);

        //To set a certain tile frame
        void frameTile(const unsigned int index, const Vector2 coord);

        //To draw a specific tile layer
        void draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer) const;

    private:
        //Data container and loader and drawer
        TileGroupData m_data;
        TileGroupLoader m_loader;
        TileGroupDrawer m_drawer;
};

#endif // TILEGROUP_H
