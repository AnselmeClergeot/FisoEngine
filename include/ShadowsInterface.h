/**
 * \file ShadowsInterface.h
 * \brief Definition of ShadowsInterface class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * ShadowsInterface.h defines the ShadowsInterface class
 *
 */

#ifndef SHADOWSINTERFACE_H
#define SHADOWSINTERFACE_H
#include "ShadowsInitializer.h"
#include "TileGroup.h"

/**
 * \class ShadowsInterface
 * \brief This class is the user interface with the shadows system
 *
 * This class is the user interface to operate with the shadows system.
 */
class ShadowsInterface
{
    public:

        /**
        * \fn ShadowsInterface(ShadowsInitializer &loader, ShadowsSystemStates &states, TileGroup &tilegroup)
        * \brief The class constructor
        *
        * \param loader Reference to the ShadowsInitializer to call shadows calculation
        * \param states Reference to the ShadowsSystemStates to modify the states
        * \param tilegroup Reference to the shadows TileGroup to act on it
        */
        ShadowsInterface(ShadowsInitializer &loader, ShadowsSystemStates &states, TileGroup &tilegroup);

        /**
        * \fn void setTileset(const std::string path)
        * \brief To set the shadows tileset image path
        *
        * \param path The tileset image path
        * \return void
        */
        void setTileset(const std::string path);

        /**
        * \fn void setOpacity(const unsigned int opacity)
        * \brief To set the opacity of the shadows
        *
        * \param opacity The opacity value, from 0 to 255
        * \return void
        */
        void setOpacity(const unsigned int opacity);

        /**
        * \fn void init()
        * \brief To call shadows calculation
        *
        * \return void
        */
        void init();

        /**
        * \fn void setOn(bool on)
        * \brief To set the shadows on
        *
        * \param on True for on and false for off
        * \return void
        */
        void setOn(bool on);

    private:

        ShadowsInitializer &m_initializer; /*!< Reference to the ShadowsInitializer to call initialization*/

        ShadowsSystemStates &m_states; /*!< Reference to the ShadowsSystemStates to change states */

        TileGroup &m_tilegroup; /*!< Reference to the shadows TileGroup  to act directly on it when needed*/
};

#endif // SHADOWSINTERFACE_H
