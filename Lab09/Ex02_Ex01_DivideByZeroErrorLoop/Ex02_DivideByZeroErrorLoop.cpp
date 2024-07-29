#include <iostream> 
#include <string>
#include <windows.h>

using namespace std;

class DivideByZeroError 
{ public: 
    DivideByZeroError() : message("Деление на нуль") { } 
    void printMessage() const { cout << message << endl; } 
private: 
    string message; 
};

float quotient(int num1, int num2)
{
    if (num2 == 0)
        throw DivideByZeroError();
    return (float)num1 / num2;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Введите числитель операции деления:\n"; 
    int number1; 
    cin >> number1; 
    for (int i = -10; i < 10; i++) 
    { 
        try 
        { 
            float result = quotient(number1, i); 
            cout << "Частное равно " << result << endl; 
        } 
        catch (DivideByZeroError& error) 
        {
            cout << "ОШИБКА: "; 
            error.printMessage(); 
            //return 1;
        } 
    }
    return 0; // нормальное завершение программы }
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
