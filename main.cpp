#include "Utility.h"
#include "Server.h"
#include "Client.h"
#include "Data.h"
#include "UserInterface.h"
#include <iostream>
#include <windows.h>
#include "Functions_Database.h"

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
    UserInterface A;
    //A.StartMenu();
    //A.LogMenu();
    //wait;
    
   /* int asnw;
    cout << "1 for client else for server" << endl;
    cin >> asnw;
    if (asnw == 1) {
        client_init();
        wait;
    } else { server_init(); wait;}*/

    Menu();
    int _actions;
    string fileName;

    int _size = 0;
    Data* d = new Data[_size];

    while(_stateMenu != 0){
        switch(_stateMenu){
            case 1:
                system("cls");
                DataEntry(d, _size);
                system("pause");
                system("cls");
                Menu();
                break;
            case 2:
                system("cls");

                if (_size != 0)
                    Print(d, _size);
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            case 3:
                system("cls");

                if (_size != 0)
                    DataChange(d, _size);
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            case 4:
                system("cls");
                if (_size != 0)
                    AddData(d, _size);
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            case 5:
                system("cls");
                if (_size != 0)
                    DeleteData(d, _size);
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            case 6:
                system("cls");
                if (_size != 0)
                    SortingData(d, _size);
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            case 7:
                system("cls");
                if (_size != 0)
                    SaveData(d, _size, "../Database.txt");
                else
                    cout << "Данные пусты!" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            default:
                cout << "Пункт меню введ не верно!" << endl;
                system("cls");
                Menu();
                break;
        }
    }

    system("cls");
    cout << "Работа завершена!" << endl;
    system("pause");

}


//    int asnw;
//    cout << "1 for client else for server" << endl;
//    cin >> asnw;
//    if (asnw == 1) {
//        client_init();
//        wait;
//    } else { server_init(); wait;}}
