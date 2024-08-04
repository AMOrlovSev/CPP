#pragma once
#include <iostream>

using namespace std;

class Human
{
private:
	string name;
	string lastName;
	string phoneNumber;
	static inline unsigned count{};

public:
	Human()
	{
		cout << "\nEnter Name: ";
		cin >> name;
		cout << "Enter Last Name: ";
		cin >> lastName;
		cout << "Enter Phone Number: ";
		cin >> phoneNumber;
		++count;
	}
	Human(string n, string lN, string pN) : name(n), lastName(lN), phoneNumber(pN) 
	{
		++count;
	}

	void SetName(string n) {
		this->name = n;
	}
	void SetLastName(string lN) {
		this->lastName = lN;
	}
	void SetPhoneNumber(string pN) {
		this->phoneNumber = pN;
	}

	int GetCount() {
		return count;
	}

	virtual string GetInfo() {
		string getInfo = "\nИмя: " + name + "\nФамилия: " + lastName + "\nТелефон: " + phoneNumber;
		return getInfo;
	}

	virtual string GetTotal() = 0;
};