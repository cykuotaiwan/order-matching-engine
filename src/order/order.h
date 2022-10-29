#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <stdint.h>
#include "direction.h"
#include "tradeMode.h"
#include "orderKey.h"

namespace Order
{
    class Order
    {
    private:
        std::uint64_t m_id{};
        std::uint64_t m_price{}; // cent
        Direction m_direction{};
        TradeMode m_mode{};
        std::uint64_t m_amount{};

    public:
        Order() = delete;
        Order(std::uint64_t id, std::uint64_t price, Direction direction,
              TradeMode mode, std::uint64_t amount);
        OrderKey getOrderKey() const;
        bool operator==(const Order &other) const;
    };

} // namespace Order

#endif