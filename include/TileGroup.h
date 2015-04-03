#ifndef TILEGROUP_H
#define TILEGROUP_H

#include "TileGroupData.h"
#include "TileGroupLoader.h"
#include "TileGroupDrawer.h"

class TileGroup
{
    public:
        TileGroup(MData &mapData);

        //To set the tileset path
        void setTilesetPath(const std::string path);

        //To set the configuration of the tilegrouo
        void setConfiguration(Matrix3d &matrix);

        //To set a tile number at specific coordinates
        void setTileAt(const Vector3 coord, const unsigned int index);

        //To start initializing all the TileGroupData stuff
        void initialize();

        //To update the global tile-group position
        void updatePosition();

        //To set the opacity of a specific tile
        void setSpecificOpacity(const unsigned int index, const unsigned int opacity);
        //To set a global tile number opacity
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);
        //To set the base opacity of all the tiles
        void setGroupOpacity(const unsigned int opacity);

        //To draw a specific tile layer
        void draw(sf::RenderTarget& target, sf::RenderStates states, const unsigned int layer) const;

        //To get specific tile opacity
        unsigned int getTileOpacity(const unsigned int index) const;
        //To get group opacity
        unsigned int getGroupOpacity() const;


    private:
        //Data container and loader and drawer
        TileGroupData m_data;
        TileGroupLoader m_loader;
        TileGroupDrawer m_drawer;
};

#endif // TILEGROUP_H
