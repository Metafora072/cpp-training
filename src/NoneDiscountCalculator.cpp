#include "NoneDiscountCalculator.h"

namespace PriceCal
{
    double NoneDiscountCalculator::calculatePrice(const double price) const noexcept
    {
        // 无折扣直接返回原价
        return price;
    }
}