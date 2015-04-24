/**
 * \file ConfigsLoader.h
 * \brief Definition of ConfigsLoader class
 * \author AnselmeClergeot
 * \version beta
 * \date 24/04/15
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
