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

#endif // VECTOR3_H
