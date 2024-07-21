// Ex05.4_RecursionSumOfSeries.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int RecursionSumOfSeries5(int);

int main()
{
    system("chcp 1251");

    cout << "RecursionSumOfSeries5(1): " << RecursionSumOfSeries5(1) << endl;
    cout << "RecursionSumOfSeries5(2): " << RecursionSumOfSeries5(2) << endl;
    cout << "RecursionSumOfSeries5(3): " << RecursionSumOfSeries5(3) << endl;
    cout << "RecursionSumOfSeries5(4): " << RecursionSumOfSeries5(4) << endl;
    cout << "RecursionSumOfSeries5(5): " << RecursionSumOfSeries5(5) << endl;
}

int RecursionSumOfSeries5(int n)
{
    if (n == 1) return 5; // выход из рекурсии
    else 
    {
        int sum = 5 * n + RecursionSumOfSeries5(n - 1);
        return sum;
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
