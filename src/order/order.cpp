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

    Direction Order::getDirection() const
    {
        return m_direction;
    }

    bool Order::operator==(const Order &other) const
    {
        bool result = true;
        result &= m_id == other.m_id;
        result &= m_price == other.m_price;
        result &= m_direction == other.m_direction;
        result &= m_mode == other.m_mode;
        result &= m_amount == other.m_amount;

        return result;
    }

} // namespace Order
