#ifndef VECTOR3_H
#define VECTOR3_H


class Vector3
{
    public:
        Vector3();
        Vector3(const int paramx, const int paramy, const int paramz);
        Vector3(const Vector3 &vec);
        void operator=(const Vector3 &vec);
        void operator+=(const Vector3 &vec);
        void operator-=(const Vector3 &vec);
        int x, y, z;
};

    Vector3 operator+(const Vector3 &v1, const Vector3 &v2);
    Vector3 operator-(const Vector3 &v1, const Vector3 &v2);
    bool operator==(const Vector3 &v1, const Vector3 &v2);
#endif // VECTOR3_H
