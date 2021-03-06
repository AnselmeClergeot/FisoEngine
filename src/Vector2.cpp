/*
This file is part of the FisoEngine sources : a simple C++ tile-based isometric engine.
For more informations about FisoEngine, see : https://github.com/AnselmeClergeot/FisoEngine.
You can contact Anselme Clergeot, the developer, at: anselmedu25@hotmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Vector2.hpp"



fe::Vector2::Vector2() : x(0), y(0)
{ }

fe::Vector2::Vector2(const int x, const int y) : x(x), y(y)
{ }

fe::Vector2::Vector2(const Vector2 &vec) : x(vec.x), y(vec.y)
{ }

fe::Vector2& fe::Vector2::operator=(const fe::Vector2 &vec) {
    x = vec.x;
    y = vec.y;

    return *this;
}

void fe::Vector2::operator+=(const fe::Vector2 &vec) {
    x+=vec.x;
    y+=vec.y;
}

void fe::Vector2::operator-=(const fe::Vector2 &vec) {
    x-=vec.x;
    y-=vec.y;
}

fe::Vector2 fe::operator+(const fe::Vector2& v1, const fe::Vector2 &v2) {
    fe::Vector2 res(v1);
    res+=v2;
    return res;
}

fe::Vector2 fe::operator-(const fe::Vector2& v1, const fe::Vector2 &v2) {
    fe::Vector2 res(v1);
    res-=v2;
    return res;
}

bool fe::operator==(const fe::Vector2& v1, const fe::Vector2 &v2) {
    return(v1.x==v2.x && v1.y==v2.y);
}
