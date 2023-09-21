#include "curve.h"

curve::curve(float x, float y, float z) : pos(x, y, z)
{

}





circle::circle(float x, float y, float _r) : curve(x, y, 0), r(_r)
{

};

float circle::get_r() const
{
    return r;
};
Point circle::get_point(float t) const 
{
    return Point(pos.x + r * cos(t), pos.y + r * sin(t), pos.z);
}
Point circle::derivative(float t) const 
{
    return Point(-r * sin(t), r * cos(t), 0);
}





ellipse::ellipse(float x, float y, float _r1, float _r2) : curve(x, y, 0), r1(_r1), r2(_r2)
    {

    }
Point ellipse::get_point(float t) const 
    {
        return Point(pos.x + r1 * cos(t), pos.y + r2 * sin(t), pos.z);
    }
Point ellipse::derivative(float t) const 
    {
        return Point(-r1 * sin(t), r2 * cos(t), 0);
    }




helix::helix(float x, float y, float z, float _r, float _step) : curve(x, y, 0)
{

}

Point helix::get_point(float t) const
{
    return Point(pos.x + r * cos(t), pos.y + r * sin(t), pos.z + t / 6.28 * step);
}

Point helix::derivative(float t) const
{
    return Point(-r * sin(t), r * cos(t), 0);
}

