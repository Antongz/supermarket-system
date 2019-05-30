#ifndef MENU_H
#define MENU_H

#include "Store.h"
#include <map>
#include <limits>


class Menu
{
private:
    string password;

public:
    Menu();
    //string password;
    void setPassword(string x);
    void displayMenu();
    void welcomeMenu();

    bool menuSelection( int option, Store* shop );
    void addStockInformation( Store* shop );
    void removeStock( Store* shop );
    void displayStock( Store* shop );

};

#endif
