#ifndef TIMER_H
#define TIMER_H

#include <time.h>

class Timer
{
    public:
        Timer();

        //To restart the clock()
        void restart();

        //To get the elapsed time
        const unsigned int &getElapsedTime();

    private:
        //The clock
        clock_t m_clock;
        //The elapsed time in milliseconds
        unsigned int m_milliseconds;
};

#endif // TIMER_H
