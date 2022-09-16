#ifndef TRADE_MODE_H
#define TRADE_MODE_H

namespace Order
{
    enum class TradeMode
    {
        ROD, // Rest Of Day
        IOC, // Immediate Or Cancel
        FOK  // Fill Or Kill
    };
} // namespace Order

#endif