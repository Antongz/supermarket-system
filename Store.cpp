#include "Store.h"

//add goods to the store
void Store::addStock( const std::string& stockcode, Stock& stock )
{
    stocks_.insert( std::move( std::pair<std::string, Stock>( stockcode, stock ) ) );
}

//remove goods from the store
void Store::removeStock( const std::string& stockcode )
{
    stocks_.erase( stockcode );
}

//return corresponding goods information
Stock* Store::findStock( const std::string& stockcode )
{
    auto it = stocks_.find( stockcode );
    return &it->second;
}

//return number of goods
std::size_t Store::totalStocks() const
{
    return stocks_.size();
}

//display all the stock information in the store
void Store::displayStore()
{
    StoreMapConst::const_iterator it = stocks_.begin();
    for( ; it != stocks_.end(); ++it )
    {
        std::cout << "Stock Code " << it->first << '\n'
                  << it->second << std::endl;
    }
}

Store::~Store()
{

}