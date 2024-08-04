#pragma once
#include "human.h"
#include "firm.h"

using namespace std;

class Worker : public Human
{
private:
	Firm firm;
	static inline unsigned countW{};

public:
	Worker() : Human(), firm() { ++countW; }
	Worker(Firm f) : Human(), firm(f) { ++countW; }
	Worker(string n, string lN, string pN, Firm f) : Human(n, lN, pN), firm(f) { ++countW; }

	string GetInfo() override {
		string getInfo = Human::GetInfo() + firm.FirmInfo();
		return getInfo;
	}

	string GetTotal() override {
		string total = "\nВсего людей: " + to_string(Human::GetCount()) + ", всего коллег: " + to_string(countW) + "!";
		return total;
	}
};