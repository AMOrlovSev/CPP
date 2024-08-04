#include <iostream>
#include <string>
#include <windows.h>

#include "worker.h"
#include "student.h"
#include "adressBook.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    /*Firm firm01;
    Firm firm02;*/
    /*Firm firm1("Alumstroy");
    Firm firm2("NIP", "Tekla");

    Institution institution1("—œ·√¿—”");
    Institution institution2("—Œÿ333", "—œ·");*/

    //cout << firm01.FirmInfo();
    //cout << firm02.FirmInfo();
    /*cout << firm1.FirmInfo();
    cout << firm2.FirmInfo();

    firm1.SetFirmDepartment("KMD");
    firm2.SetFirmName("SSK");
    firm2.SetFirmDepartment("");

    cout << firm1.FirmInfo();
    cout << firm2.FirmInfo();*/


    //Human human1;
    //Human human2("Artem", "Orlov", "8-800-555-35-35");
    //cout << human1.GetInfo();
    //cout << human2.GetInfo();
    //human1.SetName("456");
    //human1.SetLastName("564");
    //human1.SetPhoneNumber("654");
    //cout << human1.GetInfo();

    /*Worker worker1;
    cout << worker1.GetInfo();

    Worker worker2(firm1);
    cout << worker2.GetInfo();

    Worker worker3("qwe", "wer", "ert", firm2);
    cout << worker3.GetInfo();

    cout << worker3.GetTotal();

    Student student1;
    cout << student1.GetInfo();

    Student student2(institution1);
    cout << student2.GetInfo();

    Student student3("Ù˚‚", "‡Ô", "ÓÎ", institution2);
    cout << student3.GetInfo();

    cout << student1.GetTotal();*/



    //Human* worker00 = new Worker();
    //cout << worker00->GetInfo();

    //Human* student00 = new Student();
    //cout << student00->GetInfo();

    //cout << worker00->GetTotal();
    //cout << student00->GetTotal();


    AdressBook adressBook = AdressBook();
    adressBook.run();

    return 0;
}


