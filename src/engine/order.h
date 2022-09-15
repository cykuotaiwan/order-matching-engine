#ifndef ORDER_H
#define ORDER_H

#include <stdint.h>
#include "direction.h"
#include "tradeMode.h"

namespace engine
{
    typedef struct Order
    {
        uint64_t id;
        uint64_t price; // cent
        Direction direction;
        TradeMode mode;
        uint64_t amount;
    }Order;
    
} // namespace engine

#endif