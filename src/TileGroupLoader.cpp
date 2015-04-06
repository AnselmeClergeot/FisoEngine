#include "TileGroupLoader.h"

//To access file-loading usefull functions
#include "LoadingFuncs.h"

TileGroupLoader::TileGroupLoader(TileGroupData &data) : m_tilesetPath(""), m_data(data)
{}

void TileGroupLoader::setTilesetPath(const std::string path) {
    if(fileExists(path))
        m_tilesetPath = path;
}

void TileGroupLoader::loadTileset() {
    m_data.getTileset().loadFromFile(m_tilesetPath);
}

void TileGroupLoader::resizeTileList() {
    m_data.getTiles().resize(m_data.getTileNumber());
}

void TileGroupLoader::setTilesTileset() {
    for(int i(0); i<m_data.getTileNumber(); i++)
        m_data.spriteAt(i).setTexture(m_data.getTileset());
}

void TileGroupLoader::setTilesRect() {
    for(int i(0); i<m_data.getTileNumber(); i++)
        m_data.updateTileFromConfig(i);
}

void TileGroupLoader::initialize() {
    loadTileset();
    resizeTileList();
    setTilesTileset();
    setTilesRect();

    //Updating the loaded TileGroup position before the first frame
    m_data.updateTileGroupPosition();
}
