#include <iostream>
#include "../src/order/orderBook.h"
#include "../src/util/testUtil.h"

int main(int argc, char const *argv[])
{
    // 0. Test default ctor, should fail because it is deleted
    // Order::OrderBook book;

    // 1. Test custrom ctor
    Util::printTestMessage("[Test-1] Test custom ctor:");
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto dir = book.getDirection();

        bool result = (dir == Order::Direction::SELL);
        if (result)
            Util::printPassMessage("Construction succeed.");
        else
            Util::printFailMessage("Construction fail.");
    }

    // 2. Test empty()
    Util::printTestMessage("[Test-2] Test empty():");
    {
        Order::OrderBook book(Order::Direction::SELL);
        bool result = (book.empty());
        if (result)
            Util::printPassMessage("Test empty() succeed.");
        else
            Util::printFailMessage("Test empty() fail.");
    }

    // 3. Test add()
    Util::printTestMessage("[Test-3] Test add():");
    // 3.1 Case normal
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order = Order::Order(2, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);

        bool result = book.add(order);
        result &= book.size() == 1;
        result &= book.getFirst() == order;
        if (result)
            Util::printPassMessage("Test normal case succeed.");
        else
            Util::printFailMessage("Test normal case fail.");
    }
    // 3.2 Case different direction
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order = Order::Order(2, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);

        bool result = !book.add(order);
        result &= book.empty();
        if (result)
            Util::printPassMessage("Test different direction case succeed.");
        else
            Util::printFailMessage("Test different direction case fail.");
    }

    // 4. Test remove()
    Util::printTestMessage("[Test-4] Test remove():");
    // 4.1 Case match
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order = Order::Order(3, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        book.add(order);

        bool result = book.remove(order);
        result &= book.empty();
        if (result)
            Util::printPassMessage("Test match case succeed.");
        else
            Util::printFailMessage("Test match case fail.");
    }
    // 4.2 Case unmatch
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order = Order::Order(3, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        auto order1 = Order::Order(2, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        book.add(order);

        bool result = book.remove(order1);
        result &= !book.empty();
        if (result)
            Util::printPassMessage("Test unmatch case succeed.");
        else
            Util::printFailMessage("Test unmatch case fail.");
    }
    // 4.3 Case remove empty obj
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order = Order::Order(3, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);

        bool result = !book.remove(order);
        if (result)
            Util::printPassMessage("Test empty object case succeed.");
        else
            Util::printFailMessage("Test empty object case fail.");
    }

    // 5. Test sotring -
    Util::printTestMessage("[Test-5] Test getFirst():");
    // 5.1 SELL same id, different price
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order1 = Order::Order(1, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(1, 2000, Order::Direction::SELL, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order2;
        if (result)
            Util::printPassMessage("Test SELL same id case succeed.");
        else
            Util::printFailMessage("Test SELL same id case fail.");
    }
    // 5.2 BUY same id, different price
    {
        Order::OrderBook book(Order::Direction::BUY);
        auto order1 = Order::Order(1, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(1, 2000, Order::Direction::BUY, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order1;
        if (result)
            Util::printPassMessage("Test BUY  same id case succeed.");
        else
            Util::printFailMessage("Test BUY  same id case fail.");
    }
    // 5.3 SELL same price, different id
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order1 = Order::Order(1, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(2, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order1;
        if (result)
            Util::printPassMessage("Test SELL same price case succeed.");
        else
            Util::printFailMessage("Test SELL same price case fail.");
    }
    // 5.4 BUY same price, different id
    {
        Order::OrderBook book(Order::Direction::BUY);
        auto order1 = Order::Order(1, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(2, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order1;
        if (result)
            Util::printPassMessage("Test BUY  same price case succeed.");
        else
            Util::printFailMessage("Test BUY  same price case fail.");
    }
    // 5.5 SELL different id, price
    {
        Order::OrderBook book(Order::Direction::SELL);
        auto order1 = Order::Order(1, 2000, Order::Direction::SELL, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(2, 1000, Order::Direction::SELL, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order1;
        if (result)
            Util::printPassMessage("Test SELL different id, price case succeed.");
        else
            Util::printFailMessage("Test SELL different id, price case fail.");
    }
    // 5.6 BUY different id, price
    {
        Order::OrderBook book(Order::Direction::BUY);
        auto order1 = Order::Order(1, 2000, Order::Direction::BUY, Order::TradeMode::ROD, 10);
        auto order2 = Order::Order(2, 1000, Order::Direction::BUY, Order::TradeMode::ROD, 10);

        book.add(order1);
        book.add(order2);

        auto orderFirst = book.getFirst();
        bool result = orderFirst == order2;
        if (result)
            Util::printPassMessage("Test BUY  different id, price case succeed.");
        else
            Util::printFailMessage("Test BUY  different id, price case fail.");
    }

    return 0;
}
