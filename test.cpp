#include<bits/stdc++.h>

using namespace std;

//hesd of stock
class Stock
{

private:
    unsigned int code_number_;  // stocks are allocated by code number on creation.
    unsigned int price_;  // stocks are allocated by price on creation.
    string stock_name_;  // stocks are allocated by stock name on creation.

public:
    //default constructors
    Stock() = default;
    //define a stock name and codenumber
    Stock( string stock_name, unsigned int code_number, unsigned int price ) :
        stock_name_{ move( stock_name ) },
        code_number_{ code_number },
        price_{ price }
    {}

    //return the stock name
    string stock_nameIs() const
    {
        return stock_name_;
    }
    //return the stock code number
    unsigned int code_numberIs() const
    {
        return code_number_;
    }
    //return the stock price
    unsigned int priceIs() const
    {
        return price_;
    }
    //update the stock name
    void updateStock_name( const string& stock_name )
    {
        stock_name_ = stock_name;
    }
    //update the stock code number
    void updateCode_number( unsigned int code_number )
    {
        code_number_ = code_number;
    }
    //update the stock price
    void updatePrice( unsigned int price )
    {
        price_ = price;
    }
};

// operator to compare the stock information that user enter in a right formal
bool operator==( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  == other.stock_nameIs()  &&
             first.code_numberIs() == other.code_numberIs() &&
             first.priceIs() == other.priceIs() );
}

bool operator!=( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  != other.stock_nameIs()  ||
             first.code_numberIs() != other.code_numberIs() ||
             first.priceIs() != other.priceIs() );
}

//output stocks name,code number and price
ostream& operator<<( ostream& out, const Stock& stock )
{
    out << setw( 15 ) << "Stock name: " << stock.stock_nameIs() << '\n'
        << setw( 17 ) << "Code number: " << stock.code_numberIs() << '\n'
        << setw( 16 ) << "Stock price: " << stock.priceIs() << '\n';
    return out;
}

//head of store
class Store
{
public:
    //store elements in the store by using map
    typedef unordered_multimap<string, Stock> StoreMap;
    typedef const unordered_multimap<string, Stock> StoreMapConst;

private:
    StoreMap stocks_;  //creat the storemap

public:
    Store() = default;

    //add stock to the store
    void addStock( const string& stockcode, Stock& stock )
     {
        stocks_.insert( move( pair<string, Stock>( stockcode, stock ) ) );
     }

    //remove stock from the store
    void removeStock( const string& stockcode )
     {
        stocks_.erase( stockcode );
     }

    //find a stock by its information
    //return corresponding goods information
    Stock* findStock( const string& stockcode )
     {
        auto it = stocks_.find( stockcode );
        return &it->second;
     }

    //dispaly the total stocks in the store
    //return number of goods
    size_t totalStocks() const
     {
        return stocks_.size();
     }

    //display the stock information in the store
    void displayStore()
     {
        StoreMapConst::const_iterator it = stocks_.begin();
        for( ; it != stocks_.end(); ++it )
          {
            cout << "Stock Code " << it->first << '\n' << it->second << endl;
          }
     }

};

//head of menu
class Menu
{

public:
    Menu(){}

    //welcome menu
    void welcomeMenu()
     {
        cout << "================================================\n";
        cout << "1: Admin Menu\n";
        //cout << "2: Users Menu\n";
        cout << "3: Exit the Store and Quit\n";
        cout << "================================================\n";

        int option1;
        cout << "\nChoose an option from the menu ";
        cin >> option1;
        switch (option1){
        case 1:{
            cout.flush();
            system("clear");
            displayMenu();
            break;
          }
/*
        case 2: {
            cout.flush();
            system("clear");
            userMenu();
            break;
          }
*/
        case 3:{
            system("clear");
            exit (0);
            break;
          }
          }
     }

/*
    //user menu
    void userMenu()
     {
        cout << "================================================\n";
        cout << "0: Back to the welcome menu\n";
        //cout << "1: Add to cart\n";
        cout << "2: Find a stock by its information\n";
        cout << "3: Display the list of all stocks\n";
        cout << "4: Exit the Store and Quit\n";
        cout << "================================================\n";

        int command;
        cout << "\nChoose an option from the menu ";
        cin >> command;
        Store* shop;
        switch( static_cast<unsigned int>(command) )
          {
        case 0:
          {
            cout.flush();
            system("clear");
            welcomeMenu();
            break;
          }
        case 2:
          {
            displayStock( shop );
            break;
          }

        case 3:
          {
            unsigned int numStocks = shop->totalStocks();
            if( numStocks > 0 )
               {
                shop->displayStore();
               }
            else
               {
                cout << "\nThere are no items to display.\n";
               }
            break;
          }

        case 4:
          {
            system("clear");
            exit(0);
            break;
          }
        default:
          {
            cout << "\nInvalid selection please try again.\n";
            break;
          }
          }
     }
*/
    //display the menu main function
    void displayMenu()
     {
        cout << "================================================\n";
        cout << "0: Back to the welcome menu\n";
        cout << "1: Add a stock to the store\n";
        cout << "2: Remove stock from the store\n";
        cout << "3: Display the number of stocks in the Store\n";
        cout << "4: Find a stock by using information\n";
        cout << "5: Display the list of all stocks\n";
        cout << "6: Display menu option\n";
        cout << "7: Exit the Store and Quit\n";
        cout << "================================================\n";
     }

    //select the funcion by using switch case
    bool menuSelection( int option, Store* shop )
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

    //add a stock to the store
    //enter goods information
    void addStockInformation( Store* shop )
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

        Stock stock(stock_name, code_number, price );
        shop->addStock( stockcode, stock );
     }

    //remove a stock from the store
    void removeStock( Store* shop )
     {
        unsigned int numStocks = shop->totalStocks();
        if( numStocks == 0 )
          {
            cout << "\nThere are 0 items in store; nothing to remove.\n";
            return;
          }

        string stockcode;

        cin.ignore();

        cout << "\nRemove stock by stock barcode\n";
        cout << "Enter the stocks stock barcode: ";

        getline( cin, stockcode );
        shop->removeStock( stockcode );
     }

    //display the stock detail
    //display goods information on the console
    void displayStock( Store* shop )
     {
        unsigned int numStocks = shop->totalStocks();
        if( numStocks == 0 )
          {
            cout << "\nThere are 0 items in the store; nothing to display.\n";
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
/*
    void runAdmin()
     {
        Store shop;
        int option = 0;
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

        while( menuSelection( option, &shop ) );
        cout << "\nPress any key and enter to quit.\n";
        cin.get();
      }
*/
};

int main()
{
    Store shop;  //create a store 'shop'
    Menu Menu;  //create a menu 'menu'
    cout << "Welcome to the Supermarket!\n";
    Menu.welcomeMenu();  //display the welcome menu
    //Menu.runAdmin();

    int option = 0;  //set the defalt option
    do
    {
        cout << "\nChoose an option from the menu ";
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


