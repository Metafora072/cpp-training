#pragma once

#include <cmath>
enum class DiscountType
{
    CASH_NORMAL,
    CASH_PERCENTOFF_10,
    CASH_PERCENTOFF_20,
    CASH_PERCENTOFF_30,
    CASH_BACK,
};

namespace PriceCalc
{
    class PriceCalculator final
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;
    };

    class Normal final
    {
    public:
        double AcceptCash(const double money) const noexcept
        {
            return money;
        }
        virtual ~Normal();
    };
    class PercentOff final
    {
    private:
        double discountRate = 1;

    public:
        explicit PercentOff(double discountRate)
        {
            this->discountRate = discountRate;
        }
        virtual ~PercentOff();

        double AcceptCash(const double money) const noexcept
        {
            return money * discountRate;
        }
    };
    class CashBack final
    {
    private:
        double threshold = 100.0;
        double cashback = 20.0;

    public:
        explicit CashBack(double threshold, double cashback)
        {
            this->threshold = threshold;
            this->cashback = cashback;
        }
        virtual ~CashBack();
        double AcceptCash(const double money) const noexcept
        {
            return money - floor(money / threshold) * cashback;
        }
    };
}
