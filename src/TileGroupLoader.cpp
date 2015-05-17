/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "TileGroupLoader.h"
#include "ioFuncs.h"



fe::TileGroupLoader::TileGroupLoader(fe::TileGroupData &data,
                                     fe::MapData &mapData) : m_mapData(mapData),
                                                             m_tilesetPath(""),
                                                             m_data(data)
{ }

void fe::TileGroupLoader::setTilesetPath(const std::string path) {
    if(fileExists(path))
        m_tilesetPath = path;
}

void fe::TileGroupLoader::loadTileset() {
    m_data.getTileset().loadFromFile(m_tilesetPath);
}

void fe::TileGroupLoader::resizeTileList() {
    m_data.getTiles().resize(m_mapData.getTempConf().getW(),
                             m_mapData.getTempConf().getH(),
                             m_mapData.getTempConf().getD());
}

void fe::TileGroupLoader::setTilesTileset() {
    for(std::size_t i(0); i<m_data.getTileNumber(); i++)
        m_data.spriteAt(i).setTexture(m_data.getTileset());
}

void fe::TileGroupLoader::resizeOpacitiesMatrix3d() {
    m_data.getOpacities().resize(m_mapData.getTempConf().getW(),
                                 m_mapData.getTempConf().getH(),
                                 m_mapData.getTempConf().getD(),
                                 255);
}

void fe::TileGroupLoader::initialize() {
    loadTileset();
    resizeTileList();
    resizeOpacitiesMatrix3d();
    setTilesTileset();

    m_data.updatePosition();
    m_data.setGroupOpacity(m_data.getGroupOpacity());
}
