#pragma once

#include "PriceCalculator.h"
namespace PriceCal {
    // 无折扣
    class NoneDiscountCalculator : public PriceCalculator {
    public:
        double calculatePrice(const double price) const noexcept override;
        virtual ~NoneDiscountCalculator() = default;
    };

}