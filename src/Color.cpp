#include "Color.hpp"

fe::Color::Color() : r(255), g(255), b(255), a(255)
{ }

fe::Color::Color(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) : r(r),
                                                                                                           g(g),
                                                                                                           b(b),
                                                                                                           a(a)
{ }

fe::Color::Color(const fe::Color& color) : r(color.r), g(color.g), b(color.b), a(color.a)
{ }

fe::Color::Color(const unsigned int r, const unsigned int g, const unsigned int b) : r(r),
                                                                                     g(g),
                                                                                     b(b),
                                                                                     a(255)
{ }

fe::Color &fe::Color::operator=(const fe::Color& color) {
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;
}

bool fe::operator==(const fe::Color& color1, const fe::Color &color2) {
    return (color1.r==color2.r &&
            color1.g==color2.g &&
            color1.b==color2.b &&
            color1.a==color2.a);
}
