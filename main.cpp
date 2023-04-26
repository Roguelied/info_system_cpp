#include "Utility.h"
#include "Server.h"
#include "Client.h"
#include "Database.h"
#include "UserInterface.h"
#include "Functions_Database.h"

string UserInterface::AdminPsswrd = "admin";
vector <string> UserInterface::Date {"01.01","20.04","12.05","10.06","09.07","09.11","19.11"};

//int _stateMenu;
//void Menu(){
//    cout << "Выберите действие: " << endl
//         << "(0) Выход из программы" << endl
//         << "(1) Ввод данных" << endl
//         << "(2) Вывод данных" << endl
//         << "(3) Изменение данных" << endl
//         << "(4) Добавление данных" << endl
//         << "(5) Удаление данных" << endl
//         << "(6) Сортировка данных" << endl
//         << "(7) Сохранение данных" << endl
//         << "Ваш выбор: ";
//    cin >> _stateMenu;
//}

int main() {
    InitializeSettings();

    //Booking::RegUser("123123", "123123");
//    UserInterface::StartMenu();
//    UserInterface::LogMenu();
    UserInterface::MainMenu();
    wait;
}
    /*
    Booking Booking;
    Booking.SaveCustomer(Booking); */

//    Menu();
//    int _actions;
//    string fileName;
//
//    int _size = 0;
//    Data* d = new Data[_size];
//
//    while(_stateMenu != 0){
//        switch(_stateMenu){
//            case 1:
//                system("cls");
//                if (_size != 0)
//                    DataEntry(d, _size);
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 2:
//                system("cls");
//
//                if (_size != 0)
//                    Print(d, _size);
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 3:
//                system("cls");
//
//                if (_size != 0)
//                    DataChange(d, _size);
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 4:
//                system("cls");
//                if (_size != 0)
//                    AddData(d, _size);
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 5:
//                system("cls");
//                if (_size != 0)
//                    DeleteData(d, _size);
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 6:
//                system("cls");
//                if (_size != 0)
//                    SortingData(d, _size);
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            case 7:
//                system("cls");
//                if (_size != 0)
//                    SaveData(d, _size, "../Out.txt");
//                else
//                    cout << "Данные пусты!" << endl;
//                system("pause");
//                system("cls");
//                Menu();
//                break;
//            default:
//                cout << "Пункт меню введ не верно!" << endl;
//                system("cls");
//                Menu();
//                break;
//        }
//    }
//
//    system("cls");
//    cout << "Работа завершена!" << endl;
//    system("pause");
//
//}
//

