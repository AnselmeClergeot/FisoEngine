/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * \file Vector3.hpp
 * \brief Definition of Vector3 class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Vector3.hpp defines the Vector3 class
 *
 */

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

namespace fe {
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
        * \fn Vector3(const fe::Vector3 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        */
        Vector3(const fe::Vector3 &vec);

        /**
        * \fn fe::Vector3& operator=(const fe::Vector3 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        * \return Reference to the set Vector3
        */
        fe::Vector3& operator=(const fe::Vector3 &vec);

        /**
        * \fn void operator+=(const fe::Vector3 &vec)
        * \brief The += operator
        *
        * \param vec The model to add to the Vector3
        * \return void
        */
        void operator+=(const fe::Vector3 &vec);

        /**
        * \fn void operator-=(const fe::Vector3 &vec)
        * \brief The -= operator
        *
        * \param vec The model to subtract to the Vector3
        * \return void
        */
        void operator-=(const fe::Vector3 &vec);

        int x, /*!< The x element */

            y, /*!< The y element */

            z; /*!< The z element */
};

/**
* \fn fe::Vector3 operator+(const fe::Vector3 &v1, const fe::Vector3 &v2)
* \brief The + operator
*
* \param v1 The first addition member
* \param v2 The second addition member
* \return The result Vector3
*/
fe::Vector3 operator+(const fe::Vector3 &v1, const fe::Vector3 &v2);

/**
* \fn fe::Vector3 operator-(const fe::Vector3 &v1, const fe::Vector3 &v2)
* \brief The - operator
*
* \param v1 The first subtraction member
* \param v2 The second subtraction member
* \return The result Vector3
*/
fe::Vector3 operator-(const fe::Vector3 &v1, const fe::Vector3 &v2);

/**
* \fn bool operator==(const fe::Vector3 &v1, const fe::Vector3 &v2)
* \brief The == operator
*
* \param v1 The first comparison member
* \param v2 The second comparison member
* \return True if v1==v2, false otherwise
*/
bool operator==(const fe::Vector3 &v1, const fe::Vector3 &v2);

}

#endif // VECTOR3_HPP
