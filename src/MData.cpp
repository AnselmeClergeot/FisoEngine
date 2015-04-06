#include "MData.h"

MData::MData() : m_tempConf(), m_permConf(),
                 m_size(), m_position(),
                 m_tileSize(), m_tileBaseHeight(0), m_invisibleTile(0), m_translucentTiles()
{}

void MData::setSize(const Vector2 size) {
    m_size = size;
}

void MData::setPosition(const Vector2 position) {
    m_position = position;
}

void MData::move(const Vector2 rate) {
    m_position+=rate;
}

void MData::setTileSize(const Vector2 size) {
    m_tileSize = size;
}

void MData::setTileBaseHeight(const unsigned int h) {
    m_tileBaseHeight = h;
}

void MData::setInvisibleTile(const unsigned int tile) {
    m_invisibleTile = tile;
}

void MData::addTranslucentTile(const unsigned int tile) {
    m_translucentTiles.push_back(tile);
}

void MData::removeTranslucentTile(const unsigned int tile) {
    for(int i(0); i<m_translucentTiles.size(); i++)
    {
        if(m_translucentTiles[i]==tile)
            m_translucentTiles.erase(m_translucentTiles.begin()+i);
    }
}

Matrix3d &MData::getTempConf() {
    return m_tempConf;
}

Matrix3d &MData::getPermConf() {
    return m_permConf;
}

Vector2 MData::getSize() const {
    return m_size;
}

Vector2 MData::getPosition() const {
    return m_position;
}

Vector2 MData::getTileSize() const {
    return m_tileSize;
}

unsigned int MData::getTileBaseHeight() const {
    return m_tileBaseHeight;
}

unsigned int MData::getInvisibleTile() const {
    return m_invisibleTile;
}

bool MData::isTranslucent(const unsigned int tile) const {
    return std::find(m_translucentTiles.begin(), m_translucentTiles.end(), tile)!=m_translucentTiles.end();
}
