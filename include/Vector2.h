/**
 * \file Vector2.h
 * \brief Definition of Vector2 class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * Vector2.h defines the Vector2 class
 *
 */

#ifndef VECTOR2_H
#define VECTOR2_H

/**
 * \class Vector2
 * \brief This class is a container of 2 int x and y
 *
 * This class can be used to store 2D coordinates.
 */
class Vector2
{
    public:

        /**
        * \fn Vector2()
        * \brief The default class constructor
        *
        */
        Vector2();

        /**
        * \fn Vector2(const int x, const int y)
        * \brief The constructor with x and y values
        *
        * \param x The x value
        * \param y The y value
        */
        Vector2(const int x, const int y);

        /**
        * \fn Vector2(const Vector2 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        */
        Vector2(const Vector2 &vec);

        /**
        * \fn Vector2& operator=(const Vector2 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        * \return Reference to the set Vector2
        */
        Vector2& operator=(const Vector2 &vec);

        /**
        * \fn void operator+=(const Vector2 &vec)
        * \brief The += operator
        *
        * \param vec The model to add to the Vector2
        * \return void
        */
        void operator+=(const Vector2 &vec);

        /**
        * \fn void operator-=(const Vector2 &vec)
        * \brief The -= operator
        *
        * \param vec The model to subtract to the Vector2
        * \return void
        */
        void operator-=(const Vector2 &vec);

        int x, /*!< The x element */

            y; /*!< The y element */
};

/**
* \fn Vector2 operator+(const Vector2 &v1, const Vector2 &v2)
* \brief The + operator
*
* \param v1 The first addition member
* \param v2 The second addition member
* \return The result Vector2
*/
Vector2 operator+(const Vector2 &v1, const Vector2 &v2);

/**
* \fn Vector2 operator-(const Vector2 &v1, const Vector2 &v2)
* \brief The - operator
*
* \param v1 The first subtraction member
* \param v2 The second subtraction member
* \return The result Vector2
*/
Vector2 operator-(const Vector2 &v1, const Vector2 &v2);

/**
* \fn bool operator==(const Vector2 &v1, const Vector2 &v2)
* \brief The == operator
*
* \param v1 The first comparison member
* \param v2 The second comparison member
* \return True if v1==v2, false otherwise
*/
bool operator==(const Vector2 &v1, const Vector2 &v2);

#endif // VECTOR2_H
