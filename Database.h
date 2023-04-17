#ifndef INFO_SYSTEM_CPP_DATABASE_H
#define INFO_SYSTEM_CPP_DATABASE_H

#include "Utility.h"

class Booking{
private:
    string Name;
    string WagonType;
    string Place;
    string DateAndTime;
    string Route;
    string Price;
    string ID;

public:
    void SaveCustomer(Booking & Booking);
    static void RegUser(string Login, string Password);
    static void FindUser(string Login, string Password);
};


#endif //INFO_SYSTEM_CPP_DATABASE_H