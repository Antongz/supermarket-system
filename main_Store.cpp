#include "Menu.h"
#include <vector>

using namespace std;

int main()
{
    Store shop;
    Menu Menu;
    //cout << "         \033[41;1m Welcome to the Supermarket! \033[0m\n";
    cout << "*    *    *  ****  *     ****  ****      * *      ****" << endl;
    cout << " *   *   *   *     *     *     *  *     * * *     *   " << endl;
    cout << "  *  *  *    ****  *     *     *  *    *  *  *    ****" << endl;
    cout << "   * * *     *     *     *     *  *   *   *   *   *   " << endl;
    cout << "    * *      ****  ****  ****  ****  *    *    *  ****" << endl;
    Menu.welcomeMenu();
    //Menu.displayMenu();

    int option = 0;
    do
    {
        cout << "\n ʕ•ᴥ•ʔ Choose an option from the menu ʕ•ᴥ•ʔ:";
        cin >> option;
        if( cin.fail() )
        {
            cout << "\nPlease enter an integer\n";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        cout << '\n';
    }

    while( Menu.menuSelection( option, &shop ) );
    cout << "\nPress any key and enter to quit.\n";
    cin.get();

    return 0;
}
