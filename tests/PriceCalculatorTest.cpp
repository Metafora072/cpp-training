#include <gtest/gtest.h>
#include "PriceCalculator.h"
#include "NoneDiscountCalculator.h"
#include "PercentDiscountCalculator.h"
#include "AmountDiscountCalculator.h"

using namespace PriceCal;

TEST(PriceCalculator, should_return_100_when_given_cash_normal_and_price_100)
{
    // given
    PriceCalculator *noneDiscountCalculator = new NoneDiscountCalculator(); // 原价卖出

    // when
    double cash = noneDiscountCalculator->calculatePrice(100);

    // then
    EXPECT_DOUBLE_EQ(100, cash);
}


TEST(PriceCalculator, should_return_90_when_given_cash_takeoff_and_price_100)
{
    // given
    PriceCalculator *percentDiscountCalculator = new PercentDiscountCalculator(0.9); // 打九折

    // when
    double cash = percentDiscountCalculator->calculatePrice(100);

    // then
    EXPECT_DOUBLE_EQ(90, cash);
}


TEST(PriceCalculator, should_return_80_when_given_cash_discount_and_price_100)
{
    // given
    PriceCalculator *amountDiscountCalculator = new AmountDiscountCalculator(100, 20); // 满减，满100减20

    // when
    double cash = amountDiscountCalculator->calculatePrice(100);

    // then
    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, should_return_80_when_given_cash_discount_and_price_80)
{
    // given
    PriceCalculator *amountDiscountCalculator = new AmountDiscountCalculator(100, 20); // 满减，满100减20

    // when
    double cash = amountDiscountCalculator->calculatePrice(80);

    // then
    EXPECT_DOUBLE_EQ(80, cash);
}

TEST(PriceCalculator, should_return_160_when_given_cash_discount_and_price_200)
{
    // given
    PriceCalculator *amountDiscountCalculator = new AmountDiscountCalculator(100, 20); // 满减，满100减20

    // when
    double cash = amountDiscountCalculator->calculatePrice(200);

    // then
    EXPECT_DOUBLE_EQ(160, cash);
}


TEST(PriceCalculator, should_return_80_when_given_cash_takeoff_and_price_100)
{
    // given
    PriceCalculator *percentDiscountCalculator = new PercentDiscountCalculator(0.8);  // 打八折

    // when
    double cash = percentDiscountCalculator->calculatePrice(100);

    // then
    EXPECT_DOUBLE_EQ(80, cash);
}