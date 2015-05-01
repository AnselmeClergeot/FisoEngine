/**
 * \file Timer.h
 * \brief Definition of Timer class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Timer.h defines the Timer class
 *
 */

#ifndef TIMER_H
#define TIMER_H
#include <time.h>

/**
 * \class Timer
 * \brief This class is an extremely simple timer
 *
 * This class is counting the elapsed time in milliseconds since last restart
 */
class Timer
{
    public:

        /**
        * \fn Timer()
        * \brief The class default constructor
        *
        */
        Timer();

        /**
        * \fn void restart()
        * \brief To restart the Timer
        *
        * \return void
        */
        void restart();

        /**
        * \fn const unsigned int &getElapsedTime()
        * \brief To get the elapsed time since last restart
        *
        * \return The elapsed time in milliseconds
        */
        const unsigned int &getElapsedTime();

    private:

        clock_t m_clock; /*!< The clock_t used to get CPU time */

        unsigned int m_milliseconds; /*!< The elapsed time  */
};

#endif // TIMER_H
