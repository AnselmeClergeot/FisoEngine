#ifndef SCREENINFOS_H
#define SCREENINFOS_H

#include "Vector2.h"

class ScreenInfos
{
    public:
        //The default constructor
        ScreenInfos();

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

#endif // SCREENINFOS_H
