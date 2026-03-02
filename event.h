#ifndef EVENT_H
#define EVENT_H

#include <bits/stdc++.h>
#include "seat.h"
using namespace std;

class Event
{
public:
    static const int MAX_SEAT_TYPES = 10;
    string name;
    string address;
    SeatType *seatTypes[MAX_SEAT_TYPES];
    static int seatTypeCount;

    Event(string name, string address)
    {
        this->name = name;
        this->address = address;
        seatTypeCount = 0;
    }

    bool addSeatType(SeatType *seat)
    {
        if (seatTypeCount >= MAX_SEAT_TYPES)
        {
            cout << "Cannot add more seat types.\n";
            return false;
        }
        seatTypes[seatTypeCount++] = seat;
        return true;
    }

    // SeatType *getSeatType(string seatName)
    // {
    //     for (int i = 0; i < seatTypeCount; i++)
    //     {
    //         if (seatTypes[i]->name == seatName)
    //             return seatTypes[i];
    //     }
    //     return nullptr;
    // }


};

int Event::seatTypeCount = 0;

#endif