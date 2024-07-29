#pragma once
#include "Dot.h"
using namespace std;

class Triangle
{
private:
    Dot point1, point2, point3;

public:
    Triangle(Dot p1, Dot p2, Dot p3);
    double getSide(Dot p1, Dot p2);
    double getPerimeter();
    double getArea();
};