#include "Menu.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Menu::Menu()
{

}

//display the menu main function
void Menu::displayMenu()
{
    std::cout << "================================================\n";
    std::cout << "1: Add a stock to the store\n";
    std::cout << "2: Remove stock from the store\n";
    std::cout << "3: Display the number of stocks in the Store\n";
    std::cout << "4: Find a stock by its information\n";
    std::cout << "5: Display the list of all stocks\n";
    std::cout << "6: Display menu option\n";
    std::cout << "7: Exit the Store and quit\n";
    std::cout << "================================================\n";
}

//select the funcion by using switch case
bool Menu::menuSelection( int option, Store* shop )
{

    switch( static_cast<unsigned int>(option) )
    {
    case 1:
    {
        addStockInformation( shop );

        std::cout.flush();
        system( "clear" );

        displayMenu();

        std::cout << "\nYou have entered a stock into the store.\n";
        break;
    }
    case 2:
    {
        if( shop->totalStocks() > 0 )
        {
            removeStock( shop );

            std::cout.flush();
            system( "clear" );

            displayMenu();

            std::cout << "\nYou have removed a stock from the store.\n";
        }
        else
        {
            std::cout << "\nThere are no stocks in store.\n";
        }
        break;
    }
    case 3:
    {
        unsigned int numStocks = shop->totalStocks();
        if( numStocks != 1 )
        {
            std::cout << "\nThere are " << numStocks << " stocks in our store.\n";
        }
        else
        {
            std::cout << "\nThere is 1 stock in our store.\n";
        }
        break;
    }
    case 4:
    {
        displayStock( shop );
        break;
    }
    case 5:
    {
        unsigned int numStocks = shop->totalStocks();
        if( numStocks > 0 )
        {
            shop->displayStore();
        }
        else
        {
            std::cout << "\nThere are no stocks to display.\n";
        }
        break;
    }
    case 6:
    {
        std::cin.ignore();
        std::cout.flush();
        system( "clear" );
        displayMenu();
        break;
    }
    case 7:
    {
        return false;
    }
    default:
    {
        std::cout << "\nInvalid selection please try again.\n";
        break;
    }
    }
    return true;
}

//enter goods information
void Menu::addStockInformation( Store* shop )
{
    unsigned int code_number = 0;
    unsigned int price = 0;
    std::string stock_name, stockcode;

    std::cin.ignore();

    std::cout << "Please enter the stocks barcode: ";
    std::getline( std::cin, stockcode );

    std::cout << "Please enter the stocks  name: ";
    std::getline( std::cin, stock_name );

    std::cout << "Please enter the stocks code number: ";
    std::cin >> code_number;

    std::cout << "Please enter the stocks price: ";
    std::cin >> price;

    Stock stock( stock_name, code_number, price );
    shop->addStock( stockcode, stock );
}

//remove goods from the store
void Menu::removeStock( Store* shop )
{
    unsigned int numStocks = shop->totalStocks();
    if( numStocks == 0 )
    {
        std::cout << "\nThere are 0 stocks in store; nothing to remove.\n";
        return;
    }

    std::string stockcode;

    std::cin.ignore();

    std::cout << "\nRemove stock by stock barcode\n";
    std::cout << "Enter the stocks stock barcode: ";

    std::getline( std::cin, stockcode );
    shop->removeStock( stockcode );
}

//display goods information on the console
void Menu::displayStock( Store* shop )
{
    unsigned int numStocks = shop->totalStocks();
    if( numStocks == 0 )
    {
        std::cout << "\nThere are 0 stocks in the store; nothing to display.\n";
        return;
    }

    std::string stockcode;

    std::cin.ignore();

    std::cout << "\nFind stock by stock barcode\n";
    std::cout << "Enter the stocks stock code: ";

    std::getline( std::cin, stockcode );
    Stock* stock = shop->findStock( stockcode );
    if( stock )
    {
        std::cout << *stock;
    }
    else
    {
        std::cout << "\nStock was not found.\n";
    }
}