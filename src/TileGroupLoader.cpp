#include "TileGroupLoader.h"

TileGroupLoader::TileGroupLoader(TileGroupData &data) :
    m_tilesetPath(""), m_data(data)
{

}

bool TileGroupLoader::fileExists(const std::string path)
{
    std::ifstream file(path.c_str());
    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}

void TileGroupLoader::setTilesetPath(const std::string path)
{
    if(fileExists(path))
        m_tilesetPath = path;
}

void TileGroupLoader::loadTileset()
{
    m_data.getTileset().loadFromFile(m_tilesetPath);
}

void TileGroupLoader::resizeTileList()
{
    m_data.getTiles().resize(m_data.getSize());
}

void TileGroupLoader::setTilesTileset()
{
    for(int i(0); i<m_data.getSize(); i++)
        m_data.spriteAt(i).setTexture(m_data.getTileset());
}

void TileGroupLoader::setTilesRect()
{
    for(int i(0); i<m_data.getSize(); i++)
        m_data.updateTile(i);
}

void TileGroupLoader::initialize()
{
    loadTileset();
    resizeTileList();
    setTilesTileset();
    setTilesRect();
    m_data.updatePosition();
}
