// Ex06.1_StructTime.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;

    void ShowTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    int ShowSeconds()
    {
        int sec = hours * 3600 + minutes * 60 + seconds;
        return sec;
    }
};

Time InputTime()
{
    Time t;
    cout << "\nВведите число часов: ";
    cin >> t.hours;
    cout << "\nВведите число минут: ";
    cin >> t.minutes;
    cout << "\nВведите число секунд: ";
    cin >> t.seconds;
    return t;
}

Time sumTime(Time t1, Time t2)
{
    Time t;
    t.seconds = (t1.seconds + t2.seconds)%60;
    t.minutes = ((t1.minutes + t2.minutes) + (t1.seconds + t2.seconds) / 60)%60;
    t.hours = t1.hours + t2.hours+(t1.seconds + t2.seconds)/60;
    return t;
}

Time difTime(Time t1, Time t2)
{
    Time t;
    if (t1.ShowSeconds() > t2.ShowSeconds())
    {
        if ((t1.seconds - t2.seconds) < 0)
        {
            t.seconds = t1.seconds - t2.seconds + 60;
            t1.minutes--;
        }
        else
            t.seconds = t1.seconds - t2.seconds;

        if ((t1.minutes - t2.minutes) < 0)
        {
            t.minutes = t1.minutes - t2.minutes + 60;
            t1.hours--;
        }
        else
            t.minutes = t1.minutes - t2.minutes;

        t.hours = t1.hours - t2.hours;
    }
    else 
    {
        if ((t2.seconds - t1.seconds) < 0)
        {
            t.seconds = t2.seconds - t1.seconds + 60;
            t2.minutes--;
        }
        else
            t.seconds = t2.seconds - t1.seconds;

        if ((t2.minutes - t1.minutes) < 0)
        {
            t.minutes = t2.minutes - t1.minutes + 60;
            t2.hours--;
        }
        else
            t.minutes = t2.minutes - t1.minutes;

        t.hours = t2.hours - t1.hours;
    }
    return t;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Time t1 = InputTime();
    Time t2 = InputTime();

    t1.ShowTime();
    t2.ShowTime();

    Time tSum = sumTime(t1, t2);
    tSum.ShowTime();

    Time tDif = difTime(t1, t2);
    tDif.ShowTime();
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
