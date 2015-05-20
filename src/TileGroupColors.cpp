#include "TileGroupColors.hpp"

fe::TileGroupColors::TileGroupColors(fe::MapData &mapData, fe::TileGroupData &tilegroupData)
 : m_mapData(mapData),
   m_tilegroupData(tilegroupData)
{ }


fe::Matrix3d<fe::Color> &fe::TileGroupColors::getColors() {
    return m_tilesColors;
}

void fe::TileGroupColors::setTileColor(const fe::Vector3 coord, const fe::Color color) {
    m_tilesColors.at(coord.x, coord.y, coord.z) = color;
    applyColorOfTile(coord);
}

void fe::TileGroupColors::setTileOpacity(const fe::Vector3 coord, const unsigned int opacity) {
    m_tilesColors.at(coord.x, coord.y, coord.z).a = opacity;
    applyColorOfTile(coord);
}

void fe::TileGroupColors::setTypeColor(const unsigned int tile, const fe::Color color) {
    bool alreadyPresent(false);

    for(std::size_t i(0); i<m_types.size(); i++)
    {
        if(m_types[i]==tile)
            alreadyPresent = true;
    }

    if(!alreadyPresent)
    {
        m_types.push_back(tile);
        m_typesColors.push_back(color);
    }

    else
    {
        for(std::size_t i(0); i<m_types.size(); i++)
        {
            if(m_types[i]==tile)
                m_typesColors[i] = color;
        }
    }

    for(std::size_t x(0); x<m_tilesColors.getW(); x++)
        for(std::size_t y(0); y<m_tilesColors.getH(); y++)
            for(std::size_t z(0); z<m_tilesColors.getD(); z++)
                if(m_mapData.getTempConf().at(x, y, z)==tile)
                {
                    m_tilesColors.at(x, y, z) = color;
                    applyColorOfTile(fe::Vector3(x, y, z));
                }
}

void fe::TileGroupColors::setGroupColor(const fe::Color color) {
    m_groupColor = color;

    for(std::size_t x(0); x<m_tilesColors.getW(); x++)
        for(std::size_t y(0); y<m_tilesColors.getH(); y++)
            for(std::size_t z(0); z<m_tilesColors.getD(); z++)
            {
                m_tilesColors.at(x, y, z) = color;
                applyColorOfTile(fe::Vector3(x, y, z));
            }
}

fe::Color fe::TileGroupColors::getGroupColor() const {
    return m_groupColor;
}

void fe::TileGroupColors::applyColorOfTile(const fe::Vector3 coord) {
    m_tilegroupData.getTiles().at(coord.x, coord.y, coord.z).
    setColor(sf::Color(m_tilesColors.at(coord.x, coord.y, coord.z).r,
                       m_tilesColors.at(coord.x, coord.y, coord.z).g,
                       m_tilesColors.at(coord.x, coord.y, coord.z).b,
                       m_tilesColors.at(coord.x, coord.y, coord.z).a));
}

void fe::TileGroupColors::checkForColor(const fe::Vector3 coord, const unsigned int tile) {
    bool isSpecial(false);

    for(std::size_t i(0); i<m_types.size(); i++)
    {
        if(m_types[i]==tile)
        {
            isSpecial = true;
            m_tilesColors.at(coord.x, coord.y, coord.z) = m_typesColors[i];
        }
    }

    if(!isSpecial)
        m_tilesColors.at(coord.x, coord.y, coord.z) = fe::Color();

    applyColorOfTile(coord);
}

void fe::TileGroupColors::reloadColors() {
    for(std::size_t x(0); x<m_tilesColors.getW(); x++)
        for(std::size_t y(0); y<m_tilesColors.getH(); y++)
            for(std::size_t z(0); z<m_tilesColors.getD(); z++)
                checkForColor(fe::Vector3(x, y, z), m_mapData.getTempConf().at(x, y, z));
}

fe::Color fe::TileGroupColors::getTileColor(const fe::Vector3 coord) {
    return m_tilesColors.at(coord.x, coord.y, coord.z);
}

void fe::TileGroupColors::resetColorOf(const fe::Vector3 coord) {
    m_tilesColors.at(coord.x, coord.y, coord.z) = fe::Color();
}

fe::Color fe::TileGroupColors::getColorOfType(const unsigned int type) const {
    for(std::size_t i(0); i<m_types.size(); i++)
    {
        if(m_types[i]==type)
            return m_typesColors[i];
    }
    return fe::Color();
}
