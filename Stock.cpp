#include "Stock.h"

//return the stock name
std::string Stock::stock_nameIs() const
{
    return stock_name_;
}

//return the stock code number
unsigned int Stock::code_numberIs() const
{
    return code_number_;
}

//return the stock price
unsigned int Stock::priceIs() const
{
    return price_;
}

void Stock::updateStock_name( const std::string& stock_name )
{
    stock_name_ = stock_name;
}

void Stock::updateCode_number( unsigned int code_number )
{
    code_number_ = code_number;
}

void Stock::updatePrice( unsigned int price )
{
    price_ = price;
}

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
std::ostream& operator<<( std::ostream& out, const Stock& stock )
{
    out << std::setw( 15 ) << "Stock name: " << stock.stock_nameIs() << '\n'
        << std::setw( 15 ) << "Code number: " << stock.code_numberIs() << '\n'
        << std::setw( 15 ) << "Stock price: " << stock.priceIs() << '\n';
    return out;
}