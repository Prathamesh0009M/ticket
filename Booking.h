#ifndef BOOKING_H
#define BOOKING_H

#include <bits/stdc++.h>
#include "user.h"
#include "event.h"
#include "discount.h"
#include "seat.h"
#include "payment.h"

using namespace std;

enum BookingStatus
{
    PENDING,
    CONFIRMED,
    CANCELLED
};

class Booking
{
public:
    static int idcounter;

    int bookingid;
    Event *event;
    User *user;
    SeatType *seatype;
    int totalAmount;
    BookingStatus status;
    DiscountStrategy *discount;
    PaymentStrategy *payment;

    Booking(Event *event, User *user, SeatType *seattype, DiscountStrategy *discount)
    {
        this->bookingid = ++idcounter;
        this->discount = discount;
        this->event = event;
        this->seatype = seattype;
        this->user = user;
        this->status = PENDING;
        calculateTotal();
    }

    int calculateTotal()
    {
        totalAmount = seatype->getprice();
        totalAmount = discount->applyDiscount(totalAmount);
    }

    void showBookingDetails()
    {
        cout << "Booking ID: " << bookingid << endl;
        cout << "User: " << user->name << endl;
        cout << "After Applied Current Discount";
        cout << " Total Amount: " << totalAmount << endl;
        if (status == PENDING)
        {
            cout << "Status: Pending" << endl;
        }
        if (status == CONFIRMED)
        {
            cout << "Status: CONFIRMED" << endl;
            
        }
        int d = seatype->getprice();
    }

    void bookTicket(PaymentStrategy *payment)
    {

        this->payment = payment;
        payment->pay(totalAmount);
        status = CONFIRMED;
    }

    ~Booking()
    {
        cout << "Booking object deleted" << endl;
    }
};

int Booking::idcounter = 0;

#endif