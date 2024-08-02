﻿#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(const T& container, const string& separator) {
    bool first = true;
    for (const auto& element : container) {
        if (!first) {
            cout << separator;
        }
        cout << element;
        first = false;
    }
    cout << "\n";
}

int main() {
    vector<int> data = { 1, 2, 3 };
    print(data, ", "); // на экране: 1, 2, 3
    return 0;
}