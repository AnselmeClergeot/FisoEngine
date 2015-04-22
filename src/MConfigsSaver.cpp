#include "MConfigsSaver.h"

//To access usefull io functions
#include "ioFuncs.h"

MConfigsSaver::MConfigsSaver(MapData &data) : m_data(data)
{}

void MConfigsSaver::addLoadFile(const std::string path) {
    if(fileExists(path))
        m_paths.push_back(path);
}

void MConfigsSaver::resetLayerList() {
    m_paths.clear();
}

void MConfigsSaver::save() {
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
