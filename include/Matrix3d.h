/**
 * \file Matrix3d.h
 * \brief Definition of Matrix3d class
 * \author AnselmeClergeot
 * \version beta
 * \date 01/05/15
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
 * \brief This class is a template class that offers simple 3D arrays manipulations.
 *
 * Matrix3d is used to handle 3D arrays of any type. It emulates 1D array into 3D one.
 * For the user it works like a std::vector, but with 3D functionalities.
 */

template<typename T>
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
        * \return Reference to the set Matrix3d
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
        * \fn Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const T fill)
        * \brief Size constructor with default value
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        * \param fill The default filling value
        */
        Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const T fill);

        /**
        * \fn void resize(const unsigned int w, const unsigned int h, const unsigned int d, const T fill)
        * \brief To resize the matrix with specific size and default value
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        * \param fill The default filling value
        * \return void
        */
        void resize(const unsigned int w, const unsigned int h, const unsigned int d, const T fill);

        /**
        * \fn void resize(const unsigned int w, const unsigned int h, const unsigned int d)
        * \brief To resize the matrix with specific size
        *
        * \param w The matrix width
        * \param h The matrix height
        * \param d The matrix depth
        * \return void
        */
        void resize(const unsigned int w, const unsigned int h, const unsigned int d);

        /**
        * \fn void clear()
        * \brief To clear the matrix
        *
        * \return void
        */
        void clear();

        /**
        * \fn T &at(const unsigned int x, const unsigned int y, const unsigned int z)
        * \brief To get a reference to the object at 3D coordinates
        *
        * \param x The x coordinate
        * \param y The y coordinate
        * \param z The z coordinate
        * \return A reference to the object at the informed coordinates
        */
        T &at(const unsigned int x, const unsigned int y, const unsigned int z);

        /**
        * \fn T &at(const unsigned int index)
        * \brief To get a reference to the object at 1D index
        *
        * \param index The index
        * \return A reference to the object at the informed index
        */
        T &at(const unsigned int index);

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
        * \fn std::vector<T> getData() const
        * \brief To get the matrix entire data in std::vector
        *
        * \return The data vector
        */
        std::vector<T> getData() const;

    private:
        unsigned int m_w, /*!< The matrix width */

        m_h, /*!< The matrix height */

        m_d; /*!< The matrix depth */

        std::vector<T> m_data /*!< The matrix data in a std::vector */;
};

template<typename T>
Matrix3d<T>::Matrix3d() : m_w(0), m_h(0), m_d(0), m_data(0)
{ }

template<typename T>
Matrix3d<T>::Matrix3d(const Matrix3d &matrix) : m_w(matrix.m_w), m_h(matrix.m_h), m_d(matrix.m_d), m_data(matrix.m_data)
{ }

template<typename T>
Matrix3d<T>& Matrix3d<T>::operator=(const Matrix3d &matrix) {
    m_w = matrix.m_w;
    m_h = matrix.m_h;
    m_d = matrix.m_d;
    m_data = matrix.m_data;

    return *this;
}

template<typename T>
Matrix3d<T>::Matrix3d(const unsigned int w,
                   const unsigned int h,
                   const unsigned int d) : m_w(w),
                                           m_h(h),
                                           m_d(d),
                                           m_data(w*h*d)
{ }

template<typename T>
Matrix3d<T>::Matrix3d(const unsigned int w,
                   const unsigned int h,
                   const unsigned int d,
                   const T fill) : m_w(w),
                                              m_h(h),
                                              m_d(d),
                                              m_data(w*h*d, fill)
{ }

template<typename T>
void Matrix3d<T>::resize(const unsigned int w,
                      const unsigned int h,
                      const unsigned int d,
                      const T fill) {
    m_w = w;
    m_h = h;
    m_d = d;
    m_data.resize(w*h*d, fill);
}

template<typename T>
void Matrix3d<T>::resize(const unsigned int w,
                      const unsigned int h,
                      const unsigned int d) {
    m_w = w;
    m_h = h;
    m_d = d;
    m_data.resize(w*h*d);
}

template<typename T>
void Matrix3d<T>::clear() {
    m_data.clear();
}

template<typename T>
T &Matrix3d<T>::at(const unsigned int x, const unsigned int y, const unsigned int z) {
    assert(x<m_w && y<m_h && z<m_d);
    return m_data[x + m_w * (y + m_w* z)];
}

template<typename T>
T &Matrix3d<T>::at(const unsigned int index) {
    assert(index<m_data.size());
    return m_data[index];
}

template<typename T>
unsigned int Matrix3d<T>::getSize() const {
    return m_w*m_h*m_d;
}

template<typename T>
unsigned int Matrix3d<T>::getW() const {
    return m_w;
}

template<typename T>
unsigned int Matrix3d<T>::getH() const {
    return m_h;
}

template<typename T>
unsigned int Matrix3d<T>::getD() const {
    return m_d;
}

template<typename T>
unsigned int Matrix3d<T>::get3dIter(const unsigned int x, const unsigned int y, const unsigned int z) {
    return x + m_w * (y + m_w* z);
}

template<typename T>
unsigned int Matrix3d<T>::get2dIter(const unsigned int x, const unsigned int y) {
    return x * m_w + y;
}

template<typename T>
Vector2 Matrix3d<T>::get2dFromIndex(const unsigned int index) {
    return Vector2(div(index, m_w).quot, div(index, m_w).rem);
}

template<typename T>
std::vector<T> Matrix3d<T>::getData() const {
    return m_data;
}

#endif // MATRIX3D_H
