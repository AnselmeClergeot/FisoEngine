#ifndef MAP_H
#define MAP_H


#include <SFML/Graphics.hpp>

#include "MData.h"
#include "MConfigsLoader.h"
#include "MConfigsSaver.h"

#include "TileGroup.h"

#include "ShadowsInterface.h"
#include "SInitializer.h"
#include "SStates.h"
#include "DynamicShader.h"

//This class is the user interface
class Map : public sf::Drawable
{
    public:
        Map();

        //Method to start map "creation" or save it
        void init();
        void save();

        //All these methods are indirect setters
        void addLayerFile(const std::string path);
        void setTileset(const std::string path);
        void setTileSize(const Vector2 size);
        void setTileSize(const unsigned int w, const unsigned int h);
        void setTileBaseHeight(const unsigned int h);
        void setInvisibleTile(const unsigned int tile);
        void addTranslucentTile(const unsigned int tile);

        //To set a tile at specific world coordinate
        void setTileAt(const Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw);
        void setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                       bool modifConf, bool modifDraw);
        //To set a specific tile opacity
        void setSpecificOpacity(const Vector3 coord, const unsigned int opacity);
        void setSpecificOpacity(const unsigned int x,const unsigned int y,const unsigned int z,
                                const unsigned int opacity);
        //To set a global tile number opacity
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);
        //To set all tiles opacity
        void setGroupOpacity(const unsigned int opacity);

        //Positioning methods
        void setPosition(const Vector2 pos);
        void setPosition(const unsigned int x, const unsigned int y);

        void move(const Vector2 rate);
        void move(const unsigned int rx, const unsigned int ry);

        //Draw method
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //Accessors useful for user
        Vector3 getDimensions() const;
        Vector2 getPosition() const;
        Vector2 getTileSize() const;
        unsigned int getTileBaseHeight() const;
        unsigned int getInvisibleTile() const;
        bool isTranslucent(const unsigned int tile) const;
        unsigned int getTileAt(const Vector3 coord);
        unsigned int getTileAt(const unsigned int x, const unsigned int y, const unsigned int z);
        unsigned int getGroupOpacity() const;

        unsigned int getTileOpacity(const Vector3 coord);
        unsigned int getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z);

        //Accessor to shadows interface
        ShadowsInterface &shadows();

    private:
        //Map----------------------------------

        //Map data loader/saver and data container
        MData m_data;
        MConfigsLoader m_configsLoader;
        MConfigsSaver m_configsSaver;
        //The map TileGroup
        TileGroup m_tileGroup;

        //Shadows----------------------------------
        //The shadows tile-group
        TileGroup m_shadowsTilegroup;
        //The shadows states
        SStates m_shadowsStates;
        //The initializer
        SInitializer m_shadowsInitializer;
        //The interface for user
        ShadowsInterface m_shadowsInterface;
        //The dynamic shader
        DynamicShader m_dynamicShader;
};

#endif // MAP_H
