#include<iostream>
#include "Stock.h"

using namespace std;

// main program
int main()
{
    Stock milk ("milk", 01);

    cout << "Description :" << milk.descriptionIs() << endl;
    cout << "Item number :" << milk.code_numberIs() << endl;
}