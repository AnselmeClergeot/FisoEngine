#include "Timer.h"

Timer::Timer() : m_clock(), m_milliseconds(0)
{}

void Timer::restart() {
    m_clock = clock();

    m_milliseconds = 0;
}

const unsigned int &Timer::getElapsedTime() {
    m_milliseconds = (clock() - m_clock) / (double)(CLOCKS_PER_SEC / 1000);

    return m_milliseconds;
}
