#ifndef RUNENVIRONMENT_H
#define RUNENVIRONMENT_H

#include "../ExternClasses/Vector2.h"

class RunEnvironment
{
    public:
        RunEnvironment();
        void setWindowResolution(const Vector2 res);
        void setWindowResolution(const unsigned int w, const unsigned int h);

        Vector2 getWindowResolution() const;
    private:
        Vector2 m_windowRes;

};

#endif // RUNENVIRONMENT_H
