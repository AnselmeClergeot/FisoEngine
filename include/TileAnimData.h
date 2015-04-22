#ifndef TILEANIMDATA_H
#define TILEANIMDATA_H

#include "Vector2.h"

enum AnimKind {Global, Single};
enum AnimDirection {Right, Left};

class TileAnimData
{
    public:
        TileAnimData();

        void setKind(const AnimKind kind);

        void setDirection(const AnimDirection direction);

        void setLength(const unsigned int length);

        void setStatus(const bool status);

        void updateX();

        void resetX();

        AnimKind getKind() const;

        AnimDirection getDirection() const;

        unsigned int getLength() const;

        unsigned int getX() const;

        bool getStatus() const;

    private:
        AnimKind m_kind;
        AnimDirection m_direction;
        unsigned int m_x;
        bool m_status;
        unsigned int m_length;
};

#endif // TILEANIMDATA_H
