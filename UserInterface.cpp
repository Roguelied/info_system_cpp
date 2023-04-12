//super govnocode by notFOUND
#include "UserInterface.h"
#include "Utility.h"


bool UserInterface::in_range(char *buff, const char *max)//от - до
{
    int lb = strlen(buff), lm = strlen(max);
    return (lb != lm) ? (lb < lm) : strcmp(max, buff) >= 0;
}


int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    TurnAqua;
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
    TurnBackGreen;
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
            TurnBackGreen;
            gotoxy(150, 27);
            cout << "EXIT";
            flag = 1;
        } else if (KeyCheck(Key) == "a") {
            TurnBackGreen;
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

int UserInterface::InputPassword(char *buffer) {
    char *ptr = buffer;
    unsigned char symbol;

    gotoxy(145, 37);


    do {
        symbol = (unsigned char) getch();

        if (symbol == VK_BKSPC && ptr > buffer) {
            *--ptr = 0;
            putch(VK_BKSPC);
            putch(VK_SPACE);
            putch(VK_BKSPC);
            continue;
        }
        if (symbol == VK_ESCAPE) { //esc
            for (int i = 130; i < 173; i++) {
                for (int j = 29; j < 44; j++) {
                    gotoxy(i, j);
                    cout << " ";
                }
            }
            return 3;
        }

        if (!symbol) {
            getch();
            continue;
        }
        if (symbol > VK_SPACE - 1 and (in_range(buffer, MAX_PASS))) {
            *ptr++ = symbol;
            putch('*');
        } else { *ptr = 0; }
    } while (symbol != VK_RETURN);
    *ptr = 0;


    if (strcmp(AdminPassword, buffer) == 0) {
        int flagg=0;
        gotoxy(145,39);
        TurnLightRed;
        cout<<"log in to : ";
        TurnBackGreen;
        cout<<"admin";
        TurnLightRed;
        gotoxy(145,41);
        cout<<"log in to : ";
        TurnWhite;
        cout<<"server";
        for(;;){
            int Key = _getch();
            if(KeyCheck(Key)=="s"){
                gotoxy(157,39);
                TurnWhite;
                cout<<"admin";
                gotoxy(157,41);
                TurnBackGreen;
                cout<<"server";
                flagg=1;
            } else if (KeyCheck(Key)=="w"){
                gotoxy(157,39);
                TurnBackGreen;
                cout<<"admin";
                gotoxy(157,41);
                TurnWhite;
                cout<<"server";
                flagg=0;
            }if(flagg==0 and KeyCheck(Key)=="enter"){
                system("cls");
                return 5;                                                               //admin-5
            } else if(flagg==1 and KeyCheck(Key)=="enter"){
                system("cls");
                return 6;                                                               //server-6
            }
        }






    } else {
        gotoxy(145, 34);
        cout << "WRONG PASSWORD";
        sleep_for(milliseconds(500));
        gotoxy(145, 34);
        cout << "              ";
        gotoxy(145, 37);
        cout << "           ";
        gotoxy(145, 37);
        return 2;
    }
}

int UserInterface::LogMenu() {
    int flag = 0;
    int choice = 0;
    TurnAqua;
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
    TurnBackGreen;
    gotoxy(50, 27);
    cout << "USER";
    TurnWhite;
    gotoxy(150, 27);
    cout << "ADMIN";

    int flag2 = 0;
    while (true) {
        if (flag2 == 1) {break;}
        int Key = _getch();
        if (KeyCheck(Key) == "d") {
            TurnWhite;
            gotoxy(50, 27);
            cout << "USER";
            TurnBackGreen;
            gotoxy(150, 27);
            cout << "ADMIN";
            flag = 1;
        } else if (KeyCheck(Key) == "a") {
            TurnBackGreen;
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

        } else if (flag == 1 and KeyCheck(Key) == "enter") {
            char passwd[128] = {0};
            //gotoxy(130, 29);
            TurnAqua;
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





            for (;;) {
                int res = InputPassword(passwd);
                if (res == 5 or res==6) {
                    flag2 = 1;
                    break;
                }
                if (res == 2) {
                    continue;
                }
                if (res == 3) {
                    break;
                }
            }
        }
    }

}





