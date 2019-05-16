#include "Stock.h"
//？？？
bool operator==( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  == other.stock_nameIs()  &&
             first.code_numberIs() == other.code_numberIs() &&
             first.priceIs() == other.priceIs() );
}
///？？？
bool operator!=( const Stock& first, const Stock& other )
{
    return ( first.stock_nameIs()  != other.stock_nameIs()  ||
             first.code_numberIs() != other.code_numberIs() ||
             first.priceIs() != other.priceIs() );
}
//output goods name,code number and price
std::ostream& operator<<( std::ostream& out, const Stock& stock )
{
    out << std::setw( 15 ) << "Stock name: " << stock.stock_nameIs() << '\n'
        << std::setw( 15 ) << "Code number: " << stock.code_numberIs() << '\n'
        << std::setw( 15 ) << "Stock price: " << stock.priceIs() << '\n';
    return out;
}