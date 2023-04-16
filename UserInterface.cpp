//super govnocode by notFOUND
#include "UserInterface.h"
#include "Utility.h"

/*============================================TOOL FUNCTIONS==============================================================
========================================================================================================================*/

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

        if (symbol == VK_BKSPC  && ptr > buffer) {
            *--ptr = 0;
            putch(VK_BKSPC);
            putch(VK_SPACE);
            putch(VK_BKSPC);
            continue;
        }
        //if (symbol== VK_RIGHT){
            //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        //}
        if (symbol == VK_ESCAPE) { return "-1"; }

        if (!symbol  ) {
            getch();
            continue;
        }

        if (symbol > VK_SPACE  and (in_range(buffer, length))) {
            *ptr++ = symbol;
            if (replace == ' ') { putch(symbol); }
            else { putch(replace); }
        }
    } while (symbol != VK_RETURN );
    *ptr = 0;
    return buffer;
}


/*================================================MENU LOGIC FUNCTIONS==================================================
========================================================================================================================*/

int UserInterface::StartMenu() {
    int flag = 0;
    int choice = 0;
    AdvancedOutputToXY(0, 30, TurnAqua);
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(50, 10, TurnWhite, "WECLOME TO SUPER DUPER SYSTEM32 IN DATA BASE FOR ADMINS/CLIENTS/PEOPLE/GOLLUMS/WOMEN/DEMONS/GHOSTS/KURT COBAIN");
    AdvancedOutputToXY(50, 27, TurnBackGreen, "LOG IN");
    AdvancedOutputToXY(150, 27, TurnWhite, "EXIT");
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
        } //else if (KeyCheck(Key)!="a" and KeyCheck(Key)!="d"){

        //}
        if (flag == 0 and KeyCheck(Key) == "enter") {
            system("cls");
            return choice;
        } else if (flag == 1 and KeyCheck(Key) == "enter") {
            exit(0);
        }
        sleep_for(milliseconds(100));
    }
}


int UserInterface::AdminChoice() {
    string res = Input(145, 37, MAX_PASS, '*');
    if (res == "-1") {return -1;}
    if (res != AdminPsswrd) {
        AdvancedOutputToXY(145, 34, TurnRed, "WRONG PASSWORD");
        sleep_for(milliseconds(1200));
        AdvancedOutputToXY(145, 34, TurnWhite, "              ");
        AdvancedOutputToXY(145, 37, "           ");
        gotoxy(145, 37);
        return 0;



    } else if(res==AdminPsswrd) {

        int flagg = 0;
        AdvancedOutputToXY(145, 39, TurnWhite, "log in to : "); TurnBackGreen; cout << "admin";
        AdvancedOutputToXY(145, 41, TurnWhite, "log in to : ");
        TurnWhite; gotoxy(145, 41); cout << "log in to : server"; gotoxy(162, 39);

        for(;;) {
            int Key = _getch();
            if (KeyCheck(Key) == "s") {
                AdvancedOutputToXY(157, 39, TurnWhite, "admin");
                AdvancedOutputToXY(157, 41, TurnBackGreen, "server");
                flagg = 1;

            } else if (KeyCheck(Key) == "w") {
                AdvancedOutputToXY(157, 41, TurnWhite, "server");
                AdvancedOutputToXY(157, 39, TurnBackGreen, "admin");
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
    AdvancedOutputToXY(0, 30, TurnAqua);
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(99, 10, TurnWhite, "WHO ARE YOU");
    AdvancedOutputToXY(150, 27, "ADMIN");
    AdvancedOutputToXY(50, 27, TurnBackGreen, "USER");

    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "d") {
            AdvancedOutputToXY(50, 27, TurnWhite, "USER");
            AdvancedOutputToXY(150, 27, TurnBackGreen, "ADMIN");
            isAdmin = 1;
        } else if (KeyCheck(Key) == "a") {
            AdvancedOutputToXY(50, 27, TurnBackGreen, "USER");
            AdvancedOutputToXY(150, 27, TurnWhite, "ADMIN");
            isAdmin = 0;

        } else if (isAdmin and KeyCheck(Key) == "enter") {
            TurnAqua; DrawFrame(130, 29, 172, 43);
            AdvancedOutputToXY(145, 32, TurnWhite, "ENTER PASSWORD");
            AdvancedOutputToXY(134, 37, "Password : ");

            for (;;) {
                int res = AdminChoice();
                if (res == -1) {
                    TurnWhite; Clear(130, 29, 172, 43); gotoxy(155, 27);
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
            int LoginFlag = 1;
            TurnAqua; DrawFrame(42, 29, 61, 35);

            AdvancedOutputToXY(48, 33, TurnWhite, "REGISTER");
            AdvancedOutputToXY(48, 31, TurnBackGreen, "LOGGIN");

            for (;;) {
                int key = _getch();
                if (KeyCheck(key) == "s") {
                    AdvancedOutputToXY(48, 31, TurnWhite, "LOGGIN");
                    AdvancedOutputToXY(48, 33, TurnBackGreen, "REGISTER");
                    LoginFlag = 0;
                } else if (KeyCheck(key) == "w") {
                    AdvancedOutputToXY(48, 33, TurnWhite, "REGISTER");
                    AdvancedOutputToXY(48, 31, TurnBackGreen, "LOGGIN");
                    LoginFlag = 1;
                }
                else if(KeyCheck(key)=="esc"){
                    Clear(42, 29, 61, 35);
                    gotoxy(54, 27);
                    break;
                }

                else if (LoginFlag and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    TurnAqua; DrawFrame(10, 29, 100, 39);
                    AdvancedOutputToXY(52, 30, TurnWhite, "LOGIN");
                    AdvancedOutputToXY(15, 32, "Name: ");
                    AdvancedOutputToXY(15, 36, "Password: ");

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
                    } else {system("cls");}
                    //if (Database::FindUser(LoginResult, PasswordResult)) { return to main }



                } else if (!LoginFlag and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    TurnAqua; DrawFrame(10, 29, 100, 43);
                    AdvancedOutputToXY(50, 30, TurnWhite, "REGISTRATION");
                    AdvancedOutputToXY(13, 33, "Enter your name : ");
                    AdvancedOutputToXY(13, 36, "Create password : ");
                    AdvancedOutputToXY(13, 39, "Repeat password : ");

                    for(;;) {
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
                        if(RegPassResult==RegPassCheckResult) {
                            //Database::AddUser(RegLoginResult, RegPassResult); return to login menu;
                        } else if (RegPassResult!=RegPassCheckResult) {
                            AdvancedOutputToXY(50, 41, TurnRed, "PASSWORDS MISMATCH");
                            sleep_for(milliseconds(1200));
                            TurnWhite;
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


void UserInterface::MainMenu() {
    //admin
//if(LogMenu()==-2){
    system("cls");
    TurnAqua;
    DrawFrame(0, 0, 210, 53);
    TurnWhite;
    gotoxy(20,4);
    cout<<"CHOSE THE DATE";
    TurnBackGreen;
    gotoxy(25,17);
    cout<<"05.05";
    TurnWhite;
    gotoxy(25,24);
    cout<<"06.06";
    TurnWhite;
    gotoxy(25,31);
    cout<<"07.07";
    gotoxy(30,17);


//}






}


