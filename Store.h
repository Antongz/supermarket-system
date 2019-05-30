#ifndef STORE_H
#define STORE_H

#include "Stock.h"
#include <unordered_map>

class Store
{

public:
    //store elements in the store by using map
    typedef std::unordered_multimap<std::string, Stock> StoreMap;
    typedef const std::unordered_multimap<std::string, Stock> StoreMapConst;

private:
    StoreMap stocks_; //creat the storemap
public:
    Store() = default;
    void addStock( const std::string& stockcode, Stock& stock ); //add stock
    void removeStock( const std::string& stockcode);  //removes stock
    Stock* findStock( const std::string& stockcode ); //find stock
    std::size_t totalStocks() const; //dispaly the total stocks in the store
    void displayStore(); //display the stock information in the store
    ~Store();

};

#endif // STORE_H