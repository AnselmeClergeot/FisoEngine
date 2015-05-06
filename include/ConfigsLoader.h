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
 * \file ConfigsLoader.h
 * \brief Definition of ConfigsLoader class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ConfigsLoader.h defines the ConfigsLoader class
 *
 */

#ifndef CONFIGSLOADER_H
#define CONFIGSLOADER_H
#include <fstream>
#include "MapData.h"

/**
 * \class ConfigsLoader
 * \brief Class that charges map configurations
 *
 * This class is charged to load the map configurations from the layer files.
 */
class ConfigsLoader
{
    public:

        /**
        * \fn ConfigsLoader(MapData &data)
        * \brief The class constructor
        *
        * \param data Reference to the MapData to get needed data
        * \return void
        */
        ConfigsLoader(MapData &data);

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
        * \fn void load()
        * \brief To call the loading of the configurations
        *
        * \return void
        */
        void load();

    private:

        /**
        * \fn void resizeMatrices()
        * \brief To resize the configuration matrices
        *
        * \return void
        */
        void resizeMatrices();

        /**
        * \fn void loadMapSize()
        * \brief To set the map size from the reading of one of the layer file
        *
        * \return void
        */
        void loadMapSize();

        /**
        * \fn void loadMatrices()
        * \brief To read the layer files and fill the matrices
        *
        * \return void
        */
        void loadMatrices();

        /**
        * \fn void equalizeMatrices()
        * \brief To set the map temporary configuration as the same of the permanent one
        *
        * \return void
        */
        void equalizeMatrices();

        MapData &m_data; /*!< The reference to the MapData to get needed data */

        std::vector<std::string> m_paths; /*!< The layer files path list */
};

#endif // CONFIGSLOADER_H
