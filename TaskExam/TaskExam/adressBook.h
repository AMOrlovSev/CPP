#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "worker.h"
#include "student.h"

using namespace std;

class AdressBook
{
private:
	vector<Human*> contacts;

public:
	AdressBook() {}
	~AdressBook() {}

	void run()
	{
		string menu = "0";
		while (menu != "exit")
		{
			system("cls");
			showMenu(menu);
			cin >> menu;
		}
	}

	void showMenu(string menu) {
		if (menu == "0") {
			cout << "������� \"1\" ����� �������� �������\n";
			cout << "������� \"2\" ����� �������� ��������\n\n";
			cout << "������� ����� ��� ������� \"9\" ��� ������:\n";
		}
		else if (menu == "1") {
			cout << "Worker\n";
			cout << "Student\n\n";
			cout << "������� ��� ������:\n";
		}
		else if (menu == "2") {
			for (int i = 0; i < contacts.size(); i++)
			{
				cout << contacts[i]->GetInfo() << endl;
			}
			cout << "enter 0\n";
		}
		else if (menu == "Worker") {
			Human* human = new Worker();
			contacts.push_back(human);
			cout << "enter 0\n";
		}
		else if (menu == "Student") {
			Human* human = new Student();
			contacts.push_back(human);
			cout << "enter 0\n";
		}
		else if (menu == "9") {
			SaveToFile();
			exit(0);
		}
		else {
			cout << "����������� ����, ������� \"0\"\n";
		}
	}

	void SaveToFile()
	{
		ofstream file("AdressBook.txt", ios::app);
		if (!file) {
			cout << "������\n";
		}
		for (const auto& item : contacts) {
			file << item->GetInfo() << endl;
		}
		cout << "���������\n";
		file.close();
	}
};