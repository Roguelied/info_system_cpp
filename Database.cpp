#include "Database.h"


string Booking::GetName() {
    return Name;
}
void Booking::SetName(string Name) {
    this -> Name = Name;
}
string Booking::GetWagonType() {
    return WagonType;
}
void Booking::SetWagonType(string WagonType) {
    this -> WagonType = WagonType;
}
string Booking::GetPlace() {
    return Place;
}
void Booking::SetPlace(string Place) {
    this -> Place = Place;
}
string Booking::GetDateAndTime() {
    return DateAndTime;
}
void Booking::SetDateAndTime(string DateAndTime) {
    this -> DateAndTime = DateAndTime;
}
string Booking::GetRoute() {
    return Route;
}
void Booking::SetRoute(string Route) {
    this -> Route = Route;
}
string Booking::GetPrice() {
    return Price;
}
void Booking::SetPrice(string Price) {
    this -> Price = Price;
}
string Booking::GetID() {
    return ID;
}
void Booking::SetID(string ID) {
    this -> ID = ID;
}

void Booking::SaveCustomer(Booking & Booking){ //запись в файл
    char ch[255]; string line;
    int count = 0;
    fstream out;
    out.open("../Database.txt", ios::out);
    if (out.is_open())
    {
        while(getline(out, line)){
            count++;
        }
        cout << "Введите ваше ФИО" << endl;
        cin >> Name;
        Booking.SetName(Name);
        cout << "Выберите тип вагон (купэ, вагон)" << endl;
        cin >> WagonType;
        Booking.SetWagonType(WagonType);
        cout << "Выберите место" << endl;
        cin >> Place;
        Booking.SetPlace(Place);
        cout << "Выберите время" << endl;
        cin >> DateAndTime;
        Booking.SetDateAndTime(DateAndTime);
        cout << "Выберите путь следования" << endl;
        cin >> Route;
        Booking.SetRoute(Route);
        cout << "Выберите стоимость" << endl;
        cin >> Price;
        Booking.SetPrice(Price);
        cout << "Введите ID брони" << endl;
        cin >> ID;
        Booking.SetID(ID);
        out << count+1 << " " << Booking.GetWagonType() << " " << Booking.GetDateAndTime() << " " << Booking.GetPlace() << " " << Booking.GetPrice() << " " << Booking.GetID() << " " << Booking.GetName() << endl;
    }
    out.close();
    system("pause");
}

void Booking::RegUser(string Login, string Password) {
    std::ifstream USERS("C:\\Users\\Roguelied\\CLionProjects\\info_system_cpp\\Users.txt");
    //USERS.open("C:\\Users\\Roguelied\\CLionProjects\\info_system_cpp\\Users.txt", fstream::in | fstream::out | fstream::ate); //doesnt work
    string str; getline(USERS, str);
    cout << str;


    USERS.close();
}

void Booking::FindUser(string Login, string Password) {

}

void LoadCustomer(){
    ifstream in("Database.txt");
    in.close();
}