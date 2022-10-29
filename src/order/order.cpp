#include "order.h"

namespace Order
{
    Order::Order(std::uint64_t id, std::uint64_t price, Direction direction,
                 TradeMode mode, std::uint64_t amount)
        : m_id(id), m_price(price), m_direction(direction),
          m_mode(mode), m_amount(amount)
    {
    }

    OrderKey Order::getOrderKey() const
    {
        OrderKey key(this->m_id, this->m_price, this->m_direction);
        return key;
    }
} // namespace Order
