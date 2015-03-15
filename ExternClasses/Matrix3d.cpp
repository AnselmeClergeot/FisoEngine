#include "Matrix3d.h"

//This is a simple implementation of a 3D matrix. Feel free to use as you like.

Matrix3d::Matrix3d() : m_w(0), m_h(0), m_d(0), m_data(0)
{}

Matrix3d::Matrix3d(const Matrix3d &matrix) : m_w(matrix.m_w), m_h(matrix.m_h), m_d(matrix.m_d), m_data(matrix.m_data)
{}

void Matrix3d::operator=(const Matrix3d &matrix)
{
    m_w = matrix.m_w;
    m_h = matrix.m_h;
    m_d = matrix.m_d;
    m_data = matrix.m_data;
}

Matrix3d::Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d) : m_w(w),
                                                                                       m_h(h),
                                                                                       m_d(d),
                                                                                       m_data(w*h*d)
{}

Matrix3d::Matrix3d(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int f) : m_w(w),                                                                                                             m_h(h),                                                                                                             m_d(d),
                                                                                                   m_data(w*h*d, f)
{}

void Matrix3d::resize(const unsigned int w, const unsigned int h, const unsigned int d, const unsigned int fill)
{
        m_w = w;
        m_h = h;
        m_d = d;
        m_data.resize(w*h*d, fill);
}

void Matrix3d::clear()
{
    m_data.clear();
}

int &Matrix3d::at(const unsigned int x, const unsigned int y, const unsigned int z)
{
    assert(x<m_w && y<m_h && z<m_d);
    return m_data[x + m_w * (y + m_w* z)];
}

int &Matrix3d::at(const unsigned int index)
{
    return m_data[index];
}

unsigned int Matrix3d::getSize() const
{
    return m_w*m_h*m_d;
}

unsigned int Matrix3d::getW() const
{
    return m_w;
}

unsigned int Matrix3d::getH() const
{
    return m_h;
}

unsigned int Matrix3d::getD() const
{
    return m_d;
}

unsigned int Matrix3d::get3dIter(const unsigned int x, const unsigned int y, const unsigned int z)
{
    return x + m_w * (y + m_w* z);
}

unsigned int Matrix3d::get2dIter(const unsigned int x, const unsigned int y)
{
    return x * m_w + y;
}

Vector2 Matrix3d::get2dFromIter(const unsigned int iter)
{
    div_t res;
    res = div(iter, m_w);
    return Vector2(res.quot, res.rem);
}

std::vector<int> Matrix3d::getData() const
{
    return m_data;
}
