#include <iostream>
#include "../src/order/order.h"
#include "../src/util/testUtil.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // 0. Test default ctor, should fail because it is deleted
    // Order::Order order;

    // 1. Test custom ctor
    // custom 3 param ctor
    Util::printTestMessage("[Test-1] Test custom ctor: ");
    Order::Order* order = new Order::Order(2, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
    auto key = order->getOrderKey();
    
    bool result = true;
    result &= order != nullptr;
    
    Order::OrderKey key1{2, 1000, Order::Direction::BUY};
    result &= key == key1;

    if (result)
    {
        Util::printPassMessage("Construction succeed.");
    }
    else
    {
        Util::printFailMessage("Construction fail.");
        return 1;
    }

    return 0;
}
