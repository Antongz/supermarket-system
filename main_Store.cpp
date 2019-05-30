#include "Menu.h"
#include <vector>
#include <fstream>

using namespace std;


int main()
{
    Store shop; //create a store 'shop'
    Store* shop1;
    shop1 = new Store;

    Menu Menu;  //create a menu 'menu'
    system("clear");
    cout << "*    *    *  ****  *     ****  ****      * *      ****" << endl;
    cout << " *   *   *   *     *     *     *  *     * * *     *   " << endl;
    cout << "  *  *  *    ****  *     *     *  *    *  *  *    ****" << endl;
    cout << "   * * *     *     *     *     *  *   *   *   *   *   " << endl;
    cout << "    * *      ****  ****  ****  ****  *    *    *  ****" << endl;
    Menu.welcomeMenu();

    int option = 0; //set the defalt option
    do
    {
        cout << "\nChoose an option from the menu :";
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
    delete []shop1;
}

