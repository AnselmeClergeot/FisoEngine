/**
 * \file Matrix3d.h
 * \brief Definition of Matrix3d class
 * \author AnselmeClergeot
 * \version beta
 * \date 25/04/15
 *
 * Matrix3d.h defines the Matrix3d class
 *
 */

#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include "Vector2.h"

/**
 * \class Matrix3d
 * \brief This class offers simple 3D arrays manipulations
 *
 * Matrix3d is used to handle 3D arrays. It emulates 1D array into 3D one.
 * For the user it works like a std::vector, but with 3D functionalities.
 */
class Matrix3d
{
    public:

        /**
        * \fn Matrix3d()
        * \brief The default constructor
        *
        */
        Matrix3d();

        /**
        * \fn Matrix3d(const Matrix3d &matrix)
        * \brief The copy constructor
        *
        * \param matrix Reference to the copy model
        */
        Matrix3d(const Matrix3d &matrix);

        /**
        * \fn Matrix3d& operator=(const Matrix3d &matrix)
        * \brief The assignment operator
        *
        * \param matrix Reference to the copy model
        */
        Matrix3d& operator=(const Matrix3d &matrix);

        /**
        * \fn Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d)
        * \brief Size constructor
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        */
        Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d);

        /**
        * \fn Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill)
        * \brief Size constructor with default value
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        * \param fill The default filling value
        */
        Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill);

        /**
        * \fn void resize(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill)
        * \brief To resize the matrix with specific size
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        * \param fill The default filling value
        * \return void
        */
        void resize(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill);

        /**
        * \fn void clear()
        * \brief To clear the matrix
        *
        * \return void
        */
        void clear();

        /**
        * \fn int &at(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the value at 3D coordinates
        *
        * \param x The x coordinate
        * \param y The y coordinate
        * \param z The z coordinate
        * \return The value at the informed coordinates
        */
        int &at(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn int &at(const unsigned int index)
        * \brief To get the value at 1D index
        *
        * \param index The index
        * \return The value at the informed index
        */
        int &at(const unsigned int index);

        /**
        * \fn unsigned int getSize() const
        * \brief To get the matrix 1D size
        *
        * \return The matrix 1D size
        */
        unsigned int getSize() const;

        /**
        * \fn unsigned int getW() const
        * \brief To get the matrix width
        *
        * \return The matrix width
        */
        unsigned int getW() const;

        /**
        * \fn unsigned int getH() const
        * \brief To get the matrix height
        *
        * \return The matrix height
        */
        unsigned int getH() const;

        /**
        * \fn unsigned int getD() const
        * \brief To get the matrix depth
        *
        * \return The matrix depth
        */
        unsigned int getD() const;

        /**
        * \fn unsigned int get3dIter(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get the 1D index from 3D coordinates
        *
        * \param x The x coordinate
        * \param y The y coordinate
        * \param z The z coordinate
        * \return The 1D index
        */
        unsigned int get3dIter(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn unsigned int get2dIter(const unsigned int x, const unsigned int y)
        * \brief To get a 1D index from 2D coordinates
        *
        * \param x The x coordinate
        * \param y The y coordinate
        * \return The 1D index
        */
        unsigned int get2dIter(const unsigned int x, const unsigned int y);

        /**
        * \fn Vector2 get2dFromIndex(const unsigned int index)
        * \brief To get a a 2D coordinates from 1D index
        *
        * \param index The 1D index
        * \return The 2D coordinates
        */
        Vector2 get2dFromIndex(const unsigned int index);

        /**
        * \fn std::vector<int> getData() const
        * \brief To get the matrix entire data in std::vector
        *
        * \return The matrix data
        */
        std::vector<int> getData() const;

    private:
        unsigned int m_w, /* !< The matrix width */

        m_h, /* !< The matrix height */

        m_d; /* !< The matrix depth */

        std::vector<int> m_data /* !< The matrix data */;
};

#endif // MATRIX3D_H
