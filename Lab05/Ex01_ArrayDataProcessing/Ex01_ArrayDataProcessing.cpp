// Ex01_ArrayDataProcessing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    system("chcp 1251");

    const int n = 10;

    int *mas = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]= ";
        cin >> mas[i];
    }

    //int mas[n] { 3, -4, -3, -2, -1, 10, 1, -8, 3, -5 };

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
    }
    cout << "s = " << s << endl;

    double average =  (double)s / (sizeof(mas) / sizeof(*mas));
    cout << "average = " << average << endl;

    int sumPositive = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0)
            sumPositive += mas[i];
    }
    cout << "sumPositive = " << sumPositive << endl;

    int sumNegative = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
            sumNegative += mas[i];
    }
    cout << "sumNegative = " << sumNegative << endl;

    int sumOdd = 0;
    for (int i = 0; i < n; i=i+2)
    {
        sumOdd += mas[i];
    }
    cout << "sumOdd = " << sumOdd << endl;

    int sumEven = 0;
    for (int i = 1; i < n; i = i + 2)
    {
        sumEven += mas[i];
    }
    cout << "sumEven = " << sumEven << endl;

    int maxValue = INT_MIN;
    int indMaxValue = 0;
    int minValue = INT_MAX;
    int indMinValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > maxValue)
        {
            maxValue = mas[i];
            indMaxValue = i;
        }
        if (mas[i] < minValue)
        {
            minValue = mas[i];
            indMinValue = i;
        }
    }
    cout << "maxValue = " << maxValue << " indMaxValue = " << indMaxValue << endl;
    cout << "minValue = " << minValue << " indMinValue = " << indMinValue << endl;

    int productBetweenMaxMin = mas[min(indMaxValue, indMinValue)];
    for (int i = min(indMaxValue, indMinValue)+1; i <= max(indMaxValue, indMinValue); i++)
    {
        productBetweenMaxMin *= mas[i];
    }
    cout << "productBerweenMaxMin = " << productBetweenMaxMin << endl;

    delete[] mas;
    mas = nullptr;
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
