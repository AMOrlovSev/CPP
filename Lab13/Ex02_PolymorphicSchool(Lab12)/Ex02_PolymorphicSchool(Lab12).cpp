#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

class human {
public:
    // Конструктор класса human
    human(std::string last_name, std::string name, std::string second_name)
    {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }
    // Получение ФИО человека
    virtual std::string get_full_name()
    {
        std::ostringstream full_name;
        full_name << this->last_name << " "
            << this->name << " "
            << this->second_name;
        return full_name.str();
    }
private:
    std::string name; // имя
    std::string last_name; // фамилия
    std::string second_name; // отчество
};

class student : public human {
public:
    // Конструктор класса Student
    student(std::string last_name, std::string name, std::string second_name,
        std::vector<int> scores) : human(last_name, name, second_name) {
        this->scores = scores;
    }
    // Получение среднего балла студента
    float get_average_score()
    {
        // Общее количество оценок
        unsigned int count_scores = this->scores.size();
        // Сумма всех оценок студента
        unsigned int sum_scores = 0;
        // Средний балл
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }
        average_score = (float)sum_scores / (float)count_scores;
        return average_score;
    }

    std::string get_full_name() override
    {
        std::ostringstream full_name;
        full_name << "Студент: " << human::get_full_name();
        return full_name.str();
    }

private:
    // Оценки студента
    std::vector<int> scores;
};

class teacher : public human {
    // Конструктор класса teacher
public:
    teacher(
        std::string last_name,
        std::string name,
        std::string second_name,
        // Количество учебных часов за семестр у преподавателя
        unsigned int work_time
    ) : human(
        last_name,
        name,
        second_name
    ) {
        this->work_time = work_time;
    }
    // Получение количества учебных часов
    unsigned int get_work_time()
    {
        return this->work_time;
    }

    std::string get_full_name() override
    {
        std::ostringstream full_name;
        full_name << "Учитель: " << human::get_full_name();
        return full_name.str();
    }

private:
    // Учебные часы
    unsigned int work_time;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Оценки студента
    std::vector<int> scores;
    // Добавление оценок студента в вектор
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    /*student* stud = new student("Петров", "Иван", "Алексеевич", scores);
    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл : " << stud->get_average_score() << std::endl;*/

    human* stud = new student("Петров", "Иван", "Алексеевич", scores);
    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл : " << static_cast<student*>(stud)->get_average_score() << std::endl;

    /*unsigned int teacher_work_time = 40;
    teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() << std::endl;*/

    unsigned int teacher_work_time = 40;
    human* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);
    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << static_cast<teacher*>(tch)->get_work_time() << std::endl;

    return 0;
}