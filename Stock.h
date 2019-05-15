#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <iomanip>

class Stock
{
private:
    unsigned int code_number_;
    unsigned int price_;
    std::string stock_name_;

public:
    Stock() = default;
    Stock( std::string stock_name, unsigned int code_number, unsigned int price ) :
        stock_name_{ std::move( stock_name ) },
        code_number_{ code_number },
        price_{ price }
    {}

    std::string stock_nameIs() const
    {
        return stock_name_;
    }
    unsigned int code_numberIs() const
    {
        return code_number_;
    }
    unsigned int priceIs() const
    {
        return price_;
    }
    void updateStock_name( const std::string& stock_name )
    {
        stock_name_ = stock_name;
    }
    void updateCode_number( unsigned int code_number )
    {
        code_number_ = code_number;
    }
    void updatePrice( unsigned int price )
    {
        price_ = price;
    }
};

bool operator==( const Stock& first, const Stock& other );
bool operator!=( const Stock& first, const Stock& other );
std::ostream& operator<<( std::ostream& out, const Stock& stock );

#endif // STOCK_H