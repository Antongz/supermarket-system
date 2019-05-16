#include<iostream>
#include "Stock.h"

using namespace std;

// test main program for stock class
int main()
{
    Stock milk ("milk", 1, 20);

    cout << "Description :" << milk.stock_nameIs() << endl;
    cout << "Item number :" << milk.code_numberIs() << endl;
    cout << "Stock price: " << milk.priceIs() << endl;
}