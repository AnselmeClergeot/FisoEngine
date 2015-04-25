/**
 * \file TileAnimData.h
 * \brief Definition of TileAnimData class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * TileAnimData.h defines the TileAnimData class
 *
 */

#ifndef TILEANIMDATA_H
#define TILEANIMDATA_H
#include "Vector2.h"

/*!  AnimKind defines the tile animation type*/
enum AnimKind {Global, /* !< A global animation kind like water, etc. */
               Single /* !< A single animation kind like door, explosion, etc. */ };

/*!  AnimDirection defines the tile animation direction*/
enum AnimDirection {Right, /* !< Right direction animation */
                    Left /* !< Left direction animation */ };

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
