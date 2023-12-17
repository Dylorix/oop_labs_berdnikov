#include<iostream>
#include"arr3.h"


int main() {
    setlocale(LC_ALL, "Russian");

    MyArrays::Array3d<int> myarr(2, 3, 3);

    myarr.SetValues0(0, { {1, 24, 23}, {45, 6, 67}, {3, 104, 112} });
    myarr.SetValues0(1, { {13, 4, 1}, {19, 34, 19}, {21, 20, 2} });

    myarr.Print();

    std::vector<int> slice = myarr.GetValues0(1);
    for (int i : slice) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    myarr.ones();
    myarr.Print();

    return 0;
}