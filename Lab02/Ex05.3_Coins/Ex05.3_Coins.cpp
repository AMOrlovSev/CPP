// Ex05.3_Coins.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string> 

using namespace std;

int main()
{
    system("chcp 1251");
    int coinTenRuble = 1000;
    int coinFiveRuble = 500;
    int coinTwoRuble = 200;
    int coinOneRuble = 100;
    int coinFiftyKopecks = 50;
    int coinTenKopecks = 10;
    int coinFiveKopecks = 5;
    int coinOneKopecks = 1;

    double drubleForChange;
    cout << "rubleForChange = "; cin >> drubleForChange;
    int rubleForChange = drubleForChange * 100;

    int numberOfCoins = 0;
    string listOfCoins;

    while (rubleForChange > coinOneKopecks)
    {
        int tempCoin = 0;
        if (rubleForChange >= coinTenRuble)
        {
            tempCoin = rubleForChange / coinTenRuble;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinTenRuble ";
            rubleForChange -= tempCoin*coinTenRuble;
        }
        else if (rubleForChange >= coinFiveRuble)
        {
            tempCoin = rubleForChange / coinFiveRuble;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinFiveRuble ";
            rubleForChange -= tempCoin * coinFiveRuble;
        }
        else if (rubleForChange >= coinTwoRuble)
        {
            tempCoin = rubleForChange / coinTwoRuble;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinTwoRuble ";
            rubleForChange -= tempCoin * coinTwoRuble;
        }
        else if (rubleForChange >= coinOneRuble)
        {
            tempCoin = rubleForChange / coinOneRuble;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinOneRuble ";
            rubleForChange -= tempCoin * coinOneRuble;
        }
        else if (rubleForChange >= coinFiftyKopecks)
        {
            tempCoin = rubleForChange / coinFiftyKopecks;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinFiftyKopecks ";
            rubleForChange -= tempCoin * coinFiftyKopecks;
        }
        else if (rubleForChange >= coinTenKopecks)
        {
            tempCoin = rubleForChange / coinTenKopecks;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinTenKopecks ";
            rubleForChange -= tempCoin * coinTenKopecks;
        }
        else if (rubleForChange >= coinFiveKopecks)
        {
            tempCoin = rubleForChange / coinFiveKopecks;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinFiveKopecks ";
            rubleForChange -= tempCoin * coinFiveKopecks;
        }
        else
        {
            tempCoin = rubleForChange / coinOneKopecks;
            numberOfCoins += tempCoin;
            listOfCoins += to_string(tempCoin) + "XcoinOneKopecks ";
            rubleForChange -= tempCoin * coinOneKopecks;
        }

    }
    std::cout << "listOfCoins = " << listOfCoins;

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
