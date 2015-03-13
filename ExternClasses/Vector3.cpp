#include "Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0)
{

}

Vector3::Vector3(const int paramx, const int paramy, const int paramz) : x(paramx), y(paramy), z(paramz)
{

}

Vector3::Vector3(const Vector3 &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

void Vector3::operator=(const Vector3 &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
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
