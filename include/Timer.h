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
