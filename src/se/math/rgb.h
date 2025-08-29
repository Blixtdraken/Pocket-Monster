#pragma once
#include <raylib.h>

class RGB
{
public:
    RGB(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a): r(_r), g(_g), b(_b), a(_a) {}
    RGB(unsigned char _r, unsigned char _g, unsigned char _b): r(_r), g(_g), b(_b), a(255) {}
    RGB(Color c): r(c.r), g(c.g), b(c.b), a(c.a) {}
    ///////////////////////////////////////////////
    RGB operator*=(float scalar){r *= scalar;g *= scalar;b *= scalar; return *this;}
    RGB operator/=(float scalar){r /= scalar;g /= scalar;b /= scalar; return *this;}
    ///////////////////////////////////////////////
    Color rayify(){return Color(r,g,b,a);}
    ///////////////////////////////////////////
    unsigned char r,g,b,a;
};
