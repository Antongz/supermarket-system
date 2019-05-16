#include "Menu.h"
#include <vector>


int main()
{
    Store shop; //create a store 'shop'
    Menu Menu;  //create a menu 'menu'
    std::cout << "Welcome to the Supermarket!\n";
    Menu.displayMenu(); //display the menu

    int option = 0; //set the defalt option
    do
    {
        std::cout << "\nChoose an option from the menu :";
        std::cin >> option;
        if( std::cin.fail() )
        {
            std::cout << "\nPlease enter an integer\n";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }
        std::cout << '\n';
    }

    while( Menu.menuSelection( option, &shop ) );
    std::cout << "\nPress any key and enter to quit.\n";
    std::cin.get();
    return 0;
}

