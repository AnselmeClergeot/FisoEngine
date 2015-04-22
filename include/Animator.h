#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>

#include "MData.h"
#include "TileAnimData.h"
#include "Timer.h"
#include "Vector3.h"
#include "DynamicShader.h"

class Animator
{
    friend class Map;

    public:
        Animator(MData &mapData, TileGroup &mapTilegroup, TileGroup &shadowsTilegroup, DynamicShader &shader);

        void setAnimation(const unsigned tile, const unsigned int length);

        void setSpeed(const unsigned int speed);

        void next();

        void setSingleAnimKind(const unsigned int tile);

        void setDirectionOf(const Vector3 coord, const AnimDirection direction);

        void setKindOf(const Vector3 coord, const AnimKind kind);

        void launchAnimation(const Vector3 coord);
        void launchAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

        void stopAnimation(const Vector3 coord);
        void stopAnimation(const unsigned int x, const unsigned int y, const unsigned int z);

    private:

        void updateX();

        void apply();

        void resizeAnimationsDataList();

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
