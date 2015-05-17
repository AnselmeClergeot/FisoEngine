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
 * \file ioFuncs.hpp
 * \brief io functions
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
 *
 * ioFuncs.hpp offers io functions useful when loading files
 *
 */

#ifndef IOFUNCS_HPP
#define IOFUNCS_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace fe {

/**
* \fn bool fileExists(const std::string path)
* \brief To know if a file exists
*
* \param path The file path
* \return True if file exists and false otherwise
*/
bool fileExists(const std::string path);

}

#endif // IOFUNCS_HPP
