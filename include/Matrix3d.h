#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <iostream>
#include <vector>
#include <assert.h>
#include <stdlib.h>
#include "Vector2.h"
//This is a simple implementation of a 3D matrix. Feel free to use as you like.

class Matrix3d
{
    public:
        Matrix3d();
        Matrix3d(const Matrix3d &matrix);
        Matrix3d& operator=(const Matrix3d &matrix);
        Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d);
        Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int f);
        void resize(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill);
        void clear();

        //Accessors
        int &at(const unsigned int x, const unsigned int y, const unsigned int z);
        int &at(const unsigned int index);
        unsigned int getSize() const;
        unsigned int getW() const;
        unsigned int getH() const;
        unsigned int getD() const;
        unsigned int get3dIter(const unsigned int x, const unsigned int y, const unsigned int z);
        unsigned int get2dIter(const unsigned int x, const unsigned int y);
        Vector2 get2dFromIter(const unsigned int iter);
        std::vector<int> getData() const;

    private:
        unsigned int m_w, m_h, m_d;
        std::vector<int> m_data;
};

#endif // MATRIX3D_H
