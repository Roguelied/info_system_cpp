//super govnocode by notFOUND
#include "UserInterface.h"
#include "Utility.h"


bool UserInterface::in_range(char *buff, const char *max) {
    int lb = strlen(buff), lm = strlen(max);
    return (lb != lm) ? (lb < lm) : strcmp(max, buff) >= 0;
}

void UserInterface::DrawFrame(int x1, int y1, int x2, int y2) {
    int i = x1;
    int j = y1;
    for (i; i < x2 + 1; i++) {
        gotoxy(i, y1);
        cout << "▀";
        gotoxy(i, y2);
        cout << "▄";
    }
    for (j; j < y2 + 1; j++) {
        gotoxy(x1, j);
        cout << "█";
        gotoxy(x2, j);
        cout << "█";
    }
}

int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    TurnAqua;
    gotoxy(0, 30);
    DrawFrame(0, 0, 210, 53);
    gotoxy(50, 10);
    cout
            << "WECLOME TO SUPER DUPER SYSTEM32 IN DATA BASE FOR ADMINS/CLIENTS/PEOPLE/GOLLUMS/WOMEN/DEMONS/GHOSTS/KURT OBAIN";
    TurnBackGreen;
    gotoxy(50, 27);
    cout << "LOG IN";
    TurnWhite;
    gotoxy(150, 27);
    cout << "EXIT";
    gotoxy(56, 27);
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
            gotoxy(56, 27);
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

int UserInterface::ADMINInputPassword(char *buffer) {
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
        int flagg = 0;
        gotoxy(145, 39);
        TurnWhite;
        cout << "log in to : ";
        TurnBackGreen;
        cout << "admin";
        TurnWhite;
        gotoxy(145, 41);
        cout << "log in to : ";
        TurnWhite;
        cout << "server";
        gotoxy(162, 39);
        for (;;) {
            int Key = _getch();
            if (KeyCheck(Key) == "s") {
                gotoxy(157, 39);
                TurnWhite;
                cout << "admin";
                gotoxy(157, 41);
                TurnBackGreen;
                cout << "server";
                flagg = 1;
            } else if (KeyCheck(Key) == "w") {
                gotoxy(157, 39);
                TurnBackGreen;
                cout << "admin";
                gotoxy(157, 41);
                TurnWhite;
                cout << "server";
                gotoxy(162, 39);
                flagg = 0;
            }
            if (flagg == 0 and KeyCheck(Key) == "enter") {
                system("cls");
                return 5;                                                               //admin-5
            } else if (flagg == 1 and KeyCheck(Key) == "enter") {
                system("cls");
                return 6;                                                               //server-6
            } else if (KeyCheck(Key) == "esc") { //esc
                for (int i = 130; i < 173; i++) {
                    for (int j = 29; j < 44; j++) {
                        gotoxy(i, j);
                        cout << " ";
                    }
                }
                return 12;                                                              //exit frame -12
            }
        }
    } else {
        gotoxy(145, 34);
        TurnLightRed;
        cout << "WRONG PASSWORD";
        TurnWhite;
        sleep_for(milliseconds(500));
        gotoxy(145, 34);
        cout << "              ";
        gotoxy(145, 37);
        cout << "           ";
        gotoxy(145, 37);
        return 2;
    }
}

void UserInterface::clearWINDOW(int x1, int x2, int y1, int y2) {
    int i = x1;
    int j = y1;
    for (i; i < x2 + 1; i++) {
        for (j; j < y2 + 1; j++) {
            gotoxy(i, j);
            cout << " ";
        }
    }
}

int UserInterface::USERchoise() {
    TurnAqua;
    DrawFrame(42, 29, 61, 35);
    TurnBackGreen;
    gotoxy(48, 31);
    cout << "LOGGIN";
    gotoxy(48, 33);
    TurnWhite;
    cout << "REGISTER";
    gotoxy(54, 31);
    int flag_LR = 0;
    for (;;) {
        int key = _getch();
        if (KeyCheck(key) == "s") {
            TurnWhite;
            gotoxy(48, 31);
            cout << "LOGGIN";
            gotoxy(48, 33);
            TurnBackGreen;
            cout << "REGISTER";
            flag_LR = 1;
        } else if (KeyCheck(key) == "w") {
            TurnBackGreen;
            gotoxy(48, 31);
            cout << "LOGGIN";
            gotoxy(48, 33);
            TurnWhite;
            cout << "REGISTER";
            gotoxy(54, 31);
            flag_LR = 0;
        }
        if(flag_LR==0 and KeyCheck(key)=="enter"){
            for(;;)
            clearWINDOW(42,61,29,35);
        }
    }
}

int UserInterface::USERInputReg(char *Loggin, char *Password) {
    char *login = Loggin;
    char *pass = Password;
    unsigned char lsymbol;
    gotoxy(145, 37);
    do {
        lsymbol = (unsigned char) getch();

        if (lsymbol == VK_BKSPC && login > Loggin) {
            *--login = 0;
            putch(VK_BKSPC);
            putch(VK_SPACE);
            putch(VK_BKSPC);
            continue;
        }
        if (lsymbol == VK_ESCAPE) {
            clearWINDOW(130, 172, 29, 43);                                             //esc
            return 3;
        }
        if (!lsymbol) {
            getch();
            continue;
        }
        if (lsymbol > VK_SPACE - 1 and (in_range(Loggin, MAX_PASS))) {
            *login++ = lsymbol;
            putch('*');
        } else { *login = 0; }
    } while (lsymbol != VK_RETURN);
    *login = 0;
    if (strcmp(AdminPassword, Loggin) == 0) {
        int flagg = 0;
        gotoxy(145, 39);
        TurnWhite;
        cout << "log in to : ";
        TurnBackGreen;
        cout << "admin";
        TurnWhite;
        gotoxy(145, 41);
        cout << "log in to : ";
        TurnWhite;
        cout << "server";
        gotoxy(162, 39);
    }
}

int UserInterface::LogMenu() {
    int flag = 0;
    int choice = 0;
    TurnAqua;
    gotoxy(0, 30);
    DrawFrame(0, 0, 210, 53);
    gotoxy(99, 10);
    cout << "WHO ARE YOU?";
    TurnBackGreen;
    gotoxy(50, 27);
    cout << "USER";
    TurnWhite;
    gotoxy(150, 27);
    cout << "ADMIN";
    gotoxy(54, 27);
    int flag2 = 0;
    while (true) {
        if (flag2 == 1) { break; }
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
            gotoxy(54, 27);
            flag = 0;
        }
/* ====================================================================================USER================================================================================
========================================================================================================================================================================*/
        if (flag == 0 and KeyCheck(Key) == "enter") {
            USERchoise();
        }






            //DrawFrame(10, 29, 100, 49);

/*====================================================================================ADMIN================================================================================
========================================================================================================================================================================*/

        else if (flag == 1 and KeyCheck(Key) == "enter") {
            char passwd[128] = {0};
            TurnAqua;
            DrawFrame(130, 29, 172, 43);
            gotoxy(145, 32);
            TurnWhite;
            cout << "ENTER PASSWORD";
            gotoxy(134, 37);
            cout << "Password : ";
            for (;;) {
                int res = ADMINInputPassword(passwd);
                if (res == 5 or res == 6) {
                    flag2 = 1;
                    break;
                }
                if (res == 2) {
                    continue;
                }
                if (res == 3 or res == 12) {
                    gotoxy(155, 27);
                    break;
                }
            }
        }
    }
}




