#include <iostream>
#include "Dot.h"
#include "Triangle.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Dot* d1 = new Dot(0, 0);
    Dot* d2 = new Dot(0, 4);
    Dot* d3 = new Dot(3, 0);

    Triangle triangle(d1, d2, d3);
    cout << "Стороны: " << triangle.getSide(d1, d2) << ", " << triangle.getSide(d2, d3) << ", " << triangle.getSide(d3, d1) << endl;
    cout << "Периметр: " << triangle.getPerimeter() << endl;
    cout << "Площадь: " << triangle.getArea() << endl;

    delete d1;
    delete d2;
    delete d3;

    return 0;
}