#ifndef ORDER_KEY_H
#define ORDER_KEY_H

#include <map>
#include <stdint.h>
#include "direction.h"

namespace Order
{
    class OrderKey
    {
    private:
        std::uint64_t m_id{};
        std::uint64_t m_price{}; // cent
        Direction m_direction{};

    public:
        OrderKey() = delete;
        OrderKey(std::uint64_t id, std::uint64_t price,
                 Direction direction);
        bool operator>(const OrderKey &other) const;
        bool operator<(const OrderKey &other) const;
        bool operator==(const OrderKey &other) const;
        bool operator!=(const OrderKey &other) const;
    };

    struct orderKeyCmp
    {
        bool operator()(const OrderKey &lhs, const OrderKey &rhs)
        {
            return lhs < rhs;
        }
    };
} // namespace Order

#endif