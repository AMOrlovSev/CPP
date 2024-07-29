#pragma once
#include "Dot.h"
using namespace std;

class Triangle
{
private:
    Dot* point1;
    Dot* point2;
    Dot* point3;

public:
    Triangle(Dot* p1, Dot* p2, Dot* p3);
    double getSide(Dot* p1, Dot* p2);
    double getPerimeter();
    double getArea();
};