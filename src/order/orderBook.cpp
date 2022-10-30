#include "orderBook.h"

namespace Order
{
    OrderBook::OrderBook(Direction direction)
        : m_direction(direction)
    {
    }

    bool OrderBook::add(Order &order)
    {
        if (order.getDirection() != m_direction)
            return false;

        OrderKey key = order.getOrderKey();
        this->m_book.emplace(key, order);

        return this->m_book.find(key) != this->m_book.end();
    }

    bool OrderBook::remove(Order &order)
    {
        if(m_book.empty())
            return false;
            
        auto it = this->m_book.find(order.getOrderKey());
        if (it != m_book.end() && order == it->second)
            this->m_book.erase(it);

        return this->m_book.find(order.getOrderKey()) == this->m_book.end();
    }

    Order OrderBook::getFirst() const
    {
        return this->m_book.begin()->second;
    }

    int OrderBook::size() const
    {
        return this->m_book.size();
    }

    bool OrderBook::empty() const
    {
        return this->m_book.empty();
    }

    Direction OrderBook::getDirection() const
    {
        return m_direction;
    }
} // namespace Order
