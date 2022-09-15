#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <map>
#include "order.h"
#include "orderKey.h"

namespace order
{
    class OrderBook
    {
    private:
        Direction m_direction{};
        std::map<OrderKey, Order> m_book;
        
        void sort();
    public:
        OrderBook() = delete;
        OrderBook(Direction direction);

        bool add(Order order);
        bool remove(Order order) ;
        Order getFirst();

        int size();
        bool empty();
    };
} // namespace order

#endif