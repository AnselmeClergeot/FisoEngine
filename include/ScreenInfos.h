/**
 * \file ScreenInfos.h
 * \brief Definition of ScreenInfos class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * ScreenInfos.h defines the ScreenInfos class
 *
 */

#ifndef SCREENINFOS_H
#define SCREENINFOS_H
#include "Vector2.h"

/**
 * \class ScreenInfos
 * \brief This class is used to inform environment screen data
 *
 * The user have to instantiate an instance of this class and informs some screen parameters: dimensions, etc.
 * The instance of the class will be useful for different Map aspects. (Drawing)
 */
class ScreenInfos
{
    public:

        /**
        * \fn ScreenInfos()
        * \brief The class default constructor
        *
        */
        ScreenInfos();

        /**
        * \fn void setWindowResolution(const Vector2 res)
        * \brief To set the run window dimensions
        *
        * \param res The window resolution
        * \return void
        */
        void setWindowResolution(const Vector2 res);

        /**
        * \fn void setWindowResolution(const unsigned int w, const unsigned int h)
        * \brief To set the run window dimensions
        *
        * \param w The window width in pixels
        * \param h The window height in pixels
        * \return void
        */
        void setWindowResolution(const unsigned int w, const unsigned int h);

        /**
        * \fn Vector2 getWindowResolution() const
        * \brief To get the run window dimensions
        *
        * \return The window dimensions in pixels
        */
        Vector2 getWindowResolution() const;

    private:

        Vector2 m_windowRes; /*!< The window resolution in pixels */
};

#endif // SCREENINFOS_H
