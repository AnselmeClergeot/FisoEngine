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
enum AnimKind {Global /*!< A global animation kind like water, etc. */,
               Single /*!< A single animation kind like door, explosion, etc. */ };

/*!  AnimDirection defines the tile animation direction*/
enum AnimDirection {Right /*!< Right direction animation */,
                    Left /*!< Left direction animation */ };

/**
 * \class TileAnimData
 * \brief This class represents a tile animation
 *
 * This class represent one animation for one tile.
 * It contains all animation data: direction, length, etc.
 */
class TileAnimData
{
    public:

        /**
        * \fn TileAnimData()
        * \brief The default constructor
        *
        */
        TileAnimData();

        /**
        * \fn void setKind(const AnimKind kind)
        * \brief To set the kind of the animation
        *
        * \param kind The animation kind
        * \return void
        */
        void setKind(const AnimKind kind);

        /**
        * \fn void setDirection(const AnimDirection direction)
        * \brief To set the animation direction
        *
        * \param direction The animation direction
        * \return void
        */
        void setDirection(const AnimDirection direction);

        /**
        * \fn void setLength(const unsigned int length)
        * \brief To set the animation length
        *
        * \param length The animation length in frames
        * \return void
        */
        void setLength(const unsigned int length);

        /**
        * \fn void setStatus(const bool status)
        * \brief To set the animation status (playing/not playing)
        *
        * \param status True for playing and false otherwise
        * \return void
        */
        void setStatus(const bool status);

        /**
        * \fn void updateX()
        * \brief To make progress the present animation frame, taking in account direction, etc.
        *
        * \return void
        */
        void updateX();

        /**
        * \fn void resetX()
        * \brief To reset the present frame
        *
        * \return void
        */
        void resetX();

        /**
        * \fn AnimKind getKind() const
        * \brief To get the kind of the animation
        *
        * \return The animation kind
        */
        AnimKind getKind() const;

        /**
        * \fn AnimDirection getDirection() const
        * \brief To get the direction of the animation
        *
        * \return The animation direction
        */
        AnimDirection getDirection() const;

        /**
        * \fn unsigned int getLength() const
        * \brief To get the animation length
        *
        * \return The animation length in frames
        */
        unsigned int getLength() const;

        /**
        * \fn unsigned int getX() const
        * \brief To get the animation present frame
        *
        * \return The animation present frame
        */
        unsigned int getX() const;

        /**
        * \fn bool getStatus() const
        * \brief To get the animation playing status
        *
        * \return The animation playing status: true for playing, false otherwise
        */
        bool getStatus() const;

    private:

        AnimKind m_kind; /*!< The kind of the animation */

        AnimDirection m_direction; /*!< The direction of the animation */

        unsigned int m_x; /*!< The present frame of the animation */

        bool m_status; /*!< The playing status of the animation */

        bool m_waitStatus; /*!< The waiting status for the next frame */

        unsigned int m_length; /*!< The length of the animation in frames*/
};

#endif // TILEANIMDATA_H
