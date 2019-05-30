#ifndef MENU_H
#define MENU_H

#include "Store.h"
#include "Discout_stock.h"
#include <map>
#include <fstream>
#include <limits>

using namespace std;

class Menu
{

private:
    float price;
    float finalprice;
    float discout;
    int option1;
    string pass;
    string password;

public:
    Menu();
    void welcomeMenu();
    void displayMenu(); //display the menu

    bool menuSelection( int option, Store* shop ); //select the function frome the menu
    void addStockInformation( Store* shop );  //add the stock by its information
    void removeStock( Store* shop );          //remove stock from the store
    void displayStock( Store* shop );         // display the stock in the store
    ~Menu();
};

#endif