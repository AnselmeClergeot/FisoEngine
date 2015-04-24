/**
 * \file ioFuncs.h
 * \brief io functions
 * \author AnselmeClergeot
 * \version beta
 * \date 24/04/15
 *
 * ioFuncs.h offers io functions useful when loading files
 *
 */

#ifndef IOFUNCS_H
#define IOFUNCS_H
#include <iostream>
#include <fstream>
#include <cstdlib>

/**
* \fn bool fileExists(const std::string path)
* \brief To know if a file exists
*
* \param path The file path
* \return True if file exists and false otherwise
*/
bool fileExists(const std::string path);

#endif // IOFUNCS_H
