#include "ShadowsInterface.h"

ShadowsInterface::ShadowsInterface(SLoader &loader, SData &data, TileGroup &tilegroup) : m_loader(loader),
                                                                                         m_data(data),
                                                                                         m_tilegroup(tilegroup)
{

}

void ShadowsInterface::setTileset(const std::string path)
{
    m_tilegroup.setTilesetPath(path);
}

void ShadowsInterface::init()
{
    m_loader.initialize();
    m_tilegroup.initialize();
}

void ShadowsInterface::setOn(bool on)
{
    m_data.setOn(on);
}
