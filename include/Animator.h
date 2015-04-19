#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>

#include "MData.h"
#include "TileAnimData.h"
#include "../ExternClasses/Timer.h"
#include "../ExternClasses/Vector3.h"
#include "DynamicShader.h"

class Animator
{
    public:
        Animator(MData &mapData, TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, DynamicShader &shader);

        void resizeAnimationsDataList();

        void setAnimation(const unsigned tile, const unsigned int length);

        void setSpeed(const unsigned int speed);

        void next();

        void setSingleAnimKind(const unsigned int tile);

        void setDirectionOf(const Vector3 coord, AnimDirection direction);

        void setKindOf(const Vector3 coord, AnimKind kind);

        void setAnimStatus(const Vector3 coord, bool status);

        const TileAnimData &animAt(const unsigned int iter) const;

        //To apply the animations to the tilegroups
        void apply();


    private:

        void updateX();

        std::vector<TileAnimData> m_tileAnimationsData;
        MData &m_mapData;
        Timer m_timer;

        unsigned int m_speed;
        unsigned int m_x;
        unsigned int m_maxLength;

        //Links to tilegroups to modify
        TileGroup &m_mapTilegroup, &m_shadowsTilegroup;

        //Link to dynamic shader to change shadows from tile
        DynamicShader &m_shader;

};

#endif // ANIMATOR_H
