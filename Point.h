#pragma once
#include <ostream>

using namespace std;

struct Point
{
    float x;
    float y;
    float z;

    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {

    }

    friend ostream& operator<<(ostream& os, const Point& r_point)
    {
        os << "{" << r_point.x << "," << r_point.y << "," << r_point.z << "}";
        return os;
    }
};
