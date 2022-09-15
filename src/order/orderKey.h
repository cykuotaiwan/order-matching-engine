#ifndef ORDER_KEY_H
#define ORDER_KEY_H

#include <map>
#include <stdint.h>

namespace order
{
    class OrderKey
    {
    private:
        uint64_t m_id{};
        uint64_t m_price{}; // cent
    public:
        OrderKey() = delete;
        OrderKey(uint64_t id, uint64_t price);

        bool operator>(const OrderKey key);
        bool operator>=(const OrderKey key);
        bool operator=(const OrderKey key);
        bool operator<(const OrderKey key);
        bool operator<=(const OrderKey key);
    };
} // namespace order

#endif