#ifndef STORE_H
#define STORE_H

#include "Stock.h"
#include <unordered_map>

class Store
{
public:
    typedef std::unordered_multimap<std::string, Stock> StoreMap;
    typedef const std::unordered_multimap<std::string, Stock> StoreMapConst;

private:
    StoreMap stocks_;
public:
    Store() = default;

    void addStock( const std::string& stockcode, Stock& stock );
    void removeStock( const std::string& stockcode);

    Stock* findStock( const std::string& stockcode );

    std::size_t totalStocks() const;

    void displayStore();
};

#endif // STORE_H