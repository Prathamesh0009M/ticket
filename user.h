#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std;

class User
{
public:
    string name;
    string email;

    User(string name, string email)
    {
        this->name = name;
        this->email = email;
    }

    ~User()
    {
        cout << "destroyed object" << endl;
    }
};


#endif