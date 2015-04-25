/**
 * \file Vector3.h
 * \brief Definition of Vector3 class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * Vector3.h defines the Vector3 class
 *
 */

#ifndef VECTOR3_H
#define VECTOR3_H

/**
 * \class Vector3
 * \brief This class is a container of 3 int x, y and z
 *
 * This class can be used to store 3D coordinates.
 */
class Vector3
{
    public:

        /**
        * \fn Vector3()
        * \brief The default class constructor
        *
        */
        Vector3();

        /**
        * \fn Vector3(const int x, const int y, const int z)
        * \brief The constructor with x, y and z values
        *
        * \param x The x value
        * \param y The y value
        * \param z The z value
        */
        Vector3(const int x, const int y, const int z);

        /**
        * \fn Vector3(const Vector3 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        */
        Vector3(const Vector3 &vec);

        /**
        * \fn Vector3& operator=(const Vector3 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        * \return Reference to the set Vector3
        */
        Vector3& operator=(const Vector3 &vec);

        /**
        * \fn void operator+=(const Vector3 &vec)
        * \brief The += operator
        *
        * \param vec The model to add to the Vector3
        * \return void
        */
        void operator+=(const Vector3 &vec);

        /**
        * \fn void operator-=(const Vector3 &vec)
        * \brief The -= operator
        *
        * \param vec The model to subtract to the Vector3
        * \return void
        */
        void operator-=(const Vector3 &vec);

        int x, /*!< The x element */

            y, /*!< The y element */

            z; /*!< The z element */
};

/**
* \fn Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
* \brief The + operator
*
* \param v1 The first addition member
* \param v2 The second addition member
* \return The result Vector3
*/
Vector3 operator+(const Vector3 &v1, const Vector3 &v2);

/**
* \fn Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
* \brief The - operator
*
* \param v1 The first subtraction member
* \param v2 The second subtraction member
* \return The result Vector3
*/
Vector3 operator-(const Vector3 &v1, const Vector3 &v2);

/**
* \fn bool operator==(const Vector3 &v1, const Vector3 &v2)
* \brief The == operator
*
* \param v1 The first comparison member
* \param v2 The second comparison member
* \return True if v1==v2, false otherwise
*/
bool operator==(const Vector3 &v1, const Vector3 &v2);
#endif // VECTOR3_H
