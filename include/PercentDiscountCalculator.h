#pragma once

#include "PriceCalculator.h"
namespace PriceCal {
    // 百分比打折
    class PercentDiscountCalculator : public PriceCalculator {
    private:
        const double percentTakeOff; //打几折，取值为 0 ~ 1
    public:
        PercentDiscountCalculator(const double percentTakeOff);
        double calculatePrice(const double price) const noexcept override;
    };

}