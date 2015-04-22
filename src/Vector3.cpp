#include "Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0)
{

}

Vector3::Vector3(const int paramx, const int paramy, const int paramz) : x(paramx), y(paramy), z(paramz)
{

}

Vector3::Vector3(const Vector3 &vec) : x(vec.x), y(vec.y), z(vec.z)
{

}

Vector3& Vector3::operator=(const Vector3 &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;

    return *this;
}

void Vector3::operator+=(const Vector3 &vec)
{
    x+=vec.x;
    y+=vec.y;
    z+=vec.z;
}

void Vector3::operator-=(const Vector3 &vec)
{
    x-=vec.x;
    y-=vec.y;
    z-=vec.z;
}

Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
    Vector3 res(v1);
    res+=v2;
    return res;
}

Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
    Vector3 res(v1);
    res-=v2;
    return res;
}

bool operator==(const Vector3 &v1, const Vector3 &v2)
{
    return (v1.x==v2.x && v1.y==v2.y && v1.z==v2.z);
}
