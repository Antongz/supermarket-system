#ifndef MENU_H
#define MENU_H

#include "Store.h"
#include <map>
#include <limits>


class Menu
{

public:
    Menu();
    void displayMenu(); //display the menu

    bool menuSelection( int option, Store* shop ); //select the function frome the menu
    void addStockInformation( Store* shop );  //add the stock by its information
    void removeStock( Store* shop );          //remove stock from the store
    void displayStock( Store* shop );         // display the stock in the store
};

#endif