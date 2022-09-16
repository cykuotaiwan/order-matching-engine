#include "orderKey.h"

namespace order
{
    OrderKey::OrderKey(std::uint64_t id, std::uint64_t price, Direction direction)
        : m_id(id), m_price(price), m_direction(direction)
    {
    }
} // namespace order
