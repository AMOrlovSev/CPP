#pragma once
#include <iostream>
#include <string>

using namespace std;

class Firm
{
private:
	string firmName{};
	string department{};

public:
	Firm()
	{
		cout << "Enter Firm Name: ";
		cin >> firmName;
		cout << "Enter Department (\"n\" чтобы не указывать): ";
		cin >> department;
	}
	Firm(string n) : firmName(n) {}
	Firm(string n, string d) : firmName(n), department(d) {}

	void SetFirmName(string fN) {
		this->firmName = fN;
	}
	void SetFirmDepartment(string d) {
		this->department = d;
	}
	string FirmInfo() {
		string firmInfo;
		firmInfo += "\nФирма: " + firmName;
		if (department != "n" && department != "")
			firmInfo += "\nОтдел: " + department;
		return firmInfo + "\n";
	}
};