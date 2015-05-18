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
 * \file Color.hpp
 * \brief Definition of Color class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * Color.hpp defines the Color class
 *
 */

#ifndef COLOR_HPP
#define COLOR_HPP

namespace fe {

/**
 * \class Color
 * \brief Class that contains rgba color informations
 *
 * This class is used to store a color from its rgba informations.
 */
class Color
{
    public:
        /**
        * \fn Color()
        * \brief The class constructor
        *
        */
        Color();

        /**
        * \fn Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
        * \brief The class constructor with values
        *
        * \param r The red value
        * \param g The green value
        * \param b The blue value
        * \param a The alpha (opacity) value
        */
        Color(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);

        /**
        * \fn Color(const fe::Color& color)
        * \brief The class copy constructor
        *
        * \param color The Color model for copy
        */
        Color(const fe::Color& color);

        /**
        * \fn fe::Color& operator=(const fe::Color& color)
        * \brief The assignment operator
        *
        * \param color The Color model for assignment
        * \return The reference to this class
        */
        fe::Color& operator=(const fe::Color& color);

        unsigned int r, /*!< The red value */
                     g, /*!< The green value */
                     b, /*!< The blue value */
                     a; /*!< The alpha (opacity) value */

    private:
};

/**
* \fn bool operator==(const fe::Color& color1, const fe::Color &color2)
* \brief The == operator
*
* \param color1 The first comparison member
* \param color2 The second comparison member
* \return True if all the color values are equal, false otherwise
*/
bool operator==(const fe::Color& color1, const fe::Color &color2);

}

#endif // COLOR_HPP
