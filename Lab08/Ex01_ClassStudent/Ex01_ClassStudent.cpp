// Ex01_ClassStudent.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	// Установка имени студента
	void set_name(string student_name)
	{
		name = student_name;
	}
	// Получение имени студента
	string get_name()
	{
		return name;
	}
	// Установка фамилии студента
	void set_last_name(string student_last_name)
	{
		last_name = student_last_name;
	}
	// Получение фамилии студента
	string get_last_name()
	{
		return last_name;
	}
	// Установка промежуточных оценок
	void set_scores(int student_scores[])
	{
		for (int i = 0; i < 5; ++i) {
			scores[i] = student_scores[i];
		}
	}
	// Установка среднего балла
	void set_average_score(double ball)
	{
		average_score = ball;
	}
	// Получение среднего балла
	double get_average_score()
	{
		return average_score;
	}
private:
	int scores[5]; // Промежуточные оценки
	double average_score; // Средний балл
	string name; // Имя
	string last_name; // Фамилия
};

int main()
{
	// Создание объекта класса Student
	Student student01;
	string name;
	string last_name;
	int scores[5];

	// Ввод имени с клавиатуры
	cout << "Name: ";
	getline(cin, name);
	// Ввод фамилии
	cout << "Last name: ";
	getline(cin, last_name);

	// Сумма всех оценок
	int sum = 0;
	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}

	// Сохранение имени и фамилии в объект класса Student
	student01.set_name(name);
	student01.set_last_name(last_name);
	// Сохранение промежуточных оценок в объект класса Student
	student01.set_scores(scores);
	//double average_score = sum / 5.0;
	double average_score = (double)sum / size(scores);
	// Сохранение среднего балла в объект класса Student
	student01.set_average_score(average_score);

	cout << "Average ball for " << student01.get_name() << " "
		<< student01.get_last_name() << " is "
		<< student01.get_average_score() << endl;
	return 0;
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
