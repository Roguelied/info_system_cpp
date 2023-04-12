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
    string GetName();
    void SetName(string Name);
    string GetWagonType();
    void SetWagonType(string WagonType);
    string GetPlace();
    void SetPlace(string Place);
    string GetDateAndTime();
    void SetDateAndTime(string DateAndTime);
    string GetRoute();
    void SetRoute(string Route);
    string GetPrice();
    void SetPrice(string Price);
    string GetID();
    void SetID(string ID);


    void SaveCustomer(Booking & Booking);

};


#endif //INFO_SYSTEM_CPP_DATABASE_H

