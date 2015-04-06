#ifndef SHADOWSINTERFACE_H
#define SHADOWSINTERFACE_H

#include "SInitializer.h"
#include "TileGroup.h"

class ShadowsInterface
{
    public:
        //The only constructor
        ShadowsInterface(SInitializer &loader, SStates &states, TileGroup &tilegroup);

        //To set the shadows tileset path
        void setTileset(const std::string path);

        //To set the shadows opacity
        void setOpacity(const unsigned int opacity);

        //The function that calls the init() loader function
        void init();

        //To set shadows system on
        void setOn(bool on);

    private:
        //Reference to the shadows loader to call initialization when user wants
        SInitializer &m_initializer;
        //Reference to the shadows data to set on/off on user demand
        SStates &m_states;
        //Reference to the shadows tile-group to apply user modifications
        TileGroup &m_tilegroup;
};

#endif // SHADOWSINTERFACE_H
