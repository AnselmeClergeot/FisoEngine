#ifndef TILEGROUP_H
#define TILEGROUP_H

#include "RunEnvironment.h"

#include "TileGroupData.h"
#include "TileGroupLoader.h"
#include "TileGroupDrawer.h"

//This class is the interface that warps the loader, data and drawer
class TileGroup
{
    public:
        //The only constructor
        TileGroup(MData &mapData, RunEnvironment &environment);

        //To set the tilegroup tileset path
        void setTilesetPath(const std::string path);

        //To set the configuration of the tilegrouo
        void setConfiguration(Matrix3d &matrix);

        //To set a tile at specific coordinates
        void setTileAt(const Vector3 coord, const unsigned int index);

        //The root function that calls loader to start initialization
        void initialize();

        //To update the tilegroup position
        void updatePosition();

        //To set the opacity of a specific tile
        void setSpecificOpacity(const unsigned int index, const unsigned int opacity);

        //To set the opacity of all tiles of same type
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);

        //To set the base opacity of the tilegroup
        void setGroupOpacity(const unsigned int opacity);

        //To call drawing a specific tilegroup layer
        void draw(sf::RenderTarget& target, const unsigned int layer,
                  const EntitiesInterposing *interposing = 0) const;

        //To get specific tile opacity
        unsigned int getTileOpacity(const unsigned int index) const;

        //To get the tilegroup opacity
        unsigned int getGroupOpacity() const;

    private:
        //Data container
        TileGroupData m_data;
        //The tilegroup
        TileGroupLoader m_loader;
        //The tilegroup drawer
        TileGroupDrawer m_drawer;
};

#endif // TILEGROUP_H
