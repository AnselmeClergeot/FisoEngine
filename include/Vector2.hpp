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
 * \file Vector2.hpp
 * \brief Definition of Vector2 class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Vector2.hpp defines the Vector2 class
 *
 */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace fe {
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
        * \fn Vector2(const fe::Vector2 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        */
        Vector2(const fe::Vector2 &vec);

        /**
        * \fn fe::Vector2& operator=(const fe::Vector2 &vec)
        * \brief The copy constructor
        *
        * \param vec The copy model
        * \return Reference to the set Vector2
        */
        fe::Vector2& operator=(const fe::Vector2 &vec);

        /**
        * \fn void operator+=(const fe::Vector2 &vec)
        * \brief The += operator
        *
        * \param vec The model to add to the Vector2
        * \return void
        */
        void operator+=(const fe::Vector2 &vec);

        /**
        * \fn void operator-=(const fe::Vector2 &vec)
        * \brief The -= operator
        *
        * \param vec The model to subtract to the Vector2
        * \return void
        */
        void operator-=(const fe::Vector2 &vec);

        int x, /*!< The x element */

            y; /*!< The y element */
};

/**
* \fn fe::Vector2 operator+(const fe::Vector2 &v1, const fe::Vector2 &v2)
* \brief The + operator
*
* \param v1 The first addition member
* \param v2 The second addition member
* \return The result Vector2
*/
fe::Vector2 operator+(const fe::Vector2 &v1, const fe::Vector2 &v2);

/**
* \fn fe::Vector2 operator-(const fe::Vector2 &v1, const fe::Vector2 &v2)
* \brief The - operator
*
* \param v1 The first subtraction member
* \param v2 The second subtraction member
* \return The result Vector2
*/
fe::Vector2 operator-(const fe::Vector2 &v1, const fe::Vector2 &v2);

/**
* \fn bool operator==(const fe::Vector2 &v1, const fe::Vector2 &v2)
* \brief The == operator
*
* \param v1 The first comparison member
* \param v2 The second comparison member
* \return True if v1==v2, false otherwise
*/
bool operator==(const fe::Vector2 &v1, const fe::Vector2 &v2);

}
#endif // VECTOR2_HPP
