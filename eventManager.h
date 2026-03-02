#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <iostream>
#include <vector>
#include "event.h"
using namespace std;

class EventManager
{
private:
    static EventManager *instance;
    vector<Event *> events;
    static EventManager *intance;
    EventManager()
    {
    }

public:
    static EventManager *getEventmanagerInsance()
    {
        if(instance==nullptr)
        {
            instance = new EventManager();
        }
        return instance;
    }
    void addEvent(Event *event)
    {
        events.push_back(event);
    }

    Event *findEvent(int id)
    {
        for (int i = 0; i < events.size();i++)
        {
            if (id==i)
                return events[i];
        }
        return nullptr;
    }

    void showEvents()
    {
        int cnt = 0;
        for (auto event : events)
        {
            cout <<++cnt <<". " << "Event: " << event->name
                 << " | Location: " << event->address << endl;
        }
    }
};

EventManager* EventManager ::instance = nullptr;
#endif