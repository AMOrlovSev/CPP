#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
//#include <list>
#include <set>
#include <algorithm>
#include "Student.h"

using namespace std;


class Group
{
private:
	string name;
/*	list<Student> masSt;	
	list<Student>::iterator iter;*/ 

	multiset<Student*, compareStudent> masSt;			// мультимножество студентов
	multiset<Student*, compareStudent>::iterator iter; // итератор
	

public:
	Group(string name);
	Group();
	~Group();
	void setName(string newName);
	string getName();
	int  getSize();
	void addStudent(Student* newStudent);
	//string GroupOut(int);	// было для вектора
	void GroupOut(); 
	//void GroupSort();
	void delStudent(Student* oldStudent);
	Student* findStudent(string, string);

	//friend bool operator< (Student&,  Student&);
	//friend bool operator> (Student&,  Student&);
	//friend bool operator== (Student&,  Student&);
	//friend bool operator!= (Student&,  Student&);
	
};