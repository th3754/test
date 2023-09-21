#pragma once
#include "Point.h"


class  curve
{
protected:
    Point pos;

public:
    curve(float x, float y, float z);

    virtual Point get_point( float t) const = 0;
    virtual Point derivative(float t) const = 0;
};

class  circle : public curve
{
private:
    float r;

public:
    circle(float x, float y, float _r);
    float get_r() const;
    Point get_point( float t) const override;
    Point derivative(float t) const override;
    
};

class  ellipse : public curve
{
private:
    float r1, r2;

public:
    ellipse(float x, float y, float _r1, float _r2);

    Point get_point(float t) const override;
    Point derivative(float t) const override;  
};

class  helix : public curve
{
private:
    float r;
    float step;

public:

    helix(float x, float y, float z, float _r, float _step);

    Point get_point(float t) const override;

    Point derivative(float t) const override;
};
