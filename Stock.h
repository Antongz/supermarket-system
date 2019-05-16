#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <iomanip>

class Stock
{

private:
    unsigned int code_number_;  // stocks are allocated by code number on creation.
    unsigned int price_;        // stocks are allocated by price on creation.
    std::string stock_name_;    // stocks are allocated by stock name on creation.

public:
    Stock() = default;
    Stock( std::string stock_name, unsigned int code_number, unsigned int price ) :
        stock_name_{ std::move( stock_name ) },
        code_number_{ code_number },
        price_{ price }
    {}

    std::string stock_nameIs() const;     //return the stock name
    unsigned int code_numberIs() const;   //return the stock code number
    unsigned int priceIs() const;         //return the stock price

    void updateStock_name( const std::string& stock_name ); //update the stock name
    void updateCode_number( unsigned int code_number );     //update the stock code number
    void updatePrice( unsigned int price );                 //update the stock price

};

// operator to compare the stock information that user enter in a right formal
bool operator==( const Stock& first, const Stock& other );
bool operator!=( const Stock& first, const Stock& other );
std::ostream& operator<<( std::ostream& out, const Stock& stock );

#endif // STOCK_H