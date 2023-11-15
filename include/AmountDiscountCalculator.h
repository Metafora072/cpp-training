#pragma once

#include "PriceCalculator.h"
#include <cmath>
namespace PriceCal {
    // 满减打折
    class AmountDiscountCalculator : public PriceCalculator {
    private :
        const double amountPrice; //满多少金额方可减免
        const double discountPrice; //减免多少价格 
    public:
        AmountDiscountCalculator(const double AmountPrice,const double DiscountPrice);
        double calculatePrice(const double price) const noexcept override;
    };

}

