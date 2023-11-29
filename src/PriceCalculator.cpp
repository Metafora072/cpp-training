#include "PriceCalculator.h"

#include <cmath>
#include <memory>
#include <unordered_map>
namespace PriceCalc
{
    //Discount接口成员函数实现
    PriceCalculator::Discount::~Discount(){}

    //Normal接口成员函数实现
    double PriceCalculator::Normal::AcceptCash(const double money) const noexcept {
        return money;
    }
    PriceCalculator::Normal::~Normal(){}

    //PercentOff接口成员函数实现
    PriceCalculator::PercentOff::PercentOff(double rate) : discountRate(rate){};

    double PriceCalculator::PercentOff::AcceptCash(const double money) const noexcept{
        return money * discountRate;
    }
    PriceCalculator::PercentOff::~PercentOff(){};

    //CashBack接口成员函数实现
    PriceCalculator::CashBack::CashBack(double threshold, double cashback) : threshold(threshold), cashback(cashback) {}

    double PriceCalculator::CashBack::AcceptCash(const double money) const noexcept{
        return money - floor(money / threshold) * cashback;
    }

    PriceCalculator::CashBack::~CashBack(){};


    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        //double cash = 0.0;
        std::unordered_map<DiscountType, std::unique_ptr<Discount>> discountMap;
        discountMap.emplace(DiscountType::CASH_NORMAL, std::make_unique<Normal>());
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
        discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
        discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>(100.0, 20.0));
        return discountMap.find(discountType)->second->AcceptCash(money);
    }
}  // namespace PriceCalc