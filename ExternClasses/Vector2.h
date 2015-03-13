#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2
{
    public:
        Vector2();
        Vector2(const int paramx, const int paramy);
        Vector2(const Vector2 &vec);
        void operator=(const Vector2 &vec);
        void operator+=(const Vector2 &vec);
        void operator-=(const Vector2 &vec);
        int x, y;
};

#endif // VECTOR2_H
