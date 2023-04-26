#include "Database.h"


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