#include "PriceCalculator.h"
#include <cmath>
namespace PriceCal {
    double PriceCalculator::calculatePrice(const DiscountType type,const double price) const noexcept {
        if(type == DiscountType::CASH_NORMAL) return price;
        if(type == DiscountType::CASH_TAKEOFF) return price * 0.9;
        if(type == DiscountType::CASH_DISCOUNT) return price - floor(price / 100) * 20;
        return 0;
    }
}