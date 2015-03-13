#include "MDataLoader.h"

MDataLoader::MDataLoader(MData &data) : m_data(data),
                                        m_paths()
{

}

bool MDataLoader::fileExists(const std::string path)
{
    std::ifstream file(path.c_str());
    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}

void MDataLoader::addLoadFile(const std::string path)
{
    if(fileExists(path))
        m_paths.push_back(path);
}

void MDataLoader::load()
{
    loadMapSize();
    resizeMatrices();
    loadMatrices();
    equalizePermWithTemp();
}

void MDataLoader::save()
{
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

void MDataLoader::resizeMatrices()
{
    m_data.getTempConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y);
    m_data.getPermConf().resize(m_data.getSize().x, m_data.getSize().x, m_data.getSize().y);
}

void MDataLoader::loadMapSize()
{
    std::ifstream file;
    file.open(m_paths[0].c_str());

    int width(0);

    std::string l;

    while(std::getline(file, l))
        width++;

    file.close();

    m_data.setSize(Vector2(width, m_paths.size()));
}

void MDataLoader::loadMatrices()
{
    std::ifstream file;
    std::string line("");
    for(int z(0); z<m_paths.size(); z++)
    {
        file.open(m_paths[z].c_str());
        std::string index("");
        int count(z*m_data.getSize().x*m_data.getSize().x);

        while(!file.eof())
        {
            std::getline(file, line);
            for(int i(0); i<line.length(); i++)
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

void MDataLoader::equalizePermWithTemp()
{
    m_data.getTempConf() = m_data.getPermConf();
}
