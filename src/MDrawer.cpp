#include "MDrawer.h"

MDrawer::MDrawer(MData &data) : m_texture(),
                                m_tileSprites(),
                                m_data(data)
{

}

void MDrawer::resizeTileList(const unsigned int s)
{
    m_tileSprites.resize(s);
}

sf::Texture &MDrawer::getTexture()
{
    return m_texture;
}

sf::Sprite &MDrawer::tileAt(const unsigned int i)
{
    return m_tileSprites[i];
}

void MDrawer::updateAt(const unsigned int i)
{
    frameTile(Vector2(0, m_data.getTempConf().at(i)), i);
}

void MDrawer::updatePosition()
{
    for(int z(0); z<m_data.getSize().y; z++)
        for(int x(0); x<m_data.getSize().x; x++)
            for(int y(0); y<m_data.getSize().x; y++)
                setTilePosition(Vector3(x, y, z));
}

void MDrawer::setTilePosition(const Vector3 coord)
{
    m_tileSprites[m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
    setPosition(toIsometricPosition(coord, m_data).x, toIsometricPosition(coord, m_data).y);
}

void MDrawer::frameTile(const Vector2 coord, const unsigned int i)
{
    m_tileSprites[i].setTextureRect(sf::IntRect(coord.x*m_data.getTileSize().x,
                                                coord.y*m_data.getTileSize().y,
                                                m_data.getTileSize().x,
                                                m_data.getTileSize().y));
}

void MDrawer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int z(0); z<m_data.getSize().y; z++)
        for(int x(0); x<m_data.getSize().x; x++)
            for(int y(0); y<m_data.getSize().x; y++)
    {
        if(tileIsVisible(Vector3(x, y, z), target))
            target.draw(m_tileSprites[m_data.getTempConf().get3dIter(x, y, z)]);
    }

}

bool MDrawer::tileIsVisible(const Vector3 coord, sf::RenderTarget &target) const
{
    return (m_tileSprites[m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            getPosition().x+m_data.getTileSize().x>0 &&
            m_tileSprites[m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            getPosition().y+m_data.getTileSize().y>0 &&
            m_tileSprites[m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            getPosition().x < target.getSize().x &&
            m_tileSprites[m_data.getTempConf().get3dIter(coord.x, coord.y, coord.z)].
            getPosition().y < target.getSize().y);
}
