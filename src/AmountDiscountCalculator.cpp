#include "AmountDiscountCalculator.h"

namespace PriceCal
{
    // 构造函数
    AmountDiscountCalculator::AmountDiscountCalculator(const double amountPrice, const double discountPrice) : amountPrice(amountPrice), discountPrice(discountPrice) {}

    // 计算满减后的价格
    double AmountDiscountCalculator::calculatePrice(const double price) const noexcept
    {
        return price - floor(price / amountPrice) * discountPrice;
    }
}