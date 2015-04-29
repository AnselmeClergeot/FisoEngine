#include "ConfigsLoader.h"
#include "ioFuncs.h"

ConfigsLoader::ConfigsLoader(MapData &data) : m_data(data), m_paths()
{ }

void ConfigsLoader::addLoadFile(const std::string path) {
    if(fileExists(path))
        m_paths.push_back(path);
}

void ConfigsLoader::resetLayerList() {
        m_paths.clear();
}

void ConfigsLoader::load() {
    loadMapSize();
    resizeMatrices();
    loadMatrices();
    equalizeMatrices();
}

void ConfigsLoader::resizeMatrices() {
    m_data.getTempConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y, 0);
    m_data.getPermConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y, 0);
}

void ConfigsLoader::loadMapSize() {
    std::ifstream file;
    file.open(m_paths[0].c_str());

    int width(0);
    std::string l;

    while(std::getline(file, l))
        width++;

    file.close();

    m_data.setSize(Vector2(width, m_paths.size()));
}

void ConfigsLoader::loadMatrices() {
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

void ConfigsLoader::equalizeMatrices() {
    m_data.getTempConf() = m_data.getPermConf();
}
