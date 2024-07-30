#include <iostream>
#include <windows.h>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	const float MTF;
	// конструктор по умолчанию
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
	// конструктор с двумя параметрами
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }

	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // перевод в футы
		feet = int(fltfeet); // число полных футов
		inches = 12 * (fltfeet - feet); // остаток - это дюймы
	}

	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\' - " << inches << "\"\n";
	}
	Distance operator+ (const Distance&) const;
	Distance operator- (const Distance&) const;

	friend std::ostream& operator<< (std::ostream& out, const Distance& dist);

	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
};

Distance Distance::operator+ (const Distance& d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}

Distance Distance::operator- (const Distance& d2) const
{
	int f = feet - d2.feet;
	float i = inches - d2.inches;
	if (i < 0)
	{
		i += 12.0;
		f--;
	}
	return Distance(f, i);
}

std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\' - " << dist.inches << "\"\n";
	return out;
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Distance dist02 = 2.35F;
	cout << "\ndist02 = " << dist02;

	float mtrs;
	mtrs = static_cast<float>(dist02);
	mtrs = dist02;
	cout << "\nmtrs = " << mtrs;

	//Distance dist1, dist2, dist3, dist4;
	//dist1.getdist();
	//dist2.getdist();
	//dist3 = dist1 + dist2;
	//dist4 = dist1 + dist2 + dist3;

	//cout << "\ndist3 = " << dist3;
	////dist3.showdist();
	//cout << "\ndist4 = " << dist4;
	////dist4.showdist();

	//dist3 = dist1 - dist2;
	//dist4 = dist1 - dist2 - dist3;
	//cout << "\ndist3 = " << dist3;
	////dist3.showdist();
	//cout << "\ndist4 = " << dist4;
	////dist4.showdist();

	
}
