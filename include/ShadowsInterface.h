#ifndef SHADOWSINTERFACE_H
#define SHADOWSINTERFACE_H

#include "SLoader.h"
#include "SData.h"
#include "TileGroup.h"

class ShadowsInterface
{
    public:
        ShadowsInterface(SLoader &loader, SData &data, TileGroup &tilegroup);
        //To set the shadows tileset path
        void setTileset(const std::string path);

        //To start loading/calculating all shadows stuff
        void init();

        //To set shadows on
        void setOn(bool on);
    private:
        //Reference to the shadows loader
        SLoader &m_loader;
        //Reference to the shadows data
        SData &m_data;
        //Reference to the shadows tile-group
        TileGroup &m_tilegroup;
};

#endif // SHADOWSINTERFACE_H
