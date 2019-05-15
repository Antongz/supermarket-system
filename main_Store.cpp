#include "Menu.h"
#include <vector>


int main()
{
    Store shop;
    Menu Menu;
    std::cout << "Welcome to the Supermarket!\n";
    Menu.displayMenu();

    int option = 0;
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

