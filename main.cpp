#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"

string UserInterface::AdminPsswrd = "admin";
int _stateMenu;
void Menu(){
    cout << "Выберите действие: " << endl
         << "(0) Выход из программы" << endl
         << "(1) Ввод данных" << endl
         << "(2) Вывод данных" << endl
         << "(3) Изменение данных" << endl
         << "(4) Добавление данных" << endl
         << "(5) Удаление данных" << endl
         << "(6) Сортировка данных" << endl
         << "(7) Сохранение данных" << endl
         << "Ваш выбор: ";
    cin >> _stateMenu;
}

int main() {
    InitializeSettings();

    //Booking::RegUser("123123", "123123");
//    UserInterface::StartMenu();
//    UserInterface::LogMenu();
//    UserInterface::MainMenu();
    //wait;


}

