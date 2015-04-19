#ifndef ANIMATIONSAPPLICATOR_H
#define ANIMATIONSAPPLICATOR_H

#include "TileGroup.h"
#include "Animator.h"

class AnimationsApplicator
{
    public:
        AnimationsApplicator(TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, Animator &animator);
    private:
        TileGroup &m_mapTilegroup;
        TileGroup &m_shadowsTilegroup;
        Animator &m_animator;
};

#endif // ANIMATIONSAPPLICATOR_H
