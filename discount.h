#ifndef DISCOUNT_H
#define DISCOUNT_H

class DiscountStrategy
{
public:
    virtual int applyDiscount(int price) = 0;
    virtual ~DiscountStrategy() {};
};

class EarlyBird : public DiscountStrategy
{
public:
    int applyDiscount(int price) override
    {
        return price * 0.8;
    }
};

class FestivalDiscount : public DiscountStrategy
{
public:
    int applyDiscount(int price) override
    {
        return price * 0.85; 
    }
};

class CouponDiscount : public DiscountStrategy
{
public:
    int couponAmount=100;

    CouponDiscount(int amount) : couponAmount(amount) {}

    int applyDiscount(int price) override
    {
        return price - couponAmount;
    }
};

#endif