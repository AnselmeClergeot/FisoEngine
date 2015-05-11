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

/**
 * \file ConfigsSaver.h
 * \brief Definition of ConfigsSaver class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ConfigsSaver.h defines the ConfigsSaver class
 *
 */

#ifndef CONFIGSSAVER_H
#define CONFIGSSAVER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "MapData.h"

namespace fe {
/**
 * \class ConfigsSaver
 * \brief Class that saves map configurations
 *
 * This class is charged to saves the map configurations into the layer files.
 */
class ConfigsSaver
{
    public:

        /**
        * \fn ConfigsSaver(MapData &data)
        * \brief The class constructor
        *
        * \param data Reference to the MapData to get needed data
        * \return void
        */
        ConfigsSaver(MapData &data);

        /**
        * \fn void addLoadFile(const std::string path)
        * \brief To add a layer file
        *
        * \param path The path of the layer file
        * \return void
        */        void addLoadFile(const std::string path);

        /**
        * \fn void resetLayerList()
        * \brief To reset the layer configuration files list
        *
        * \return void
        */
        void resetLayerList();

        /**
        * \fn void save()
        * \brief To save the map configurations into the files
        *
        * \return void
        */
        void save();

    private:

        MapData &m_data; /*!< Reference to the MapData to get needed data */

        std::vector<std::string> m_paths; /*!< The layer files path list */
};
}

#endif // CONFIGSSAVER_H
