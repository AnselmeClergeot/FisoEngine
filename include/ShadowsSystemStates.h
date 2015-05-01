/**
 * \file ShadowsSystemStates.h
 * \brief Definition of ShadowsSystemStates class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ShadowsSystemStates.h defines the ShadowsSystemStates class
 *
 */

#ifndef SHADOWSSYSTEMSTATES_H
#define SHADOWSSYSTEMSTATES_H

/**
 * \class ShadowsSystemStates
 * \brief This class is the state container of the shadows system.
 *
 * This class is used by the engine to store the different shadows system states like on/off, initialized, etc.
 */
class ShadowsSystemStates
{
    public:

        /**
        * \fn ShadowsSystemStates()
        * \brief The default class constructor
        *
        */
        ShadowsSystemStates();

        /**
        * \fn void setOn(bool on)
        * \brief To set the shadows system on/off
        *
        * \param on True for on and false for off
        * \return void
        */
        void setOn(bool on);

        /**
        * \fn void setInitialized()
        * \brief To set the shadows system initialized state to true
        *
        * \return void
        */
        void setInitialized();

        /**
        * \fn bool isOn() const
        * \brief To know if the shadows system is on or off
        *
        * \return True for on and false for off
        */
        bool isOn() const;

        /**
        * \fn bool isInitialized() const
        * \brief To know if the shadows system is initialized or not
        *
        * \return True for initialized and false otherwise
        */
        bool isInitialized() const;

    private:

        bool m_on, /*!< The on/off state */

        m_initialized; /*!< The initialized or not state */
};

#endif // SHADOWSSYSTEMSTATES_H
