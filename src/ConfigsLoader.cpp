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

#include "ConfigsLoader.h"
#include "ioFuncs.h"

fe::ConfigsLoader::ConfigsLoader(fe::MapData &data) : m_data(data), m_paths()
{ }

void fe::ConfigsLoader::addLoadFile(const std::string path) {
    if(fileExists(path))
        m_paths.push_back(path);
}

void fe::ConfigsLoader::resetLayerList() {
        m_paths.clear();
}

void fe::ConfigsLoader::load() {
    loadMapSize();
    resizeMatrices();
    loadMatrices();
    equalizeMatrices();
}

void fe::ConfigsLoader::resizeMatrices() {
    m_data.getTempConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y, 0);
    m_data.getPermConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y, 0);
}

void fe::ConfigsLoader::loadMapSize() {
    std::ifstream file;
    file.open(m_paths[0].c_str());

    int width(0);
    std::string l;

    while(std::getline(file, l))
        width++;

    file.close();

    m_data.setSize(fe::Vector2(width, m_paths.size()));
}

void fe::ConfigsLoader::loadMatrices() {
    std::ifstream file;
    std::string line("");

    for(std::size_t z(0); z<m_paths.size(); z++)
    {
        file.open(m_paths[z].c_str());
        std::string index("");
        int count(z*m_data.getSize().x*m_data.getSize().x);

        while(!file.eof())
        {
            std::getline(file, line);
            for(std::size_t i(0); i<line.length(); i++)
            {
                if(line[i]!=',') index+=line[i];
                if(line[i]==',' || i==line.length()-1)
                {
                    m_data.getPermConf().at(count) = atoi(index.c_str());
                    index="";
                    count++;
                }
            }
        }
        file.close();
    }
}

void fe::ConfigsLoader::equalizeMatrices() {
    m_data.getTempConf() = m_data.getPermConf();
}
