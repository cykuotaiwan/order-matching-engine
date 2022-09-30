#include <iostream>
#include "../src/order/orderKey.h"
#include "../src/util/testUtil.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    // 0. Test default ctor, should fail because it is deleted
    // Order::orderKey key;

    // 1. Test custom ctor
    Util::printTestMessage("[Test-1] Test custom ctor");
    Order::OrderKey *key = new Order::OrderKey(2, 1000, Order::Direction::BUY);
    bool result1 = (key != nullptr);
    if (result1)
        Util::printPassMessage("Construction succeed.");
    else
    {
        Util::printFailMessage("Construction fail.");
        return 1;
    }

    // 2. Test operator ==
    Util::printTestMessage("[Test-2] Test operator ==");
    Order::OrderKey key2{2, 1000, Order::Direction::BUY};
    Order::OrderKey keyDiffID{3, 1000, Order::Direction::BUY};
    Order::OrderKey keyDiffPrice{2, 2000, Order::Direction::BUY};
    Order::OrderKey keyDiffDir{2, 1000, Order::Direction::SELL};
    bool result2 = (*key == key2);
    if (result2)
        Util::printPassMessage("Compare 2 identical obj");
    else
    {
        Util::printFailMessage("Compare 2 identical obj");
        return 1;
    }
    result2 = !(*key == keyDiffID);
    result2 &= !(*key == keyDiffPrice);
    result2 &= !(*key == keyDiffDir);
    if (result2)
        Util::printPassMessage("Compare objs with different element");
    else
    {
        Util::printFailMessage("Compare objs with different element");
        return 1;
    }

    return 0;
}
