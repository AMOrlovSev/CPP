// Ex05.2_SNILS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	system("chcp 1251");

	int snilsNumbersLength = 9;
	int snilsCheckNumberLength = 2;
	bool flag = true;

	int snilsNumbers;
	int snilsCheckNumber;
	std::cout << "snilsNumbers = "; cin >> snilsNumbers;
	std::cout << "snilsCheckNumber = "; cin >> snilsCheckNumber;

	int previousNumber = snilsNumbers % 10;
	int currentNumber;
	int count = 1;

	int snilsNumbersSum = previousNumber;

	for (int i = 2; i <= snilsNumbersLength; i++)
	{
		currentNumber = snilsNumbers % (int)pow(10, i)/ (int)pow(10, i-1);
		snilsNumbersSum += currentNumber * i;

		if (currentNumber == previousNumber)
			count++;
		else
			count = 1;

		if (count > 2)
		{
			flag = false;
			break;
		}
		previousNumber = currentNumber;
	}

	if (flag)
	{
		//112251129-88
		if (snilsNumbersSum < 100)
		{
			if (snilsCheckNumber != snilsNumbersSum)
				flag = false;
		}
		//112251189-00
		else if (snilsNumbersSum == 100 || snilsNumbersSum == 101)
		{
			if (snilsCheckNumber != 00)
				flag = false;
		}
		else if (snilsNumbersSum > 101)
		{
			//112251789-17
			if (snilsNumbersSum % 101 < 100)
			{
				if (snilsCheckNumber != snilsNumbersSum % 101)
					flag = false;
			}
			//998177615-00
			else
			{
				if (snilsCheckNumber != 00)
					flag = false;
			}
		}
	}

	std::cout << "СНИЛС = " << std::boolalpha << flag;
	//std::cout << "snilsNumbersSum = " << snilsNumbersSum;

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
