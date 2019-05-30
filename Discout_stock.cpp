#include "Discout_stock.h"

Discout_stock::Discout_stock()
{

}

float Discout_stock::discoutIs() const
{
    return discout_;
}

void Discout_stock::update_discout( float discout )
{
    discout_ = discout;
}
