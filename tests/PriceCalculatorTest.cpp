#include <gtest/gtest.h>
#include "PriceCalculator.h"

using namespace PriceCal;

TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.calculatePrice(PriceCalculator::DiscountType::CASH_NORMAL, 100);

    // then
    EXPECT_DOUBLE_EQ(100, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_takeoff_and_price_100)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.calculatePrice(PriceCalculator::DiscountType::CASH_TAKEOFF, 100);

    // then
    EXPECT_DOUBLE_EQ(90, cash);
}


TEST(PriceCalculator, should_return_80_when_given_cash_discount_and_price_100)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.calculatePrice(PriceCalculator::DiscountType::CASH_DISCOUNT, 100);

    // then
    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, should_return_90_when_given_cash_discount_and_price_90)
{
    // given
    PriceCalculator priceCalculator;

    // when
    double cash = priceCalculator.calculatePrice(PriceCalculator::DiscountType::CASH_DISCOUNT, 90);

    // then
    EXPECT_DOUBLE_EQ(90, cash);
}
