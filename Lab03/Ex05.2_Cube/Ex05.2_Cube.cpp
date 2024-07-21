// Ex05.2_Cube.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using namespace std;

int cubeMath(int);
int cubeRecursion(int);

int main()
{
    system("chcp 1251");

    cout << "cubeMath(8): " << cubeMath(8) << endl;
    cout << "cubeRecursion(8): " << cubeRecursion(8) << endl;
}

int cubeMath(int number)
{
    int x = pow(number, 1.0 / 3);
    return x;
}

int cubeRecursion(int number)
{
    float xnew = number;
    float xold = xnew;
    if (abs(xnew-xold)<0.0001)
        return xnew;
    else 
    {
        return xnew = 1.0 / 3 * (number / (cubeRecursion(xold) * cubeRecursion(xold)) + 2 * cubeRecursion(xold));
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
