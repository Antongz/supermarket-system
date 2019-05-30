#include "Menu.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Menu::Menu()
{

}

//welcome
void Menu::welcomeMenu()
{
    cout << "\033[35;1m ================================================ \033[0m \n";
    cout << "\033[35;5m       ʕ•ᴥ•ʔ Please choose the options ʕ•ᴥ•ʔ       \033[0m \n\n";
    cout << "\033[35;1m |         ( • •)~ 1: Admin Menu ~(• • )        | \033[0m \n";
    cout << "\033[35;1m |  ( • •)~ 2: Exit the Store and Quit ~(• • )  | \033[0m \n\n";
    cout << "\033[35;5m       ʕ•ᴥ•ʔ Please choose the options ʕ•ᴥ•ʔ       \033[0m \n";
    cout << "\033[35;1m ================================================ \033[0m \n";
    //cout << "\033[41;1mRed Underline Text\033[0m" << endl;
    int option1;
    cout << "\nChoose an option from the menu ";
    cin >> option1;
    switch (option1) {
    case 1: {
        cout.flush();
        system("clear");
        displayMenu();
        break;
     }

    case 2: {
        system("clear");
        exit(0);
        break;
     }
     }
}

//display the menu main function
void Menu::displayMenu()
{
    cout << "\033[35;1m ================================================ \033[0m \n";
    cout << "\033[35;5m        ʕ•ᴥ•ʔ Please choose the options ʕ•ᴥ•ʔ      \033[0m \n\n";
    cout << "\033[35;1m |       0: Back to the welcome menu            | \033[0m \n";
    cout << "\033[35;1m |       1: Add a stock to the store            | \033[0m \n";
    cout << "\033[35;1m |       2: Remove stock from the store         | \033[0m \n";
    cout << "\033[35;1m |       3: Display the number of stocks        | \033[0m \n";
    cout << "\033[35;1m |       4: Find a stock by its information     | \033[0m \n";
    cout << "\033[35;1m |       5: Display the list of all stocks      | \033[0m \n";
    cout << "\033[35;1m |       6: Display menu option                 | \033[0m \n";
    cout << "\033[35;1m |       7: Exit the Store and quit             | \033[0m \n\n";
    cout << "\033[35;5m        ʕ•ᴥ•ʔ Please choose the options ʕ•ᴥ•ʔ      \033[0m \n";
    cout << "\033[35;1m ================================================ \033[0m \n";
}

//select the funcion by using switch case
bool Menu::menuSelection( int option, Store* shop )
{

    switch( static_cast<unsigned int>(option) )
    {

    case 0:
     {
        cout.flush();
        system("clear");

        welcomeMenu();
        break;
     }

    case 1:
    {
        addStockInformation( shop );

        cout.flush();
        system( "clear" );

        displayMenu();

        cout << "\nYou have entered a stock into the store.\n";
        break;
    }
    case 2:
    {
        if( shop->totalStocks() > 0 )
        {
            removeStock( shop );

            cout.flush();
            system( "clear" );

            displayMenu();

            cout << "\nYou have removed a stock from the store.\n";
        }
        else
        {
            cout << "\nThere are no stocks in store.\n";
        }
        break;
    }
    case 3:
    {
        unsigned int numStocks = shop->totalStocks();
        if( numStocks != 1 )
        {
            cout << "\nThere are " << numStocks << " stocks in our store.\n";
        }
        else
        {
            cout << "\nThere is 1 stock in our store.\n";
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
            cout << "\nThere are no stocks to display.\n";
        }
        break;
    }
    case 6:
    {
        cin.ignore();
        cout.flush();
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
        cout << "\nInvalid selection please try again.\n";
        break;
    }
    }
    return true;
}

void Menu::addStockInformation( Store* shop )
{
    unsigned int code_number = 0;
    unsigned int price = 0;
    string stock_name, stockcode;

    cin.ignore();

    cout << "Please enter the stocks barcode: ";
    getline( cin, stockcode );

    cout << "Please enter the stocks  name: ";
    getline( cin, stock_name );

    cout << "Please enter the stocks code number: ";
    cin >> code_number;

    cout << "Please enter the stocks price: ";
    cin >> price;

    Stock stock( stock_name, code_number, price );
    shop->addStock( stockcode, stock );
}

void Menu::removeStock( Store* shop )
{
    unsigned int numStocks = shop->totalStocks();
    if( numStocks == 0 )
    {
        cout << "\nThere are 0 stocks in store; nothing to remove.\n";
        return;
    }

    string stockcode;

    cin.ignore();

    cout << "\nRemove stock by stock barcode\n";
    cout << "Enter the stocks stock barcode: ";

    getline( cin, stockcode );
    shop->removeStock( stockcode );
}

void Menu::displayStock( Store* shop )
{
    unsigned int numStocks = shop->totalStocks();
    if( numStocks == 0 )
    {
        cout << "\nThere are 0 stocks in the store; nothing to display.\n";
        return;
    }

    string stockcode;

    cin.ignore();

    cout << "\nFind stock by stock barcode\n";
    cout << "Enter the stocks stock code: ";

    getline( cin, stockcode );
    Stock* stock = shop->findStock( stockcode );
    if( stock )
    {
        cout << *stock;
    }
    else
    {
        cout << "\nStock was not found.\n";
    }
}
