// Ex05.1_Super_prime_number.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    system("chcp 1251");
    int n;
    bool flag = false;
    cout << "n = "; cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Число " << n << " не простое" << endl;
    else
        cout << "Число " << n << " простое" << endl;

    //максимальное простое int, подставить вместо INT_MAX
#include <ctime>

    unsigned int start_time = clock();

    int maxInt = 0;
    for (int n = 2; n <= INT_MAX; n++)
    {
        bool flag = false;
        for (int ii = 2; ii <= sqrt(n); ii++)
        {
            if (n % ii == 0)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            maxInt = n;
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "maxInt " << maxInt << endl;
    cout << "search_time " << search_time << endl;
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
