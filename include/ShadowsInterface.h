#ifndef SHADOWSINTERFACE_H
#define SHADOWSINTERFACE_H

#include "SInitializer.h"
#include "TileGroup.h"

class ShadowsInterface
{
    public:
        ShadowsInterface(SInitializer &loader, SStates &states, TileGroup &tilegroup);
        //To set the shadows tileset path
        void setTileset(const std::string path);

        //To set the shadows opacity
        void setOpacity(const unsigned int opacity);

        //To start loading/calculating all shadows stuff
        void init();

        //To set shadows on
        void setOn(bool on);
    private:
        //Reference to the shadows loader
        SInitializer &m_initializer;
        //Reference to the shadows data
        SStates &m_states;
        //Reference to the shadows tile-group
        TileGroup &m_tilegroup;
};

#endif // SHADOWSINTERFACE_H
