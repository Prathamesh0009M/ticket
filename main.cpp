#include <bits/stdc++.h>
#include "user.h"
#include "seat.h"
#include "event.h"
#include "payment.h"
#include "discount.h"
#include "event.h"
#include "eventManager.h"
#include "Booking.h"

using namespace std;

int main()
{
    User *u1 = new User("prathamesh", "prathameshj776@gmail.com");

    Event *e = new Event("sports", "mumbai");
    Event *e2 = new Event("Alumni associations", "Delhi");
    Event *e3 = new Event("AI hackathon", "Chennai");

    EventManager *orchastor = EventManager::getEventmanagerInsance();
    orchastor->addEvent(e);
    orchastor->addEvent(e2);
    orchastor->addEvent(e3);

    orchastor->showEvents();

    cout << endl;
    int input;

    cout << "enter event number" << endl;
    cin >> input;
    Event *currentEvent = orchastor->findEvent(input);

    cout << "1. Base Seat" << endl;
    cout << "2. VIP Seat" << endl;
    cout << "3. Premium Seat" << endl;
    cout << "4. Bussiness Seat" << endl;
    cout << "select seat Type" << endl;
    int seattype;
    cin >> seattype;

    SeatType *seat;
    if (seattype == 1)
    {
        seat = new BaseSeat();
    }
    else if (seattype == 2)
    {
        seat = new VipSeat();
    }
    else if (seattype == 3)
    {
        seat = new Premium();
    }
    else if (seattype == 4)
    {
        seat = new business();
    }
    else
    {
        cout << "Invalid number process 0" << endl;
        return 0;
    }

    currentEvent->addSeatType(seat);

    DiscountStrategy *discount = new FestivalDiscount();
    Booking *B = new Booking(currentEvent, u1, seat, discount);

    B->showBookingDetails();
    cout << endl
         << endl;
    cout << "1. UPI" << endl;
    cout << "2. CARD" << endl;
    cout << "3. NET Banking" << endl;
    cout << "Select Payment Method: " << endl;

    int choice;
    cin >> choice;

    PaymentStrategy *payment;

    if (choice == 1)
    {
        payment = new UPI();
    }
    else if (choice == 2)
    {
        payment = new CARD();
    }
    else if (choice == 3)
    {
        payment = new NET_BANK();
    }
    else
    {
        cout << "Invalid Payment Option" << endl;
        return 0;
    }

    B->bookTicket(payment);

    cout << endl
         << endl
         << "____Booking Console____" << endl
         << endl;
    B->showBookingDetails();

    return 0;
}