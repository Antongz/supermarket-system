#ifndef DISCOUT_STOCK_H
#define DISCOUT_STOCK_H

#include "Stock.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class Discout_stock: public Stock
{
private:
    float discout_;

public:
    Discout_stock();
    Discout_stock( float discout ):
        discout_{ discout }
    {}

    float discoutIs() const;
    void update_discout( float discout );

};

#endif // DISCOUT_H