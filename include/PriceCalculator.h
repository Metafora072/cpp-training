#pragma once
#include <unordered_map>
#include <memory>
#include <cmath>
#include <functional>
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
    class PriceCalculator
    {
    public:
        double AcceptCash(const DiscountType discountType, const double money) const noexcept;

    private:
        // // 折扣接口，三种折扣必须实现该接口的AcceptCash方法
        // class Discount
        // {
        // public:
        //     virtual double AcceptCash(const double money) const noexcept = 0;
        //     virtual ~Discount();

        // private:
        // };

        class DiscountMapSingleton
        {
        public:
            static std::unordered_map<DiscountType,std::function<double(double)>>& getDiscountMap();
        private:
            DiscountMapSingleton();
            std::unordered_map<DiscountType, std::function<double(double)>> discountMap;
            static DiscountMapSingleton *discountMapSingleton;
        };
        class Normal final
        {
        public:
            double AcceptCash(const double money) const noexcept;
            virtual ~Normal();
        };

        class PercentOff final 
        {
        private:
            double discountRate = 1;

        public:
            explicit PercentOff(double rate);
            virtual ~PercentOff();
            double AcceptCash(const double money) const noexcept;
        };
        class CashBack final
        {
            double threshold = 100.0;
            double cashback = 20.0;

        public:
            explicit CashBack(double threshold, double cashback);
            virtual ~CashBack();
            double AcceptCash(const double money) const noexcept;
        };
    };
} // namespace PriceCalc