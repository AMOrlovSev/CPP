#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Dot* p1, Dot* p2, Dot* p3) : point1(p1), point2(p2), point3(p3) {}

double Triangle::getSide(Dot* p1, Dot* p2)
{
    double side = p1->distanceTo(*p2);
    return side;
}

double Triangle::getPerimeter()
{
    double side1 = point1->distanceTo(*point2);
    double side2 = point2->distanceTo(*point3);
    double side3 = point3->distanceTo(*point1);

    return side1 + side2 + side3;
}

double Triangle::getArea()
{
    double side1 = point1->distanceTo(*point2);
    double side2 = point2->distanceTo(*point3);
    double side3 = point3->distanceTo(*point1);

    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}