#include "PercentDiscountCalculator.h"


namespace PriceCal {
    // 构造函数
    PercentDiscountCalculator::PercentDiscountCalculator(const double percentTakeOff) : percentTakeOff(percentTakeOff) {}

    // 计算打折后的价格
    double PercentDiscountCalculator::calculatePrice(const double price) const noexcept {
        return price * this->percentTakeOff;
    }
}