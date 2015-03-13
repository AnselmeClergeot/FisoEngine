#include "MDrawerLoader.h"

MDrawerLoader::MDrawerLoader(MDrawer &drawer, MData &data) : m_drawer(drawer), m_data(data)
{

}

void MDrawerLoader::load()
{
    loadTexture();
    m_drawer.resizeTileList(m_data.getPermConf().getSize());
    setTilesTex();
    setTilesRect();
    m_drawer.updatePosition();
}

bool MDrawerLoader::fileExists(const std::string path)
{
    std::ifstream file(path.c_str());
    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}

void MDrawerLoader::setSpritesheetPath(const std::string path)
{
    if(fileExists(path))
        m_path = path;
}

void MDrawerLoader::loadTexture()
{
    m_drawer.getTexture().loadFromFile(m_path);
}


void MDrawerLoader::setTilesTex()
{
    for(int i(0); i<m_data.getPermConf().getSize(); i++)
        m_drawer.tileAt(i).setTexture(m_drawer.getTexture());
}

void MDrawerLoader::setTilesRect()
{
    for(int i(0); i<m_data.getPermConf().getSize(); i++)
        m_drawer.updateAt(i);
}
