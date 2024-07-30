#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <windows.h>

using namespace std;

class Point {
public:
    Point(double x, double y) : x(x), y(y) {}

    double getDistance() const 
    {
        return sqrt(x * x + y * y);
    }

    friend ostream& operator<<(ostream& os, const Point& p);
    friend bool operator<(const Point& p1, const Point& p2);

private:
    double x, y;
};

ostream& operator<<(ostream& os, const Point& p) 
{
    os << "X: " << p.x << ", Y: " << p.y << " Length: " << p.getDistance();
    return os;
}

bool operator<(const Point& p1, const Point& p2) 
{
    return p1.getDistance() < p2.getDistance();
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для // класса Point
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для // класса Point
	return 0;
}