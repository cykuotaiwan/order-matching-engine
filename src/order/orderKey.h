#ifndef ORDER_KEY_H
#define ORDER_KEY_H

#include <map>
#include <stdint.h>
#include "direction.h"

namespace order
{
    class OrderKey
    {
    public:
        std::uint64_t m_id{};
        std::uint64_t m_price{}; // cent
        Direction m_direction{};

    public:
        OrderKey() = delete;
        OrderKey(std::uint64_t id, std::uint64_t price,
                 Direction direction);
    };

    struct orderKeyCmp
    {
        bool operator()(OrderKey &lhs, OrderKey &rhs)
        {
            bool result = false; // less
            if (lhs.m_direction == Direction::BUY)
            {
                if (lhs.m_price < rhs.m_price)
                    result = true;
                else
                    result = lhs.m_id < rhs.m_id;
            }
            else if (lhs.m_direction == Direction::SELL)
            {
                if (lhs.m_price > rhs.m_price)
                    result = true;
                else
                    result = lhs.m_id < rhs.m_id;
            }

            return result;
        }
    };
} // namespace order

#endif