#include "orderKey.h"

namespace Order
{
    OrderKey::OrderKey(std::uint64_t id, std::uint64_t price, Direction direction)
        : m_id(id), m_price(price), m_direction(direction)
    {
    }

    bool OrderKey::operator>(const OrderKey &other) const
    {
        bool result = false;
        if (this->m_direction == Direction::BUY)
        {
            if (this->m_price > other.m_price)
                result = true;
            else
                result = this->m_id < other.m_id;
        }
        if (this->m_direction == Direction::SELL)
        {
            if (this->m_price < other.m_price)
                result = true;
            else
                result = this->m_id < other.m_id;
        }
        return result;
    }

    bool OrderKey::operator<(const OrderKey &other) const
    {
        bool result = false;
        if (this->m_direction == Direction::BUY)
        {
            if (this->m_price < other.m_price)
                result = true;
            else
                result = this->m_id < other.m_id;
        }
        if (this->m_direction == Direction::SELL)
        {
            if (this->m_price > other.m_price)
                result = true;
            else
                result = this->m_id < other.m_id;
        }
        return result;
    }

    bool OrderKey::operator==(const OrderKey &other) const
    {
        return this->m_id == other.m_id &&
               this->m_price == other.m_price &&
               this->m_direction == other.m_direction;
    }

    bool OrderKey::operator!=(const OrderKey &other) const
    {
        return !(*this == other);
    }

} // namespace Order
