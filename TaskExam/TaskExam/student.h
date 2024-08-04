#pragma once
#include "human.h"
#include "institution.h"

using namespace std;

class Student : public Human
{
private:
	Institution institution;
	static inline unsigned countI{};

public:
	Student() : Human(), institution() { ++countI; }
	Student(Institution i) : Human(), institution(i) { ++countI; }
	Student(string n, string lN, string pN, Institution i) : Human(n, lN, pN), institution(i) { ++countI; }

	string GetInfo() override {
		string getInfo = Human::GetInfo() + institution.InstitutionInfo();
		return getInfo;
	}

	string GetTotal() override {
		string total = "\nВсего людей: " + to_string(Human::GetCount()) + ", всего вместе учились: " + to_string(countI) + "!";
		return total;
	}
};