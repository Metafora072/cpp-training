#include <gtest/gtest.h>
#include "PriceCalculator.h"

TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    // test1
    PriceCal::PriceCalculator priceCalculator;

    double cash = priceCalculator.calculatePrice(PriceCal::PriceCalculator::DiscountType::CASH_NORMAL, 100);

    EXPECT_DOUBLE_EQ(100, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_takeoff_and_price_100)
{
    // test2
    PriceCal::PriceCalculator priceCalculator;

    double cash = priceCalculator.calculatePrice(PriceCal::PriceCalculator::DiscountType::CASH_TAKEOFF, 100);

    EXPECT_DOUBLE_EQ(90, cash);
}
