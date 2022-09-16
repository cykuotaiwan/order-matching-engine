#include <iostream>
#include "../src/order/orderBook.h"

int main(int argc, char const *argv[])
{
    Order::OrderBook book(Order::Direction::BUY);

    std::cout << &book << std::endl;

    return 0;
}
