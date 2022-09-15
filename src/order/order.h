#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <stdint.h>
#include "direction.h"
#include "tradeMode.h"
#include "../interface/serializable.h"

namespace order
{
    class Order : Serializable
    {
    private:
        uint64_t m_id{};
        uint64_t m_price{}; // cent
        Direction m_direction{};
        TradeMode m_mode{};
        uint64_t m_amount{};

    public:
        Order() = delete;
        Order(uint64_t id, uint64_t price, Direction direction,
              TradeMode mode, uint64_t amount);

        std::string toJson();
        void fromJson(std::string);
        std::string serialize();
        void deserialize(std::string str);
    };

} // namespace order

#endif