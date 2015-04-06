#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include "RunEnvironment.h"

#include "MData.h"
#include "MConfigsLoader.h"
#include "MConfigsSaver.h"

#include "TileGroup.h"

#include "ShadowsInterface.h"
#include "SInitializer.h"
#include "SStates.h"
#include "DynamicShader.h"

#include "EntitiesContainer.h"
#include "EntitiesInterface.h"
#include "EntitiesInterposing.h"

#include "IsometricMath.h"

//This class is the user interface to interact with different domains of the map.
class Map : public sf::Drawable
{
    public:
        //The only constructor for the user
        Map(RunEnvironment &environment);

        //To call map creation
        void init();
        //To save the map
        void save();

        //To add a layer file for loading configuration
        void addLayerFile(const std::string path);

        //To set the map tileset path
        void setTileset(const std::string path);

        //To set the tile size
        void setTileSize(const Vector2 size);
        void setTileSize(const unsigned int w, const unsigned int h);

        //To set the tile base height
        void setTileBaseHeight(const unsigned int h);

        //To set the invisible tile number
        void setInvisibleTile(const unsigned int tile);

        //To add a translucent tile number to the list
        void addTranslucentTile(const unsigned int tile);
        //To remove a translucent tile number in the list
        void removeTranslucentTile(const unsigned int tile);

        //To set a tile from number at specific world coordinates
        void setTileAt(const Vector3 coord, const unsigned int tile, bool modifConf, bool modifDraw);
        void setTileAt(const unsigned int x, const unsigned int y, const unsigned int z, const unsigned int tile,                       bool modifConf, bool modifDraw);

        //To set the opacity of a particular tile
        void setSpecificOpacity(const Vector3 coord, const unsigned int opacity);
        void setSpecificOpacity(const unsigned int x,const unsigned int y,const unsigned int z,
                                const unsigned int opacity);

        //To set the opacity of all the tiles of a particular type
        void setTypeOpacity(const unsigned int tile, const unsigned int opacity);

        //To set the same opacity to all map tiles
        void setGroupOpacity(const unsigned int opacity);

        //To set map position in pixels
        void setPosition(const Vector2 pos);
        void setPosition(const unsigned int x, const unsigned int y);

        //To move the map position
        void move(const Vector2 rate);
        void move(const unsigned int rx, const unsigned int ry);

        //To draw the entire map (with shadows and entities)
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        //To get the map dimensions
        Vector3 getDimensions() const;

        //To get map position
        Vector2 getPosition() const;

        //To get tile size
        Vector2 getTileSize() const;

        //To get tile base height
        unsigned int getTileBaseHeight() const;

        //To get the invisible tile number
        unsigned int getInvisibleTile() const;

        //To know if a tile number correspond to a translucent tile
        bool isTranslucent(const unsigned int tile) const;

        //To get the tile number at a specific 3D coordinates
        unsigned int getTileAt(const Vector3 coord);
        unsigned int getTileAt(const unsigned int x, const unsigned int y, const unsigned int z);

        //To get the map opacity (the tilegroup opacity)
        unsigned int getGroupOpacity() const;

        //To get the opacity of a particular tile at 3D coordinates
        unsigned int getTileOpacity(const Vector3 coord);
        unsigned int getTileOpacity(const unsigned int x, const unsigned int y, const unsigned int z);

        //To get the tile pointed by 2D screen coordinates
        Vector2 getTileCoordAtPixels(const Vector2 pixels, const unsigned int layer) const;

        //Accessor to shadows interface
        ShadowsInterface &shadows();

        //Accessor to the entities interface
        EntitiesInterface &entities();

    private:
        //Running environment----------------------
        RunEnvironment &m_environment;
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

        //Entities---------------------------------
        //The entities container
        EntitiesContainer m_entityContainer;
        //The interface
        EntitiesInterface m_entityInterface;
        //For entities map interposing
        EntitiesInterposing m_interposing;
};

#endif // MAP_H
