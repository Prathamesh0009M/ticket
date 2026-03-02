#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;

class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

class UPI : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Money paid via UPI: " << amount << endl;
    }
};

class CARD : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Money paid via CARD: " << amount << endl;
    }
};

class NET_BANK : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Processing Payment..." << endl;
        cout << "Money paid via NET Banking: " << amount << endl;
    }
};

#endif