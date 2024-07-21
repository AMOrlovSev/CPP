// Ex03.1_QuadraticEquation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

int Myroot(double, double, double, double&, double&);
void printResult(int, double, double, double, double, double);

int main()
{
	system("chcp 1251");

	int flag;
    double a, b, c;
    cout << "Введите a: "; cin >> a;
    cout << "Введите b: "; cin >> b;
    cout << "Введите c: "; cin >> c;
    double x1 = 0;
    double x2 = 0;

    flag = Myroot(a, b, c, x1, x2);
    printResult(flag, a, b, c, x1, x2);

    int flag2 = Myroot(3, -4, -9, x1, x2);
    printResult(flag2, 3, -4, -9, x1, x2);

    int flag1 = Myroot(1, 4, 4, x1, x2);
    printResult(flag1, 1, 4, 4, x1, x2);

    int flag0 = Myroot(3, -4, 9, x1, x2);
    printResult(flag0, 3, -4, 9, x1, x2);


}

int Myroot(double a, double b, double c, double& x1, double& x2)
{
    int flag;
    x1 = 0;
    x2 = 0;
    double D = b * b - 4 * a * c;
    if (D > 0)
    {
        flag = 1;
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
    }
    else if (D == 0)
    {
        flag = 0;
        x1 = (-b - sqrt(D)) / (2 * a);
        x2 = (-b + sqrt(D)) / (2 * a);
    }
    else
    {
        flag = -1;
    }
    return flag;
}

void printResult(int flag, double a, double b, double c, double x1, double x2)
{
    if (flag == 1)
    {
        cout << "Корни уравнения с коэффициентами a = " << a << ", b = " << b << ", c = " << c << ": x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (flag == 0)
    {
        cout << "Корень уравнения с коэффициентами a = " << a << ", b = " << b << ", c = " << c << ": x1 = x2 = " << x1 << endl;
    }
    else
    {
        cout << "Корней уравнения с коэффициентами a = " << a << ", b = " << b << ", c = " << c << " нет" << endl;
    }
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
