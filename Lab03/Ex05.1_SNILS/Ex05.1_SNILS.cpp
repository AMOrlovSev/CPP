// Ex05.1_SNILS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool snilsCorrect(string);
string deleteSubString(string, char);

int main()
{
	system("chcp 1251");

    string snilsNumbersSumLess100 = "112   2- 51---129-88";
	string snilsNumbersSum100 = "11--225 1 1 8-9-00";
	string snilsNumbersSumMore101modulo = "112  251789-17";
	string snilsNumbersSumMore101 = "998-177-615-00";
	string snilsMoreSymbols = "9981776151-00";
	string snilsLessSymbols = "99817761-00";
	string snilsNoDigit = "9981776a5-00";
	string snilsNoCorrect = "998177695-00";

    bool bsnilsNumbersSumLess100 = snilsCorrect(snilsNumbersSumLess100);
	bool bsnilsNumbersSum100 = snilsCorrect(snilsNumbersSum100);
	bool bsnilsNumbersSumMore101modulo = snilsCorrect(snilsNumbersSumMore101modulo);
	bool bsnilsNumbersSumMore101 = snilsCorrect(snilsNumbersSumMore101);
	bool bsnilsMoreSymbols = snilsCorrect(snilsMoreSymbols);
	bool bsnilsLessSymbols = snilsCorrect(snilsLessSymbols);
	bool bsnilsNoDigit = snilsCorrect(snilsNoDigit);
	bool bsnilsNoCorrect = snilsCorrect(snilsNoCorrect);

    cout << snilsNumbersSumLess100 << " isCorrect: " << boolalpha << bsnilsNumbersSumLess100 << endl;
	cout << snilsNumbersSum100 << " isCorrect: " << boolalpha << bsnilsNumbersSum100 << endl;
	cout << snilsNumbersSumMore101modulo << " isCorrect: " << boolalpha << bsnilsNumbersSumMore101modulo << endl;
	cout << snilsNumbersSumMore101 << " isCorrect: " << boolalpha << bsnilsNumbersSumMore101 << endl;
	cout << snilsMoreSymbols << " isCorrect: " << boolalpha << bsnilsMoreSymbols << endl;
	cout << snilsLessSymbols << " isCorrect: " << boolalpha << bsnilsLessSymbols << endl;
	cout << snilsNoDigit << " isCorrect: " << boolalpha << bsnilsNoDigit << endl;
	cout << snilsNoCorrect << " isCorrect: " << boolalpha << bsnilsNoCorrect << endl;
}

bool snilsCorrect(string snils)
{
    bool flag = true;

    //удаляем дефисы и пробелы, проверяем колличество символов (д.б. 11)
	string snilsWithoutHyphen = deleteSubString(snils, '-');
	string snilsWithoutSpace = deleteSubString(snilsWithoutHyphen, ' ');

    snils = snilsWithoutSpace;

    if (snils.length() != 11)
    {
        flag = false;
        return flag;
    }

    //проверяем что все символы isdigit
    for (int i = 0; i < snils.length(); i++)
    {
        if (!isdigit(snils[i]))
        {
            flag = false;
            return flag;
        }
    }

    //проверяем корректность СНИЛС
    int snilsNumbersLength = 9;
    int snilsCheckNumberLength = 2;

    string strsnilsNumbers = snils.substr(0, snilsNumbersLength);
    string strsnilsCheckNumber = snils.substr(snilsNumbersLength, snilsCheckNumberLength);

    int snilsNumbers = stoi(strsnilsNumbers);
    int snilsCheckNumber = stoi(strsnilsCheckNumber);

	int previousNumber = snilsNumbers % 10;
	int currentNumber;
	int count = 1;

	int snilsNumbersSum = previousNumber;
	
	// проверяем, что нет больше 2х подряд одинаковых цифр
	for (int i = 2; i <= snilsNumbersLength; i++)
	{
		currentNumber = snilsNumbers % (int)pow(10, i) / (int)pow(10, i - 1);
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

	// проверяем соответствие контрольному значению
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

    return flag;
}

string deleteSubString(string text, char to_delete)
{
	string my_str = text;
	my_str.erase(remove(my_str.begin(), my_str.end(), to_delete), my_str.end());
    return my_str;
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
