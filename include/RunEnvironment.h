#ifndef RUNENVIRONMENT_H
#define RUNENVIRONMENT_H

#include "../ExternClasses/Vector2.h"

class RunEnvironment
{
    public:
        //The default constructor
        RunEnvironment();

        //To set the window resolution
        void setWindowResolution(const Vector2 res);

        //To set the window resolution
        void setWindowResolution(const unsigned int w, const unsigned int h);

        //To get the window resolution
        Vector2 getWindowResolution() const;

    private:
        //The window resolution
        Vector2 m_windowRes;
};

#endif // RUNENVIRONMENT_H
