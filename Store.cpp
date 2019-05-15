#include "Store.h"

void Store::addStock( const std::string& stockcode, Stock& stock )
{
    stocks_.insert( std::move( std::pair<std::string, Stock>( stockcode, stock ) ) );
}

void Store::removeStock( const std::string& stockcode )
{
    stocks_.erase( stockcode );
}

Stock* Store::findStock( const std::string& stockcode )
{
    auto it = stocks_.find( stockcode );
    return &it->second;
}

std::size_t Store::totalStocks() const
{
    return stocks_.size();
}

void Store::displayStore()
{
    StoreMapConst::const_iterator it = stocks_.begin();
    for( ; it != stocks_.end(); ++it )
    {
        std::cout << "Stock Code " << it->first << '\n'
                  << it->second << std::endl;
    }
}