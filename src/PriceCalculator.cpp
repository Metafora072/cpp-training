#include "PriceCalculator.h"

#include <cmath>
#include <memory>
#include <unordered_map>
namespace PriceCalc
{

    // Discount接口成员函数实现
    // PriceCalculator::Discount::~Discount() {}

    // 静态成员初始化
    PriceCalculator::DiscountMapSingleton *PriceCalculator::DiscountMapSingleton::discountMapSingleton = NULL;

    // 构造函数
    PriceCalculator::DiscountMapSingleton::DiscountMapSingleton() {}

    std::unordered_map<DiscountType, std::function<double(double)>> &PriceCalculator::DiscountMapSingleton::getDiscountMap()
    {
        if (discountMapSingleton == NULL)
        {
            discountMapSingleton = new DiscountMapSingleton;
            //printf("update discountMap!");
            // discountMapSingleton->discountMap.emplace(DiscountType::CASH_NORMAL, std::make_unique<Normal>());
            // discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, std::make_unique<PercentOff>(0.9));
            // discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, std::make_unique<PercentOff>(0.8));
            // discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, std::make_unique<PercentOff>(0.7));
            // discountMapSingleton->discountMap.emplace(DiscountType::CASH_BACK, std::make_unique<CashBack>(100.0, 20.0));
            discountMapSingleton->discountMap.emplace(DiscountType::CASH_NORMAL, [](double money) { return Normal().AcceptCash(money); });
            discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_10, [](double money) { return PercentOff(0.9).AcceptCash(money); });
            discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_20, [](double money) { return PercentOff(0.8).AcceptCash(money); });
            discountMapSingleton->discountMap.emplace(DiscountType::CASH_PERCENTOFF_30, [](double money) { return PercentOff(0.7).AcceptCash(money); });
            discountMapSingleton->discountMap.emplace(DiscountType::CASH_BACK, [](double money) { return CashBack(100.0, 20.0).AcceptCash(money); });
        }
        return discountMapSingleton->discountMap;
    }

    // Normal成员函数实现
    double PriceCalculator::Normal::AcceptCash(const double money) const noexcept
    {
        return money;
    }
    PriceCalculator::Normal::~Normal() {}

    // PercentOff成员函数实现
    PriceCalculator::PercentOff::PercentOff(double rate) : discountRate(rate){};

    double PriceCalculator::PercentOff::AcceptCash(const double money) const noexcept
    {
        return money * discountRate;
    }
    PriceCalculator::PercentOff::~PercentOff(){};

    // CashBack成员函数实现
    PriceCalculator::CashBack::CashBack(double threshold, double cashback) : threshold(threshold), cashback(cashback) {}

    double PriceCalculator::CashBack::AcceptCash(const double money) const noexcept
    {
        return money - floor(money / threshold) * cashback;
    }

    PriceCalculator::CashBack::~CashBack(){};

    double PriceCalculator::AcceptCash(const DiscountType discountType, const double money) const noexcept
    {
        return PriceCalculator::DiscountMapSingleton::getDiscountMap()[discountType](money);
    }
} // namespace PriceCalc