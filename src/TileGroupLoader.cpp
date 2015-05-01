#include "TileGroupLoader.h"
#include "ioFuncs.h"

TileGroupLoader::TileGroupLoader(TileGroupData &data, MapData &mapData) : m_mapData(mapData),
                                                                          m_tilesetPath(""),
                                                                          m_data(data)
{ }

void TileGroupLoader::setTilesetPath(const std::string path) {
    if(fileExists(path))
        m_tilesetPath = path;
}

void TileGroupLoader::loadTileset() {
    m_data.getTileset().loadFromFile(m_tilesetPath);
}

void TileGroupLoader::resizeTileList() {
    m_data.getTiles().resize(m_mapData.getTempConf().getW(),
                             m_mapData.getTempConf().getH(),
                             m_mapData.getTempConf().getD());
}

void TileGroupLoader::setTilesTileset() {
    for(std::size_t i(0); i<m_data.getTileNumber(); i++)
        m_data.spriteAt(i).setTexture(m_data.getTileset());
}

void TileGroupLoader::setTilesRect() {
    for(std::size_t i(0); i<m_data.getTileNumber(); i++)
        m_data.updateTileFromConfig(i);
}

void TileGroupLoader::initialize() {
    loadTileset();
    resizeTileList();
    setTilesTileset();
    setTilesRect();

    //Updating the TileGroup position before the first frame
    m_data.updatePosition();
}
