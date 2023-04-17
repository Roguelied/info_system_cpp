#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
//01 хз купэ 10.99.40_19:33 Хабаровск 4000 ID86XJD8 nosov_mikhail_vitalievitxhdi

struct Carriage {
    string type, place, price, id;
};

struct Initials {
    string surname, name, patrinymic;
};

struct Date {
    int day, month, year;
};

struct Address {
    string fr_w, to_w;
};

class Data{

private:
    Carriage carriage;
    Initials initials;
    Date date;
    Address address;

public:
    Data();
    Data(Initials initials_, Date date_, Address address_, Carriage carriage_);
    ~Data();

    void Print();
    void DataEntry(Initials initials_, Date date_, Address address_, Carriage carriage_);
    Initials GetInitials(){ return initials; };
    Date GetDate(){ return date; };
    Address GetAddress(){ return address; };
    Carriage GetCarriage(){ return carriage; };

    Data& operator = (Data d_o);
};

#endif