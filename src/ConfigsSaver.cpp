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

#include "ConfigsSaver.h"
#include "ioFuncs.h"

ConfigsSaver::ConfigsSaver(MapData &data) : m_data(data), m_paths()
{ }

void ConfigsSaver::addLoadFile(const std::string path) {
    if(fileExists(path))
        m_paths.push_back(path);
}

void ConfigsSaver::resetLayerList() {
    m_paths.clear();
}

void ConfigsSaver::save() {
    std::ofstream file;

    for(std::size_t z(0); z<m_paths.size(); z++)
    {
        file.open(m_paths[z].c_str());
        for(std::size_t y(0); y<m_data.getSize().x; y++)
        {
            for(std::size_t x(0); x<m_data.getSize().x; x++)
            {
                file << m_data.getPermConf().at(x, y, z);
                if(x+1<m_data.getSize().x)
                    file << ",";
            }
            file << "\n";
        }
        file.close();
    }
}
