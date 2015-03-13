#include "MData.h"

MData::MData() : m_tempConf(), m_permConf(),
                 m_size(), m_position(),
                 m_tileSize(), m_tileBaseHeight(0)
{

}

//Setters
void MData::setSize(const Vector2 size)
{
    m_size = size;
}

void MData::setPosition(const Vector2 position)
{
    m_position = position;
}

void MData::move(const Vector2 rate)
{
    m_position+=rate;
}

void MData::setTileSize(const Vector2 size)
{
    m_tileSize = size;
}

void MData::setTileBaseHeight(const unsigned int h)
{
    m_tileBaseHeight = h;
}

//Accessors
Matrix3d &MData::getTempConf()
{
    return m_tempConf;
}

Matrix3d &MData::getPermConf()
{
    return m_permConf;
}

Vector2 MData::getSize() const
{
    return m_size;
}

Vector2 MData::getPosition() const
{
    return m_position;
}

Vector2 MData::getTileSize() const
{
    return m_tileSize;
}

unsigned int MData::getTileBaseHeight() const
{
    return m_tileBaseHeight;
}
