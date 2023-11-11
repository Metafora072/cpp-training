#pragma once

namespace PriceCal
{
    class PriceCalculator
    {

    public:
        enum class DiscountType
        {
            CASH_NORMAL,
            CASH_TAKEOFF,
            CASH_DISCOUNT
        };
        double calculatePrice(const DiscountType type, const double price) const noexcept;
    };
}
