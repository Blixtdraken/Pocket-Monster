#pragma once
#include <cmath>
#include <raylib.h>
namespace se
{
    class Vec2
    {
       
    public:
        Vec2();
        Vec2(float _x, float _y): x(_x), y (_y){}
        Vec2(float _all): x(_all), y (_all){}
        Vec2(::Vector2 raylibVector): x(raylibVector.x), y (raylibVector.y){}
        //////////////////////////////////////////////////////////////
        Vector2   rayify(){return ::Vector2(x,y);}
        Vec2      normalized(){return *this/length();}
        float     length(){return std::sqrt(std::powf(x, 2.0) + std::powf(y, 2.0));}
        Vec2      rotate(float _angle){return Vec2();} // TODO
        Vec2      rotate_pivot(float _angle, Vec2 _pivot_oint){return Vec2();} // TODO
        //////////////////////////////////////////////////////////
        Vec2 operator/(Vec2 right){return Vec2(x/right.x, y/right.y);}
        Vec2 operator*(Vec2 right){return Vec2(x*right.x, y*right.y);}
        Vec2 operator/=(float right){return Vec2(x/right, y/right);}
        Vec2 operator*=(float right){return Vec2(x*right, y*right);}
        //Vec2 operator=(::Vector2 right){return Vec2(right.x,right.y);}
        ////////////////////////////////////////////////////////
        float x,y;
    };

    class Vec2I
    {
       
    public:
        Vec2I(int _x, int _y): x(_x), y (_y){}
        Vec2I(int _all): x(_all), y (_all){}
        Vec2I(::Vector2 raylibVector): x(raylibVector.x), y (raylibVector.y){}
        
        ::Vector2 rayify(){return ::Vector2(x,y);}
        
        int x,y;
    };
}

