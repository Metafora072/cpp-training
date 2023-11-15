#pragma once

namespace PriceCal
{
    // 价格计算的接口，里面包含折扣类型以及价格计算的纯虚函数
    class PriceCalculator
    {

    public:
        /*enum class DiscountType
        {
            CASH_NORMAL,
            CASH_TAKEOFF,
            CASH_DISCOUNT
        };*/
        virtual double calculatePrice(const double price) const noexcept = 0;
        virtual ~PriceCalculator() = default;
    };
}
