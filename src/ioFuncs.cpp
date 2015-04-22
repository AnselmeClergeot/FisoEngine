#include "ioFuncs.h"

bool fileExists(const std::string path) {
    std::ifstream file(path.c_str());

    if(!file.good())
    {
        std::cout << "Enable to find file " << path << std::endl;
        exit(1);
    }
    return file.good();
}
