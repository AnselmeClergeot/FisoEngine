#include "Vector2.h"

Vector2::Vector2() : x(0), y(0)
{ }

Vector2::Vector2(const int x, const int y) : x(x), y(y)
{ }

Vector2::Vector2(const Vector2 &vec) : x(vec.x), y(vec.y)
{ }

Vector2& Vector2::operator=(const Vector2 &vec) {
    x = vec.x;
    y = vec.y;

    return *this;
}

void Vector2::operator+=(const Vector2 &vec) {
    x+=vec.x;
    y+=vec.y;
}

void Vector2::operator-=(const Vector2 &vec) {
    x-=vec.x;
    y-=vec.y;
}

Vector2 operator+(const Vector2& v1, const Vector2 &v2) {
    Vector2 res(v1);
    res+=v2;
    return res;
}

Vector2 operator-(const Vector2& v1, const Vector2 &v2) {
    Vector2 res(v1);
    res-=v2;
    return res;
}

bool operator==(const Vector2& v1, const Vector2 &v2) {
    return(v1.x==v2.x && v1.y==v2.y);
}
