#ifndef SEAT_H
#define SEAT_H
#include <bits/stdc++.h>
using namespace std;

class SeatType
{
public:
    int virtual getprice() = 0;
    virtual ~SeatType();
};

SeatType::~SeatType()
{
    cout << "base classe's seatType destroyed" << endl;
}

class BaseSeat : public SeatType
{
public:
    int getprice() override
    {
        cout << "SeatType = BASE" << endl;

        return 200;
    }
    ~BaseSeat()
    {
        cout << "Base SeatType Destroyed" << endl;
    }
};

class VipSeat : public SeatType
{
public:
    int getprice() override
    {
        cout << "SeatType = VIP" << endl;
        return 1000;
    }
    ~VipSeat()
    {
        cout << "Base VipSeat Destroyed" << endl;
    }
};

class Premium : public SeatType
{
public:
    int getprice() override
    {
        cout << "SeatType = premium" << endl;

        return 800;
    }
    ~Premium()
    {
        cout << " Premium Destroyed" << endl;
    }
};

class business : public SeatType
{
public:
    int getprice() override
    {
        cout << "SeatType = Business" << endl;
        return 1500;
    }
    ~business()
    {
        cout << "business Destroyed" << endl;
    }
};

#endif