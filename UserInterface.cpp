//super govnocode by notFOUND
#include "UserInterface.h"
#include "Utility.h"


void UserInterface::DrawFrame(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2 + 1; i++) {
        gotoxy(i, y1); cout << "▀";
        gotoxy(i, y2); cout << "▄";
    }
    for (int j = y1; j < y2 + 1; j++) {
        gotoxy(x1, j); cout << "█";
        gotoxy(x2, j); cout << "█";
    }
}

void UserInterface::Clear(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2 + 1; i++) {
        for (int j = y1; j < y2 + 1; j++) {
            gotoxy(i, j); cout << " ";
        }
    }
}

string UserInterface::Input(int x, int y, const char *length, char replace) {

    char buffer[128] = {0};
    char *ptr = buffer;
    unsigned char symbol;

    gotoxy(x, y); //where field is

    do {
        symbol = (unsigned char) getch();

        if (symbol == VK_BKSPC && ptr > buffer) {
            *--ptr = 0;
            putch(VK_BKSPC);
            putch(VK_SPACE);
            putch(VK_BKSPC);
            continue;
        }

        if (symbol == VK_ESCAPE) { return "-1"; }

        if (!symbol) {
            getch();
            continue;
        }

        if (symbol > VK_SPACE - 1 and (in_range(buffer, length))) {
            *ptr++ = symbol;
            if (replace == ' ') { putch(symbol); }
            else { putch(replace); }
        }
    } while (symbol != VK_RETURN);
    *ptr = 0;
    return buffer;
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


int UserInterface::ADMINchoice() {
    string res = Input(145, 37, MAX_PASS, '*');
    if (res == "-1") {return -1;}
    if (res != ADMINpsswrd) {
        TurnLightRed; gotoxy(145, 34); cout << "WRONG PASSWORD";
        sleep_for(milliseconds(1200));
        TurnWhite; gotoxy(145, 34); cout << "              ";
        gotoxy(145, 37); cout << "           "; gotoxy(145, 37);
        return 0;

    } else if(res==ADMINpsswrd) {

        int flagg = 0;
        TurnWhite; gotoxy(145, 39); cout << "log in to : ";
        TurnBackGreen; cout << "admin";
        TurnWhite; gotoxy(145, 41); cout << "log in to : ";
        TurnWhite; cout << "server"; gotoxy(162, 39);

        for(;;) {
            int Key = _getch();
            if (KeyCheck(Key) == "s") {

                TurnWhite; gotoxy(157, 39); cout << "admin";
                TurnBackGreen; gotoxy(157, 41); cout << "server";
                flagg = 1;

            } else if (KeyCheck(Key) == "w") {

                TurnBackGreen; gotoxy(157, 39); cout << "admin";
                TurnWhite; gotoxy(157, 41); cout << "server"; gotoxy(162, 39);
                flagg = 0;
            }
            if (flagg == 0 and KeyCheck(Key) == "enter") { //admin
                return 1;
            } else if (flagg == 1 and KeyCheck(Key)=="enter") { //server
                return 2;
            } else if (KeyCheck(Key) == "esc") {
                return -1;
            }
        }
    }
    return 0;
}

int UserInterface::LogMenu() {
    int isAdmin = 0;
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

    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "d") {

            TurnWhite;
            gotoxy(50, 27);
            cout << "USER";
            TurnBackGreen;
            gotoxy(150, 27);
            cout << "ADMIN";
            isAdmin = 1;

        } else if (KeyCheck(Key) == "a") {

            TurnBackGreen;
            gotoxy(50, 27);
            cout << "USER";
            TurnWhite;
            gotoxy(150, 27);
            cout << "ADMIN";
            gotoxy(54, 27);
            isAdmin = 0;

        } else if (isAdmin and KeyCheck(Key) == "enter") {
            TurnAqua;
            DrawFrame(130, 29, 172, 43);
            TurnWhite;
            gotoxy(145, 32);
            cout << "ENTER PASSWORD";
            gotoxy(134, 37);
            cout << "Password : ";
            for (;;) {
                int res = ADMINchoice();
                if (res == -1) {
                    TurnWhite;
                    Clear(130, 29, 172, 43);
                    gotoxy(155, 27);
                    break;
                } else if (res == 0) {
                    continue;
                } else if (res == 1) {
                    system("cls");
                    return -2;
                } else if (res == 2) {
                    system("cls");
                    return -1;
                }
            }
        }

        else if (!isAdmin and KeyCheck(Key) == "enter") {
            int flaglog = 1;
            TurnAqua;
            DrawFrame(42, 29, 61, 35);
            TurnBackGreen;
            gotoxy(48, 31);
            cout << "LOGGIN";
            TurnWhite;
            gotoxy(48, 33);
            cout << "REGISTER";
            gotoxy(54, 31);
            for (;;) {
                int key = _getch();
                if (KeyCheck(key) == "s") {
                    TurnWhite;
                    gotoxy(48, 31);
                    cout << "LOGGIN";
                    gotoxy(48, 33);
                    TurnBackGreen;
                    cout << "REGISTER";
                    TurnWhite;
                    flaglog = 0;
                } else if (KeyCheck(key) == "w") {
                    TurnBackGreen;
                    gotoxy(48, 31);
                    cout << "LOGGIN";
                    gotoxy(48, 33);
                    TurnWhite;
                    cout << "REGISTER";
                    gotoxy(54, 31);
                    flaglog = 1;
                    //login
                }
                else if(KeyCheck(key)=="esc"){
                    Clear(42, 29, 61, 35);
                    gotoxy(54, 27);
                    break;
                }
                else if (flaglog and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    TurnAqua;
                    DrawFrame(10, 29, 100, 39);
                    TurnWhite;
                    gotoxy(52, 30);
                    cout << "LOGIN";
                    gotoxy(15, 32);
                    cout << "Name : ";
                    gotoxy(15, 36);
                    cout << "Password : ";
                    string log = Input(22, 32, MAX_LOGIN, ' ');
                    if (log == "-1") {
                        Clear(10, 29, 100, 39);
                        gotoxy(54, 27);
                        break;
                    }
                    //else{system("cls");}
                    string pas = Input(26, 36, MAX_PASS, '*');
                    if (pas == "-1") {
                        Clear(10, 29, 100, 39);
                        gotoxy(54, 27);
                        break;
                    } else{system("cls");}
                } else if (!flaglog and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    TurnAqua;
                    DrawFrame(10, 29, 100, 43);
                    TurnWhite;
                    gotoxy(50, 30);
                    cout << "REGISTRATION";
                    gotoxy(13, 33);
                    cout << "Enter your name : ";
                    gotoxy(13, 36);
                    cout << "Create password : ";
                    gotoxy(13, 39);
                    cout << "Repeat password : ";
                    for(;;){
                    string Newlog = Input(31, 33, MAX_LOGIN, ' ');
                    if (Newlog == "-1") {
                        Clear(10, 29, 100, 43);
                        gotoxy(54, 27);
                        break;
                    }//else{system("cls");}
                    string Newpas = Input(31, 36, MAX_LOGIN, '*');
                    if (Newpas == "-1") {
                        Clear(10, 29, 100, 43);
                        gotoxy(54, 27);
                        break;
                    }
                    string Repitnewpas = Input(31, 39, MAX_LOGIN, '*');
                    if (Repitnewpas == "-1") {
                        Clear(10, 29, 100, 43);
                        gotoxy(54, 27);
                        break;
                    }
                    if(Newpas!=Repitnewpas){
                        TurnLightRed;gotoxy(50,41);cout << "PASSWORDS MISMATCH";
                        sleep_for(milliseconds(1200));
                        TurnWhite;gotoxy(50,41);cout<<"                  ";
                        gotoxy(31, 39);cout<<"                 ";
                        gotoxy(31, 36);cout<<"                 ";
                        gotoxy(31,33);cout<<"                  ";
                        continue;
                                }
                            }
                    break;
                }
            }
        }
    }
}


