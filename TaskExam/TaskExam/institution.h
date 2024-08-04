#pragma once
#include <iostream>
#include <string>

using namespace std;

class Institution
{
private:
	string iName;
	string city;
public:
	Institution()
	{
		cout << "Enter Institution Name: ";
		cin >> iName;
		cout << "Enter City (\"n\" ����� �� ���������): ";
		cin >> city;
	}
	Institution(string iN) : iName(iN) {}
	Institution(string iN, string c) : iName(iN), city(c) {}

	void SetIName(string iN) {
		this->iName = iN;
	}
	void SetCity(string c) {
		this->city = c;
	}
	string InstitutionInfo() {
		string iInfo;
		iInfo += "\n������� ���������: " + iName;
		if (city != "n" && city != "")
			iInfo += "\n�����: " + city;
		return iInfo + "\n";
	}
};