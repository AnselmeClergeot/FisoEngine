#ifndef ANIMATIONSINTERFACE_H
#define ANIMATIONSINTERFACE_H

#include "Animator.h"
#include "../ExternClasses/Vector3.h"

class AnimationsInterface
{
    public:
        AnimationsInterface(Animator &animator);

        void setSpeed(const unsigned int speed);

        void setAnimation(const unsigned tile, const unsigned int length);

        void setSingleAnimKind(const unsigned int tile);

        void setDirectionOf(const Vector3 coord, AnimDirection direction);
        void setDirectionOf(const unsigned int x, const unsigned int y, const unsigned int z, AnimDirection                             direction);

        void setKindOf(const Vector3 coord, AnimKind kind);
        void setKindOf(const unsigned int x, const unsigned int y, const unsigned int z, AnimKind kind);

        void launchAnimation(const Vector3 coord);
        void launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

        void stopAnimation(const Vector3 coord);
        void stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

        void next();
    private:
        Animator &m_animator;
};

#endif // ANIMATIONSINTERFACE_H
