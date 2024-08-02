#include <iostream>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

struct StudentGrade {
    string name;
    char grade;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    map<string, char> grades;

    while (true) 
    {
        cout << "Введите имя студента (или 'q', чтобы закончить ввод): ";
        string name; cin >> name;

        if (name == "q")
            break;

        cout << "Оценка: " << name << ": ";
        char grade; cin >> grade;

        grades[name] = grade;
    }

    cout << "\nОценки учащихся:" << endl;
    for (const auto& pair : grades) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}