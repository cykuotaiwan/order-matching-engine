#include <iostream>
#include "../src/order/orderBook.h"
#include "../src/util/testUtil.h"

int main(int argc, char const *argv[])
{
    // 0. Test default ctor, should fail because it is deleted
    // Order::OrderBook book;

    // 1. Test custrom ctor
    Util::printTestMessage("[Test-1] Test custom ctor:");
    Order::OrderBook *book = new Order::OrderBook(Order::Direction::SELL);
    auto dir = book->getDirection();

    bool result = true;
    result &= book != nullptr;
    result &= dir == Order::Direction::SELL;
    if (result)
    {
        Util::printPassMessage("Construction succeed.");
    }
    else
    {
        Util::printFailMessage("Construction fail.");
        return 1;
    }

    // 2. Test empty()
    Util::printTestMessage("[Test-2] Test empty()");
    result = book->empty();
    if (result)
    {
        Util::printPassMessage("Test empty() succeed.");
    }
    else
    {
        Util::printFailMessage("Test empty() fail.");
        return 2;
    }

    // 3. Test add()
    Util::printTestMessage("[Test-3] Test add()");
    auto order1 = Order::Order(2, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
    result = book->add(order1);
    result &= book->size() == 1;
    result &= book->getFirst() == order1;
    if (result)
    {
        Util::printPassMessage("Test add() succeed.");
    }
    else
    {
        Util::printFailMessage("Test add() fail.");
        return 3;
    }

    // 4. Test remove()
    Util::printTestMessage("[Test-4] Test remove()");
    auto order2 = Order::Order(3, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
    result = book->remove(order2);
    result &= book->size() == 1;
    result &= book->remove(order1);
    result &= book->empty();
    if (result)
    {
        Util::printPassMessage("Test remove() succeed.");
    }
    else
    {
        Util::printFailMessage("Test remove() fail.");
        return 4;
    }

    return 0;
}
