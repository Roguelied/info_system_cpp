#include "Data.h"

Data::Data(){
    initials.surname = "";
    initials.name = "";
    initials.patrinymic = "";

    carriage.id = "";
    carriage.place = "";
    carriage.price = "";
    carriage.place = "";

    date.day = 0;
    date.month = 0;
    date.year = 0;

    address.fr_w = "";
    address.to_w = "";
}

Data::Data(Initials initials_, Date date_, Address address_, Carriage carriage_) {
    initials.surname = initials_.surname;
    initials.name = initials_.name;
    initials.patrinymic = initials_.patrinymic;

    carriage.id = carriage_.id;
    carriage.place = carriage_.place;
    carriage.price = carriage_.price;
    carriage.place = carriage_.place;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date_.year;

    address.fr_w = address_.fr_w;
    address.to_w = address_.to_w;
}

Data::~Data() {
}

void Data::Print(){
    cout << "ФИО: " << initials.surname << " " << initials.name << " " << initials.patrinymic << endl;
    cout << "Дата: " << date.day << " " << date.month << " " << date.year << endl;
    cout << "Откуда: " << address.fr_w << " \nКуда: " << address.to_w << endl;
    cout << "Билет: " << carriage.type << " " << carriage.place << " " << carriage.id << " " << carriage.price << endl;
}

void Data::DataEntry(Initials initials_, Date date_, Address address_, Carriage carriage_) {
    initials.surname = initials_.surname;
    initials.name = initials_.name;
    initials.patrinymic = initials_.patrinymic;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date_.year;

    address.fr_w = address_.fr_w;
    address.to_w = address_.to_w;

    carriage.id = carriage_.id;
    carriage.place = carriage_.place;
    carriage.price = carriage_.price;
    carriage.place = carriage_.place;
}

Data& Data::operator=(Data d_o) {
    this->initials.surname = d_o.initials.surname;
    this->initials.name = d_o.initials.name;
    this->initials.patrinymic = d_o.initials.patrinymic;

    this->date.day = d_o.date.day;
    this->date.month = d_o.date.month;
    this->date.year = d_o.date.year;

    this->address.fr_w = d_o.address.fr_w;
    this->address.to_w = d_o.address.to_w;

    this->carriage.id = d_o.carriage.id;
    this->carriage.place = d_o.carriage.place;
    this->carriage.price = d_o.carriage.price;
    this->carriage.place = d_o.carriage.place;


    return *this;
}

