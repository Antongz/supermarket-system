#include "Stock.h"
#include <iomanip>

using namespace std;

//return the stock name
string Stock::stock_nameIs() const
{
    return stock_name_;
}

//return the stock price
float Stock::priceIs() const
{
    return price_;
}

void Stock::updateStock_name( const string& stock_name )
{
    stock_name_ = stock_name;
}

void Stock::updatePrice( float price )
{
    price_ = price;
}


// operator to compare the stock information that user enter in a right formal
bool operator==( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  == other.stock_nameIs()  &&
             first.priceIs() == other.priceIs() );
}

bool operator!=( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  != other.stock_nameIs()  ||
             first.priceIs() != other.priceIs());
}

//output stocks name,code number and price
ostream& operator<<( ostream& out, const Stock& stock )
{
    out << "Stock name: " << stock.stock_nameIs() << '\n'
        << setprecision(5) << "Stock price: " << stock.priceIs() << '\n';
    return out;
}