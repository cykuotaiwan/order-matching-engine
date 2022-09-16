#include "orderBook.h"

namespace order
{
    OrderBook::OrderBook(Direction direction)
        : m_direction(direction)
    {
    }

    bool OrderBook::add(Order order)
    {
        OrderKey key = order.getOrderKey();
        this->m_book.emplace(key, order);

        return this->m_book.find(key) != this->m_book.end();
    }

    bool OrderBook::remove(Order order)
    {
        auto it = this->m_book.find(order.getOrderKey());
        this->m_book.erase(it);

        return this->m_book.find(order.getOrderKey()) == this->m_book.end();
    }

    Order OrderBook::getFirst()
    {
        return this->m_book.begin()->second;
    }

    int OrderBook::size()
    {
        return this->m_book.size();
    }

    bool OrderBook::empty()
    {
        return this->m_book.empty();
    }

} // namespace order
