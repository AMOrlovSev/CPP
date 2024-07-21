// Ex05.4_Target.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <cmath>

int main()
{
    system("chcp 1251");

    int numberOfShots = 0;
    std::cout << "Количество выстрелов: "; std::cin >> numberOfShots;

    int targetCenterX = 0;
    int targetCenterY = 0;

    char blindyActivation;
    std::cout << "Для активации стрельбы вслепую введите \"Y\" "; std::cin >> blindyActivation;

    if (blindyActivation == 'Y' || blindyActivation == 'y')
    {
        srand(time(NULL));
        targetCenterX = rand() % 4 + 1;
        targetCenterY = rand() % 4 + 1;
    }

    int points = 0;
    int userShotX = 0;
    int userShotY = 0;

    int targetPointsLevel1 = 10;
    int targetPointsLevel2 = 5;
    int targetPointsLevel3 = 1;
    int targetPointsLevel4 = 0;

    int targetLevelsLevel1 = 1;
    int targetLevelsLevel2 = 2;
    int targetLevelsLevel3 = 3;

    for (int i = 1; i <= numberOfShots; i++)
    {
        std::cout << "Выстрел " << i << " по X: "; std::cin >> userShotX;
        std::cout << "Выстрел " << i << " по Y: "; std::cin >> userShotY;

        int deltaX = std::abs(userShotX - targetCenterX);
        int deltaY = std::abs(userShotY - targetCenterY);
        double accuracy = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

        int count = 0;
        if (accuracy <= targetLevelsLevel1)
        {
            count = targetPointsLevel1;
        }
        else if (accuracy > targetLevelsLevel1 && accuracy <= targetLevelsLevel2)
        {
            count = targetPointsLevel2;
        }
        else if (accuracy > targetLevelsLevel2 && accuracy <= targetLevelsLevel3)
        {
            count = targetPointsLevel3;
        }
        points += count;
    }
    std::cout << "Очки: " << points;
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
