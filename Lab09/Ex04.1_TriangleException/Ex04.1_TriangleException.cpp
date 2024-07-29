// Ex04.1_TriangleException.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Triangle
{
public:

    class ExTriangle
    {
    public:
        ExTriangle() : message("Указаны неверные стороны") { }
        void printMessage() const { cout << message << endl; }
    private:
        string message;
    };

    Triangle() : a(5), b(5), c(5) {};
    Triangle(int sa, int sb, int sc)
    {
        a = sa;
        b = sb;
        c = sc;
        if ((a + b) > c || (b + c) > a || (c + a) > b)
            throw ExTriangle();
    }
    Triangle(int sa)
    {
        a = sa;
        b = sa;
        c = sa;
    }

    void setSides()
    {
        cout << "Введите сторону треугольника a: ";
        cin >> a;
        cout << "Введите сторону треугольника b: ";
        cin >> b;
        cout << "Введите сторону треугольника c: ";
        cin >> c;
        if ((a+b)<=c || (b+c)<=a || (c+a)<=b)
            throw ExTriangle();
        //cout << "Площадь разностороннего треугольника: " << triangleArea(a, b, c) << endl;
    }
    void setSide()
    {
        cout << "Введите сторону треугольника: ";
        cin >> a;
        b = a; c = b;
        //cout << "Площадь равностороннего треугольника: " << triangleArea(a) << endl;
    }
    void showArea()
    {
        if (a==b && b==c)
            cout << "Площадь равностороннего треугольника: " << triangleArea(a, b, c) << endl;
        else
            cout << "Площадь разностороннего треугольника: " << triangleArea(a, b, c) << endl;
    }


private:
    int a{};
    int b{};
    int c{};
    double s = triangleArea(a, b, c);

    double triangleArea(int a, int b, int c)
    {
        double p = (a + b + c) / 2.0;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try
    {
        Triangle tr01;
        tr01.showArea();
        tr01.setSide();
        tr01.showArea();
        tr01.setSides();
        tr01.showArea();

        Triangle tr02(12);
        tr02.showArea();

        Triangle tr03(1,2,3);
        tr03.showArea();

    }
    catch (Triangle::ExTriangle& error)
    {
        cout << "ОШИБКА: ";
        error.printMessage();
        return 1; // завершение программы при ошибке
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
