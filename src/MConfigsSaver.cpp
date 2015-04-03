#include "MConfigsSaver.h"

MConfigsSaver::MConfigsSaver(MData &data) : m_data(data)
{}

bool MConfigsSaver::fileExists(const std::string path) {
    std::ifstream file(path.c_str());

    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}

void MConfigsSaver::addLoadFile(const std::string path) {
    if(fileExists(path))
        m_paths.push_back(path);
}

void MConfigsSaver::save() {
    std::ofstream file;

    for(int z(0); z<m_paths.size(); z++)
    {
        file.open(m_paths[z].c_str());
        for(int y(0); y<m_data.getSize().x; y++)
        {
            for(int x(0); x<m_data.getSize().x; x++)
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
