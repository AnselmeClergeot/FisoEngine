/**
 * \file ConfigsSaver.h
 * \brief Definition of ConfigsSaver class
 * \author AnselmeClergeot
 * \version beta
 * \date 24/04/15
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

#endif // CONFIGSSAVER_H
