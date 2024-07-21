// Ex06.1_ArrayInFunction.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void show_array(const int[], const int);
int sumArray(const int Arr[], const int N);
double averageArray(const int Arr[], const int N);
int sumPositive(const int Arr[], const int N);
int sumNegative(const int Arr[], const int N);
int sumOdd(const int Arr[], const int N);
int sumEven(const int Arr[], const int N);
int maxValue(const int Arr[], const int N);
int indMaxValue(const int Arr[], const int N);
int minValue(const int Arr[], const int N);
int indMinValue(const int Arr[], const int N);
int productBetweenMaxMin(const int Arr[], const int N);
void sortArray(int Arr[], const int N);

int main()
{
    system("chcp 1251");

    const int n = 10;
    /*int mas[n];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]= ";
        cin >> mas[i];
    }*/

    int mas[n] = { 3, -4, -3, -2, -1, 10, 1, -8, 3, -5 };

    show_array(mas, n);

    cout << "sumArray = " << sumArray(mas, n) << endl;
    cout << "averageArray = " << averageArray(mas, n) << endl;
    cout << "sumPositive = " << sumPositive(mas, n) << endl;
    cout << "sumNegative = " << sumNegative(mas, n) << endl;
    cout << "sumOdd = " << sumOdd(mas, n) << endl;
    cout << "sumEven = " << sumEven(mas, n) << endl;
    cout << "maxValue = " << maxValue(mas, n) << endl;
    cout << "indMaxValue = " << indMaxValue(mas, n) << endl;
    cout << "minValue = " << minValue(mas, n) << endl;
    cout << "indMinValue = " << indMinValue(mas, n) << endl;
    cout << "productBetweenMaxMin = " << productBetweenMaxMin(mas, n) << endl;

    sortArray(mas, n);
    show_array(mas, n);
}

void show_array(const int Arr[], const int N)
{
    for (int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

int sumArray(const int Arr[], const int N)
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        s += Arr[i];
    }
    return s;
}

double averageArray(const int Arr[], const int N)
{
    double average = (double)sumArray(Arr, N) / N;
    return average;
}

int sumPositive(const int Arr[], const int N)
{
    int sumPositive = 0;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] > 0)
            sumPositive += Arr[i];
    }
    return sumPositive;
}

int sumNegative(const int Arr[], const int N)
{
    int sumNegative = 0;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] < 0)
            sumNegative += Arr[i];
    }
    return sumNegative;
}

int sumOdd(const int Arr[], const int N)
{
    int sumOdd = 0;
    for (int i = 0; i < N; i = i + 2)
    {
        sumOdd += Arr[i];
    }
    return sumOdd;
}

int sumEven(const int Arr[], const int N)
{
    int sumEven = 0;
    for (int i = 1; i < N; i = i + 2)
    {
        sumEven += Arr[i];
    }
    return sumEven;
}

int maxValue(const int Arr[], const int N)
{
    int maxValue = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] > maxValue)
        {
            maxValue = Arr[i];
        }
    }
    return maxValue;
}

int indMaxValue(const int Arr[], const int N)
{
    int maxValue = INT_MIN;
    int indMaxValue = 0;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] > maxValue)
        {
            maxValue = Arr[i];
            indMaxValue = i;
        }
    }
    return indMaxValue;
}

int minValue(const int Arr[], const int N)
{
    int minValue = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] < minValue)
        {
            minValue = Arr[i];
        }
    }
    return minValue;
}

int indMinValue(const int Arr[], const int N)
{
    int minValue = INT_MAX;
    int indMinValue = 0;
    for (int i = 0; i < N; i++)
    {
        if (Arr[i] < minValue)
        {
            minValue = Arr[i];
            indMinValue = i;
        }
    }
    return indMinValue;
}

int productBetweenMaxMin(const int Arr[], const int N)
{
    int productBetweenMaxMin = Arr[min(indMaxValue(Arr, N), indMinValue(Arr, N))];
    for (int i = min(indMaxValue(Arr, N), indMinValue(Arr, N)) + 1; i <= max(indMaxValue(Arr, N), indMinValue(Arr, N)); i++)
    {
        productBetweenMaxMin *= Arr[i];
    }
    return productBetweenMaxMin;
}

void sortArray(int Arr[], const int N)
{
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (Arr[j] < Arr[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = Arr[i];
            Arr[i] = Arr[min];
            Arr[min] = buf;
        }
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
