#include "UserInterface.h"
#include "Utility.h"
//super govnocode by notFOUND



int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    TurnMagenta;
    gotoxy(0, 30);
    for (int i = 0; i < 211; i++) {
        gotoxy(0 + i, 0);
        cout << "▀";
        gotoxy(0 + i, 53);
        cout << "▄";
    }
    for (int i = 0; i < 54; i++) {
        gotoxy(0, i);
        cout << "█";
        gotoxy(210, i);
        cout << "█";
    }
    gotoxy(50, 10);
    cout
            << "WECLOME TO SUPER DUPER SYSTEM32 IN DATA BASE FOR ADMINS/CLIENTS/PEOPLE/GOLLUMS/WOMEN/DEMONS/GHOSTS/KURT OBAIN";
    TurnYellow;
    gotoxy(50, 27);
    cout << "LOG IN";
    TurnWhite;
    gotoxy(150, 27);
    cout << "EXIT";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "d") {
            TurnWhite;
            gotoxy(50, 27);
            cout << "LOG IN";
            TurnYellow;
            gotoxy(150, 27);
            cout << "EXIT";
            flag = 1;
        } else if (KeyCheck(Key) == "a") {
            TurnYellow;
            gotoxy(50, 27);
            cout << "LOG IN";
            TurnWhite;
            gotoxy(150, 27);
            cout << "EXIT";
            flag = 0;
        }
        if (flag == 0 and KeyCheck(Key) == "enter") {
            system("cls");
            return choice;
        } else if (flag == 1 and KeyCheck(Key) == "enter") {
            exit(0);
        }
    }
}


int UserInterface::LogMenu() {
    int flag = 0;
    int choice = 0;
    TurnMagenta;
    gotoxy(0, 30);
    for (int i = 0; i < 211; i++) {
        gotoxy(0 + i, 0);
        cout << "▀";
        gotoxy(0 + i, 53);
        cout << "▄";
    }
    for (int i = 0; i < 54; i++) {
        gotoxy(0, i);
        cout << "█";
        gotoxy(210, i);
        cout << "█";
    }
    gotoxy(99, 10);
    cout << "WHO ARE YOU?";
    TurnYellow;
    gotoxy(50, 27);
    cout << "USER";
    TurnWhite;
    gotoxy(150, 27);
    cout << "ADMIN";
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "d") {
            TurnWhite;
            gotoxy(50, 27);
            cout << "USER";
            TurnYellow;
            gotoxy(150, 27);
            cout << "ADMIN";
            flag = 1;
        } else if (KeyCheck(Key) == "a") {
            TurnYellow;
            gotoxy(50, 27);
            cout << "USER";
            TurnWhite;
            gotoxy(150, 27);
            cout << "ADMIN";
            flag = 0;
        }
        if (flag == 0 and KeyCheck(Key) == "enter") {
            system("cls");
            return choice;
        } else if (flag == 1 and KeyCheck(Key) == "e") {
            gotoxy(130, 29);
            TurnMagenta;
            for (int i = 0; i < 43; i++) {
                gotoxy(130 + i, 29);
                cout << "▀";
                gotoxy(130 + i, 43);
                cout << "▄";
            }
            for (int i = 29; i < 44; i++) {
                gotoxy(130, i);
                cout << "█";
                gotoxy(172, i);
                cout << "█";
            }
            gotoxy(145, 32);
            TurnLightRed;
            cout << "ENTER PASSWORD";
            gotoxy(134, 37);
            cout << "Password : ";
            string CorrectPassword = "11111";
            string EnteringPassword;

            for (int i = 0; i < 5; i++) {
                EnteringPassword[i] = getchar();
                //cout << "*";
                //cout << EnteringPassword[i];
//                if (KeyCheck(Key) == "enter") {

//                }
            }
            if (EnteringPassword == CorrectPassword) {

                cout << "              " <<EnteringPassword << "   "  << CorrectPassword;
                wait;
                exit(12);
            } else {
                cout << "              " << EnteringPassword << "   "  << CorrectPassword;
                wait;
                exit(2);
            }

        }

    }
}