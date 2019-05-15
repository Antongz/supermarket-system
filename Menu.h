#ifndef MENU_H
#define MENU_H

#include "Store.h"
#include <map>
#include <limits>


class Menu
{

public:
    Menu();
    void displayMenu();

    bool menuSelection( int option, Store* shop );
    void addStockInformation( Store* shop );
    void removeStock( Store* shop );
    void displayStock( Store* shop );
};

#endif