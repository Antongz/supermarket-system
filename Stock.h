#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


class Stock
{

private:
    float price_;        // stocks are allocated by price on creation.
    std::string stock_name_;    // stocks are allocated by stock name on creation.


public:
    Stock() = default;
    Stock( std::string stock_name, float price ) :
        stock_name_{ std::move( stock_name ) },
        price_{ price }
    {}

    std::string stock_nameIs() const;     //return the stock name
    float priceIs() const;         //return the stock price

    void updateStock_name( const std::string& stock_name ); //update the stock name
    void updatePrice( float price );                 //update the stock price

};

// operator to compare the stock information that user enter in a right formal
bool operator==( const Stock& first, const Stock& other );
bool operator!=( const Stock& first, const Stock& other );
std::ostream& operator<<( std::ostream& out, const Stock& stock );

#endif // STOCK_H