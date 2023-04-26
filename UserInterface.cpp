//super govnocode by notFOUND
#include "UserInterface.h"
#include "Utility.h"

string UserInterface::AdminPsswrd = "admin";
string UserInterface::AdminLoggin = "admin";
vector<string> UserInterface::Date{"01.01", "20.04", "12.05", "10.06", "09.07", "09.11", "19.11"};

/*============================================TOOL FUNCTIONS==============================================================
========================================================================================================================*/

void UserInterface::DrawFrame(int x1, int y1, int x2, int y2) {
    TurnAqua;
    for (int i = x1; i < x2 + 1; i++) {
        gotoxy(i, y1);
        cout << "▀";
        gotoxy(i, y2);
        cout << "▄";
    }
    for (int j = y1; j < y2 + 1; j++) {
        gotoxy(x1, j);
        cout << "█";
        gotoxy(x2, j);
        cout << "█";
    }
    TurnWhite;
}

void UserInterface::Clear(int x1, int y1, int x2, int y2) {
    for (int i = x1; i < x2 + 1; i++) {
        for (int j = y1; j < y2 + 1; j++) {
            AdvancedOutputToXY(i, j, TurnWhite, " ");
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

        if (symbol >= VK_SPACE and (in_range(buffer, length))) {
            *ptr++ = symbol;
            if (replace == ' ') { putch(symbol); }
            else { putch(replace); }
        }
    } while (symbol != VK_RETURN);
    *ptr = 0;
    return buffer;
}


/*================================================MENU LOGIC FUNCTIONS==================================================
========================================================================================================================*/

int UserInterface::StartMenu() {
    int choice = 0;
    int select = 2;
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(50, 10, TurnWhite,
                       "WECLOME TO SUPER DUPER SYSTEM32 IN DATA BASE FOR ADMINS/CLIENTS/PEOPLE/GOLLUMS/WOMEN/DEMONS/GHOSTS/KURT COBAIN");
    AdvancedOutputToXY(150, 27, TurnWhite, "EXIT");
    AdvancedOutputToXY(50, 27, TurnBackGreen, "LOG IN");
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and select % 2 == 0) {
            AdvancedOutputToXY(50, 27, TurnWhite, "LOG IN");
            AdvancedOutputToXY(150, 27, TurnBackGreen, "EXIT");
            select++;
        } else if (KeyCheck(Key) == "tab" and (select + 1) % 2 == 0) {
            AdvancedOutputToXY(150, 27, TurnWhite, "EXIT");
            AdvancedOutputToXY(50, 27, TurnBackGreen, "LOG IN");
            select++;
        }
        //}
        if (select % 2 == 0 and KeyCheck(Key) == "enter") {
            system("cls");
            LogMenu();
        } else if ((select + 1) % 2 == 0 and KeyCheck(Key) == "enter") {
            exit(0);
        }
        sleep_for(milliseconds(100));
    }
}

int UserInterface::LogMenu() {
    int isAdmin = 0;
    int couter = 5;
    int CurrentX = 100;
    AdvancedOutputToXY(0, 30, TurnAqua);
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(99, 10, TurnWhite, "WHO ARE YOU");
    AdvancedOutputToXY(CurrentX + 50, 27, "ADMIN");
    AdvancedOutputToXY(CurrentX, 40, TurnWhite, "EXIT");
    AdvancedOutputToXY(CurrentX - 50, 27, TurnBackGreen, "USER");
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab") {
            if ((couter + 1) % 3 == 0) {
                AdvancedOutputToXY(CurrentX - 50, 27, TurnWhite, "USER");
                AdvancedOutputToXY(CurrentX, 40, TurnWhite, "EXIT");
                AdvancedOutputToXY(CurrentX + 50, 27, TurnBackGreen, "ADMIN");
                couter++;
                isAdmin = 1;
            } else if (couter % 3 == 0) {
                AdvancedOutputToXY(CurrentX - 50, 27, TurnWhite, "USER");
                AdvancedOutputToXY(CurrentX + 50, 27, TurnWhite, "ADMIN");
                AdvancedOutputToXY(CurrentX, 40, TurnBackGreen, "EXIT");
                couter++;
            } else if ((couter + 2) % 3 == 0) {
                AdvancedOutputToXY(CurrentX + 50, 27, TurnWhite, "ADMIN");
                AdvancedOutputToXY(CurrentX, 40, TurnWhite, "EXIT");
                AdvancedOutputToXY(CurrentX - 50, 27, TurnBackGreen, "USER");
                couter++;
                isAdmin = 0;
            }
        } else if (KeyCheck(Key) == "enter" and (couter + 2) % 3 == 0) {
            exit(0);
        } else if (isAdmin and KeyCheck(Key) == "enter") {
            while (1) {
                DrawFrame(108, 29, 198, 39);
                AdvancedOutputToXY(145, 30, TurnWhite, "LOGIN FOR ADMIN");
                AdvancedOutputToXY(113, 32, "Name : ");
                AdvancedOutputToXY(113, 36, "Password : ");
                string AdminLog = Input(120, 32, MAX_LOGIN, ' ');
                if (AdminLog == "-1") {
                    Clear(108, 29, 198, 39);
                    gotoxy(155, 27);
                    break;
                }
                string AdminPas = Input(124, 36, MAX_PASS, '*');
                if (AdminPas == "-1") {
                    Clear(108, 29, 198, 39);
                    gotoxy(155, 27);
                    break;
                }
                if (KeyCheck(Key) == "enter" and
                    (AdminLog == UserInterface::AdminLoggin and AdminPas == UserInterface::AdminPsswrd)) {
                    system("cls");
                    PersonalAdminArea();                                                                                  //admin=1
                }
                if (KeyCheck(Key) == "enter" and
                    (AdminLog != UserInterface::AdminLoggin or AdminPas != UserInterface::AdminPsswrd)) {
                    AdvancedOutputToXY(150, 38, TurnRed, "PASSWORDS MISMATCH");
                    sleep_for(milliseconds(1200));
                    Clear(108, 29, 198, 39);
                    continue;
                }
            }
        } else if (!isAdmin and KeyCheck(Key) == "enter") {
            int LoginFlag = 2;
            DrawFrame(42, 29, 61, 35);
            AdvancedOutputToXY(48, 33, TurnWhite, "REGISTER");
            AdvancedOutputToXY(48, 31, TurnBackGreen, "LOGG IN");
            for (;;) {
                int key = _getch();
                if (KeyCheck(key) == "tab" and LoginFlag % 2 == 0) {
                    AdvancedOutputToXY(48, 31, TurnWhite, "LOGG IN");
                    AdvancedOutputToXY(48, 33, TurnBackGreen, "REGISTER");
                    LoginFlag++;
                } else if (KeyCheck(key) == "tab" and (LoginFlag + 1) % 2 == 0) {
                    AdvancedOutputToXY(48, 33, TurnWhite, "REGISTER");
                    AdvancedOutputToXY(48, 31, TurnBackGreen, "LOGG IN");
                    LoginFlag++;
                } else if (KeyCheck(key) == "esc") {
                    Clear(42, 29, 61, 35);
                    gotoxy(54, 27);
                    break;
                } else if (LoginFlag % 2 == 0 and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    DrawFrame(10, 29, 100, 39);
                    AdvancedOutputToXY(52, 30, TurnWhite, "LOGIN");
                    AdvancedOutputToXY(15, 32, "Name : ");
                    AdvancedOutputToXY(15, 36, "Password : ");
                    string LoginResult = Input(22, 32, MAX_LOGIN, ' ');
                    if (LoginResult == "-1") {
                        Clear(10, 29, 100, 39);
                        gotoxy(54, 27);
                        break;
                    }
                    string PasswordResult = Input(26, 36, MAX_PASS, '*');
                    if (PasswordResult == "-1") {
                        Clear(10, 29, 100, 39);
                        gotoxy(54, 27);
                        break;
                    } else {
                        system("cls");
                        exit(1);
                    }
                } else if ((LoginFlag + 1) % 2 == 0 and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    DrawFrame(10, 29, 100, 43);
                    AdvancedOutputToXY(50, 30, TurnWhite, "REGISTRATION");
                    AdvancedOutputToXY(13, 33, "Enter your name : ");
                    AdvancedOutputToXY(13, 36, "Create password : ");
                    AdvancedOutputToXY(13, 39, "Repeat password : ");
                    for (;;) {
                        string RegLoginResult = Input(31, 33, MAX_LOGIN, ' ');
                        if (RegLoginResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }//else{system("cls");}
                        string RegPassResult = Input(31, 36, MAX_LOGIN, '*');
                        if (RegPassResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }
                        string RegPassCheckResult = Input(31, 39, MAX_LOGIN, '*');
                        if (RegPassCheckResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }
                        if (RegPassResult == RegPassCheckResult) {
                            system("cls");
                            exit(2);
                        } else if (RegPassResult != RegPassCheckResult) {
                            AdvancedOutputToXY(50, 41, TurnRed, "PASSWORDS MISMATCH");
                            sleep_for(milliseconds(1200));
                            Clear(31, 33, 68, 41);
                            continue;
                        }
                    }
                    break;
                }
            }
        }
    }
}

string UserInterface::DateChoice() {
    int CurrentY = 21;
    int CurrentX = 45;
    int Selector = 0;
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(CurrentX - 5, 11, TurnWhite, "CHOSE THE DATE");
    AdvancedOutputToXY(CurrentX, 24, TurnWhite, Date[Selector + 1]);
    AdvancedOutputToXY(CurrentX, 27, TurnWhite, Date[Selector + 2]);
    AdvancedOutputToXY(CurrentX, 21, TurnBackGreen, Date[Selector]);
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "s" and CurrentY != 27) {
            Selector++;
            AdvancedOutputToXY(CurrentX, CurrentY, TurnWhite, Date[Selector - 1]);
            CurrentY += 3;
            AdvancedOutputToXY(CurrentX, CurrentY, TurnBackGreen, Date[Selector]);
            gotoxy(CurrentX + 5, CurrentY);
        } else if (KeyCheck(Key) == "s" and CurrentY == 27 and Selector < 6) {
            Selector++;
            AdvancedOutputToXY(CurrentX, CurrentY, TurnBackGreen, Date[Selector]);
            AdvancedOutputToXY(CurrentX, CurrentY - 3, TurnWhite, Date[Selector - 1]);
            AdvancedOutputToXY(CurrentX, CurrentY - 6, TurnWhite, Date[Selector - 2]);
            gotoxy(CurrentX + 5, CurrentY);
        } else if (KeyCheck(Key) == "w" and CurrentY != 21) {
            Selector--;
            CurrentY -= 3;
            AdvancedOutputToXY(CurrentX, CurrentY, TurnBackGreen, Date[Selector]);
            AdvancedOutputToXY(CurrentX, CurrentY + 3, TurnWhite, Date[Selector + 1]);
            gotoxy(CurrentX + 5, CurrentY);
        } else if (KeyCheck(Key) == "w" and CurrentY == 21 and Selector != 0) {
            Selector--;
            AdvancedOutputToXY(CurrentX, CurrentY, TurnBackGreen, Date[Selector]);
            AdvancedOutputToXY(CurrentX, CurrentY + 3, TurnWhite, Date[Selector + 1]);
            AdvancedOutputToXY(CurrentX, CurrentY + 3, TurnWhite, Date[Selector + 2]);
            gotoxy(CurrentX + 5, CurrentY);
        } else if (KeyCheck(Key) == "esc") {
            Clear(40, 8, 60, 30);
            gotoxy(25,18);
            break;
        } else if(KeyCheck(Key)=="enter"){
            exit(5);
        }
    }
}

void UserInterface::PersonalAdminArea() {
    int selector = 7;
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(175, 8,  "Person Info");
    AdvancedOutputToXY(175, 12, "Login : admin");
    AdvancedOutputToXY(10, 11, TurnWhite, "Admin`s Functions");
    AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
    AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
    AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
    AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
    AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
    AdvancedOutputToXY(10, 18, TurnBackGreen, "Check User Info");
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and (selector + 5) % 6 == 0) {
            AdvancedOutputToXY(10, 18, TurnWhite, "Check User Info");
            AdvancedOutputToXY(10, 21, TurnBackGreen, "Add User");
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            gotoxy(18, 21);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 4) % 6 == 0) {
            AdvancedOutputToXY(10, 18, TurnWhite, "Check User Info");
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnBackGreen, "Delete User");
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            gotoxy(21, 24);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 3) % 6 == 0) {
            AdvancedOutputToXY(10, 18, TurnWhite, "Check User Info");
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnBackGreen, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            gotoxy(21, 27);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 2) % 6 == 0) {
            AdvancedOutputToXY(10, 18, TurnWhite, "Check User Info");
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnBackGreen, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            gotoxy(24, 30);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 1) % 6 == 0) {
            AdvancedOutputToXY(10, 18, TurnWhite, "Check User Info");
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnBackGreen, "Sort Database");
            gotoxy(23, 33);
            selector++;
        } else if (KeyCheck(Key) == "tab" and selector % 6 == 0) {
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            AdvancedOutputToXY(10, 18, TurnBackGreen, "Check User Info");
            selector++;
        } else if (KeyCheck(Key) == "enter" and (selector + 5) % 6 == 0) {
            DateChoice();
        }
    }
};



