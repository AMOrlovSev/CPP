#include <iostream>
#include <windows.h>

using namespace std;

template<class T>
T avverage(T arr[], int size) {
    T avverage = 0;
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return avverage = sum / size;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr[] = { 9,3,17,6,5,4,31,2,12 };
    long arrl[] = { 9,3,17,6,5,4,31,2,12 };
    double arrd[] = { 2.1, 2.3,1.7,6.6,5.3,2.44,3.1,2.4,1.2 };
    char arrc[] = { 'a', 'b', 'c', 'd'};

    int k1 = sizeof(arr) / sizeof(arr[0]);
    int k2 = sizeof(arrl) / sizeof(arr[0]);
    int k3 = sizeof(arrd) / sizeof(arrd[0]);
    int k4 = sizeof(arrc) / sizeof(arrc[0]) - 1;

    cout << avverage(arr, k1) << endl;
    cout << avverage(arrl, k2) << endl;
    cout << avverage(arrd, k3) << endl;
    cout << avverage(arrc, k4) << endl;
}