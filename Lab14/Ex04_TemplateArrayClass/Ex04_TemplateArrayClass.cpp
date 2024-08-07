﻿#include <iostream>
#include <windows.h>
//using namespace std;

//class array
//{
//public:
//    array(int size);
//    long sum();
//    int average_value();
//    void show_array();
//    int add_value(int);
//
//private:
//    int* data;
//    int size;
//    int index;
//};
template<class T, class T1> class array
{
public:
    array(int size);
    T1 sum();
    T average_value();
    void show_array();
    int add_value(T);
private:
    T* data;
    int size;
    int index;
};

//array::array(int size)
//{
//    data = new int[size];
//    if (data == NULL)
//    {
//        std::cerr << "Error memory ---- exit program" << std::endl;
//        exit(1);
//    }
//    array::size = size;
//    array::index = 0;
//}
template<class T, class T1> array<T, T1>::array(int size)
{
    data = new T[size];
    if (data == NULL)
    {
        std::cerr << "Error memory ---- exit program" << std::endl;
        exit(1);
    }
    array::size = size;
    array::index = 0;
}

//long array::sum()
//{
//    long sum = 0;
//    for (int i = 0; i < index; i++) sum += data[i];
//    return(sum);
//}
template<class T, class T1> T1 array<T, T1>::sum()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++) sum += data[i];
    return(sum);
}

//int array::average_value()
//{
//    long sum = 0;
//    for (int i = 0; i < index; i++) sum += data[i];
//    return (sum / index);
//}
template<class T, class T1> T array<T, T1>::average_value()
{
    T1 sum = 0;
    for (int i = 0; i < index; i++) sum += data[i];
    return (sum / index);
}

//void array::show_array()
//{
//    for (int i = 0; i < index; i++) cout << data[i] << ' ';
//    cout << endl;
//}
template<class T, class T1> void array<T, T1>::show_array()
{
    for (int i = 0; i < index; i++) 
        std::cout << data[i] << ' ';
    std::cout << std::endl;
}

//int array::add_value(int value)
//{
//    if (index == size) return(-1); // массив полон 
//    else
//    {
//        data[index] = value;
//        index++;
//        return(0); // успешно 
//    }
//}
template<class T, class T1> int array<T, T1>::add_value(T value)
{
    if (index == size) return(-1); // массив полон 
    else
    {
        data[index] = value;
        index++;
        return(0); // успешно 
    }
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    array<int, long> numbers(100);
    array<float, float> values(200);

    int i;
    for (i = 0; i < 50; i++) numbers.add_value(i);
    numbers.show_array();
    std::cout << "Sum = " << numbers.sum() << std::endl;
    std::cout << "Average = " << numbers.average_value() << std::endl;
    for (i = 0; i < 100; i++) 
        values.add_value(i * 100);
    values.show_array();
    std::cout << "Sum = " << values.sum() << std::endl;
    std::cout << "Average = " << values.average_value() << std::endl;
}
