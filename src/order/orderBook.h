#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <map>
#include "order.h"
#include "orderKey.h"

namespace Order
{
    class OrderBook
    {
    private:
        Direction m_direction{};
        std::map<OrderKey, Order, orderKeyCmp> m_book;
        
    public:
        OrderBook() = delete;
        OrderBook(Direction direction);

        bool add(Order order);
        bool remove(Order order) ;
        Order getFirst();

        int size();
        bool empty();
    };
} // namespace Order

#endif