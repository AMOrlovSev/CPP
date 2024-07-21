// Ex03_FunctionPointer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void show_array(const int[], const int);
bool from_min(const int, const int);
bool from_max(const int, const int);
void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b));

int main()
{
    system("chcp 1251");

    bool (*from_f[2])(int, int) = { from_min,from_max };

    const int N = 10;
    int my_choose = 0;
    /*int a[N] = { 9,8,7,6,1,2,3,5,4,9 };*/
    int* a = new int[N] { 9, 8, 7, 6, 1, 2, 3, 5, 4, 9 };

    cout << "1. Сортировать по возрастанию\n";
    cout << "2. Сортировать по убыванию\n";
    cin >> my_choose;

    cout << "Исходные данные: ";
    show_array(a, N);

    //switch (my_choose)
    //{
    //case 1: bubble_sort(a, N, from_min); break;
    //case 2: bubble_sort(a, N, from_max); break;
    //default: cout << "\rНеизвестная операция ";
    //}

    bubble_sort(a, N, (*from_f[my_choose - 1]));

    show_array(a, N);

    delete[] a;
    a = nullptr;

    return 0;
}

void show_array(const int Arr[], const int N)
{
    for (int i = 0; i < N; i++)
        cout << Arr[i] << " ";
    cout << "\n";
}

bool from_min(const int a, const int b)
{
    return a > b;
}

bool from_max(const int a, const int b)
{
    return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
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
