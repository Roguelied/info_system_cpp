//super govnocode by notFOUND
#include "UserInterface.h"


string UserInterface::AdminPsswrd = "admin";
string UserInterface::AdminLoggin = "admin";
string UserInterface::ServerPsswrd = "server_";
string UserInterface::ServerLoggin = "server_";
vector<Button> UserInterface::Buttons = {};
vector<string> UserInterface::Date{"01.01", "20.04", "12.05", "10.06", "09.07", "09.11", "19.11"};
vector<string> UserInterface::reserv = {};

/*============================================TOOL FUNCTIONS==============================================================
========================================================================================================================*/


std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


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

string UserInterface::Input(int x, int y, char *length, char replace) {

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

void UserInterface::StartMenu() {
    DrawFrame(0, 0, 119, 29);
    AdvancedOutputToXY(5, 5, TurnWhite,
                       "WECLOME TO SUPER DUPER SYSTEM32 IN DATA BASE FOR ADMINS/CLIENTS/PEOPLE/GOLLUMS/WOMEN/DEMONS/GHOSTS/KURT COBAIN");
    Button Enter(20, 16, "ENTER", UserInterface::Press);
    Button Exit(100, 16, "EXIT", UserInterface::Press);
    UserInterface::SelectionMode();
    UserInterface::DeleteButtons();
    LogMenu();
}

int UserInterface::LogMenu() {
    int couter = 1;
    DrawFrame(0, 0, 119, 29);
    AdvancedOutputToXY(50, 10, TurnWhite, "ENTER SYSTEM 32");
    AdvancedOutputToXY(100, 16, TurnWhite, "EXIT");
    AdvancedOutputToXY(20, 16, TurnBackGreen, "USER");
    while (true) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab") {
            if ((couter + 1) % 2 == 0) {
                AdvancedOutputToXY(20, 16, TurnWhite, "USER");
                AdvancedOutputToXY(100, 16, TurnBackGreen, "EXIT");
                couter++;
            } else if (couter % 2 == 0) {
                AdvancedOutputToXY(100, 16, TurnWhite, "EXIT");
                AdvancedOutputToXY(20, 16, TurnBackGreen, "USER");
                couter++;
            }
        } else if (KeyCheck(Key) == "enter" and couter % 2 == 0) {
            exit(666);
        } else if ((couter + 1) % 2 == 0 and KeyCheck(Key) == "enter") {
            int LoginFlag = 2;
            DrawFrame(16, 18, 29, 22);
            AdvancedOutputToXY(19, 21, TurnWhite, "REGISTER");
            AdvancedOutputToXY(19, 19, TurnBackGreen, "LOGG IN");
            for (;;) {
                int key = _getch();
                if (KeyCheck(key) == "tab" and LoginFlag % 2 == 0) {
                    AdvancedOutputToXY(19, 19, TurnWhite, "LOGG 1N");
                    AdvancedOutputToXY(19, 21, TurnBackGreen, "REGISTER");
                    LoginFlag++;
                } else if (KeyCheck(key) == "tab" and (LoginFlag + 1) % 2 == 0) {
                    AdvancedOutputToXY(19, 21, TurnWhite, "REGISTER");
                    AdvancedOutputToXY(19, 19, TurnBackGreen, "LOGG 1N");
                    LoginFlag++;
                } else if (KeyCheck(key) == "esc") {
                    Clear(16, 18, 29, 22);
                    gotoxy(24, 16);
                    break;
                } else if (LoginFlag % 2 == 0 and KeyCheck(key) == "enter") {
                    Clear(16, 18, 29, 22);
                    DrawFrame(5, 18, 40, 26);
                    AdvancedOutputToXY(20, 19, TurnWhite, "LOG1N");
                    AdvancedOutputToXY(10, 21, "Name : ");
                    AdvancedOutputToXY(10, 23, "Password : ");
                    string LoginResult = Input(17, 21, MAX_INPUT, ' ');

                    if (LoginResult == "-1" or LoginResult.empty()) {
                        Clear(5, 18, 40, 26);
                        gotoxy(24, 16);
                        break;
                    }
                    string PasswordResult = Input(21, 23, MAX_INPUT, '*');
                    if (PasswordResult == "-1" or PasswordResult.empty()) {
                        Clear(5, 18, 40, 26);
                        gotoxy(24, 16);
                        break;
                    }
                    string Result = Client::AskServer("UFND " + LoginResult + "%" + PasswordResult + "%");
                    if (Result == "WRONGPASS" or Result == "NOTFOUND") {
                        AdvancedOutputToXY(18, 25, TurnRed, Result);
                        sleep_for(milliseconds(1000));
                        Clear(5, 18, 40, 26);
                        gotoxy(24, 16);
                        break;
                    } else {
                        stringstream StringStream(Result);
                        system("cls");
                        StringStream >> Client::User.Index;
                        StringStream >> Client::User.Login;
                        StringStream >> Client::User.Password;
                        StringStream >> Client::User.ID;
                        StringStream >> Client::User.AdminFlag;
                        if (Client::User.AdminFlag == "1") {
                            PersonalAdminArea();
                            break;
                        } else {
                            PersonalUserArea();
                            break;
                        }
                    }

                } else if ((LoginFlag + 1) % 2 == 0 and KeyCheck(key) == "enter") {
                    Clear(5, 18, 40, 26);
                    DrawFrame(5, 18, 40, 27);
                    AdvancedOutputToXY(20, 19, TurnWhite, "REGISTRATION");
                    AdvancedOutputToXY(10, 21, "Enter your name : ");
                    AdvancedOutputToXY(10, 23, "Create password : ");
                    AdvancedOutputToXY(10, 25, "Repeat password : ");
                    for (;;) {
                        string RegLoginResult = Input(28, 21, MAX_INPUT, ' ');
                        if (RegLoginResult == "-1") {
                            Clear(5, 18, 40, 26);
                            gotoxy(24, 16);
                            break;
                        }//else{system("cls");}
                        string RegPassResult = Input(28, 23, MAX_INPUT, '*');
                        if (RegPassResult == "-1") {
                            Clear(5, 18, 40, 26);
                            gotoxy(24, 16);
                            break;
                        }
                        string RegPassCheckResult = Input(28, 25, MAX_INPUT, '*');
                        if (RegPassCheckResult == "-1") {
                            Clear(5, 18, 40, 26);
                            gotoxy(24, 16);
                            break;
                        }
                        if (RegPassResult == RegPassCheckResult) {
                            string Result = Client::AskServer(
                                    "UREG " + RegLoginResult + "%" + RegPassCheckResult + "%");
                            if (Result == "Username is taken") {
                                AdvancedOutputToXY(10, 26, TurnRed, Result);
                                sleep_for(milliseconds(1200));
                                Clear(5, 18, 40, 27);
                                gotoxy(24, 16);
                                break;
                            } else {
                                AdvancedOutputToXY(6, 26, TurnRed, "SUCCESSFULLY REGISTERED,SIGN IN");
                                sleep_for(milliseconds(1200));
                                Clear(5, 18, 40, 27);
                                gotoxy(24, 16);
                                break;
                            }
                        } else if (RegPassResult != RegPassCheckResult) {
                            AdvancedOutputToXY(10, 26, TurnRed, "PASSWORDS MISMATCH");
                            sleep_for(milliseconds(1200));
                            Clear(5, 18, 40, 27);
                            gotoxy(24, 16);
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}

string UserInterface::DateChoice() {
    string ListOfAvailable = Client::AskServer("AALL");
    cout << ListOfAvailable;
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
            gotoxy(25, 18);
            break;
        } else if (KeyCheck(Key) == "enter") {
            exit(5);
        }
    }
}

void UserInterface::PersonalUserArea() {
    DrawFrame(0, 0, 119, 29);
    AdvancedOutputToXY(2, 3, TurnWhite, "login : " + Client::User.Login);
    AdvancedOutputToXY(2, 5, TurnWhite, "user id : " + Client::User.ID);
    AdvancedOutputToXY(20, 3, TurnWhite, "ALL RESERVED BY " + Client::User.Login);
    string Str = Client::AskServer("DFFR " + Client::User.Login + "%");
    std::string delimiter = "\n";
    vector<string>reserv7  = split(Str, delimiter);
    int CurrentY = 5;
    for (auto i: reserv7) {
        AdvancedOutputToXY(20, CurrentY, TurnYellow, i);
        CurrentY += 2;
    }
    //AdvancedOutputToXY(20, 5, TurnWhite, Client::AskServer("DFFR " + Client::User.Login + "%"));
    AdvancedOutputToXY(70, 5, TurnWhite, "Exit Account");
    AdvancedOutputToXY(70, 7, TurnWhite, "Exit System");
    AdvancedOutputToXY(70, 3, TurnBackGreen, "Reserve somethink");
    int Couter = 1;
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and (Couter + 2) % 3 == 0) {
            AdvancedOutputToXY(70, 3, TurnWhite, "Reserve somethink");
            AdvancedOutputToXY(70, 5, TurnBackGreen, "Exit Account");
            Couter++;
        } else if (KeyCheck(Key) == "tab" and (Couter + 1) % 3 == 0) {
            AdvancedOutputToXY(70, 5, TurnWhite, "Exit Account");
            AdvancedOutputToXY(70, 7, TurnBackGreen, "Exit System");
            Couter++;
        } else if (KeyCheck(Key) == "tab" and (Couter) % 3 == 0) {
            AdvancedOutputToXY(70, 7, TurnWhite, "Exit System");
            AdvancedOutputToXY(70, 3, TurnBackGreen, "Reserve somethink");
            Couter++;
        } else if (KeyCheck(Key) == "enter" and Couter % 3 == 0) {
            exit(666);
        } else if (KeyCheck(Key) == "enter" and (Couter + 1) % 3 == 0) {
            system("cls");
            LogMenu();
            break;
        } else if (KeyCheck(Key) == "enter" and ((Couter + 2) % 3 == 0)) {
            system("cls");
            Reservations();
            break;
        }
    }

    wait;

}

void UserInterface::Reservations() {
    DrawFrame(0, 0, 119, 29);
    string Str = Client::AskServer("AALL");
    std::string delimiter = "\n";
    vector<string> reserv3 = split(Str, delimiter);
    int CurrentY = 6;
    for (auto i: reserv3) {
        AdvancedOutputToXY(10, CurrentY, TurnWhite, i);
        CurrentY += 1;
    }
    AdvancedOutputToXY(70, 9, TurnWhite, "Back to Personal Area");
    AdvancedOutputToXY(70, 12, TurnWhite, "Exit Account");
    AdvancedOutputToXY(70, 15, TurnWhite, "Exit System");
    AdvancedOutputToXY(10, 4, TurnBackGreen, "Available Reservations");
    int Couter = 1;
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and (Couter + 3) % 4 == 0) {
            AdvancedOutputToXY(10, 4, TurnWhite, "Available Reservations");
            AdvancedOutputToXY(70, 9, TurnBackGreen, "Back to Personal Area");
            Couter++;
        } else if (KeyCheck(Key) == "tab" and (Couter + 2) % 4 == 0) {
            AdvancedOutputToXY(70, 9, TurnWhite, "Back to Personal Area");
            AdvancedOutputToXY(70, 12, TurnBackGreen, "Exit Account");
            Couter++;
        } else if (KeyCheck(Key) == "tab" and (Couter + 1) % 4 == 0) {
            AdvancedOutputToXY(70, 12, TurnWhite, "Exit Account");
            AdvancedOutputToXY(70, 15, TurnBackGreen, "Exit System");
            Couter++;
        } else if (KeyCheck(Key) == "tab" and (Couter) % 4 == 0) {
            AdvancedOutputToXY(70, 15, TurnWhite, "Exit System");
            AdvancedOutputToXY(10, 4, TurnBackGreen, "Available Reservations");
            Couter++;
        } else if (KeyCheck(Key) == "enter" and (Couter + 2) % 4 == 0) {
            system("cls");
            PersonalUserArea();
            break;
        } else if (KeyCheck(Key) == "enter" and (Couter + 1) % 4 == 0) {
            system("cls");
            LogMenu();
            break;
        } else if (KeyCheck(Key) == "enter" and (Couter) % 4 == 0) {
            exit(666);
        } else if (KeyCheck(Key) == "enter" and (Couter + 3) % 4 == 0) {
            int CurrentY = 6;
            for (auto i: reserv3) {
                AdvancedOutputToXY(10, CurrentY, TurnWhite, i);
                CurrentY += 1;
            }
            AdvancedOutputToXY(7, 6, TurnBackGreen, "=>");
            int couter = 0;
            int lenth = reserv3.capacity();
            int currenty = 6;
            for (;;) {
                gotoxy(0, 0);
                cout << "        ";
                gotoxy(0, 0);
                cout << couter;


                int key = _getch();
                if (KeyCheck(key) == "enter") {
                    string ResRequest;
                    stringstream ss(reserv3[couter]);
                    string Index, Type, Date, Seat, Name;
                    ss >> Index >> Type >> Date >> Seat >> Name;
                    ResRequest = "RES " + Index + " "  + Client::User.Login + "%";
                    string Result = Client::AskServer(ResRequest);
                    if (Result == "ALREADY RESERVED") {
                        AdvancedOutputToXY(25, currenty, TurnRed, "Already reserved");
                    } else  {
                        AdvancedOutputToXY(7+2, currenty, TurnGreen, Index + " " + Type + " " + Date + " " + Seat  + " " + Client::User.Login + "  Reserved");
                    }
                }
                TurnWhite;

                if (KeyCheck(key) == "tab" and couter != lenth - 1) {
                    AdvancedOutputToXY(7, currenty, "  ");
                    currenty++;
                    AdvancedOutputToXY(7, currenty, TurnBackGreen, "=>");
                    couter++;
                } else if (KeyCheck(key) == "tab" and couter == lenth - 1) {
                    AdvancedOutputToXY(7, currenty, "  ");
                    AdvancedOutputToXY(7, currenty - lenth + 1, TurnBackGreen, "=>");
                    couter = 0;
                    currenty = 6;
                } else if (KeyCheck(key) == "esc" and (Couter + 3) % 4 == 0) {
                    Clear(10, 6, 50, 27);
                    AdvancedOutputToXY(7, currenty, "  ");
                    gotoxy(32, 4);
                    break;
                } else if (KeyCheck(key) == "enter") {
//ТУТ
                }
            }
        }
    }
}

void UserInterface::UpdateBase() {
    Clear(30, 6, 100, 27);
    string Str = Client::AskServer("DALL");
    std::string delimiter = "\n";
    reserv = split(Str, delimiter);
    int CurrentY = 6;
    for (auto i: reserv) {
        AdvancedOutputToXY(30, CurrentY, TurnWhite, i);
        CurrentY += 1;
    }
    string Str1 = Client::AskServer("UALL");
    std::string delimiter1 = "\n";
    vector<string> reserv1 = split(Str1, delimiter1);
    int CurrentYy = 6;
    for (auto j: reserv1) {
        AdvancedOutputToXY(70, CurrentYy, TurnWhite, j);
        CurrentYy += 1;
    }
}

void UserInterface::PersonalAdminArea() {
    int selector = 1;
    DrawFrame(0, 0, 119, 29);
    UpdateBase();
    AdvancedOutputToXY(3, 3, TurnWhite, "Admin`s Functions");
    AdvancedOutputToXY(90, 2, TurnRed, "admin login : " + Client::User.Login);
    AdvancedOutputToXY(90, 3, TurnRed, "admin ID : " + Client::User.ID);
    AdvancedOutputToXY(3, 7, TurnWhite, "Delete User");
    AdvancedOutputToXY(3, 9, TurnWhite, "Add Booking");
    AdvancedOutputToXY(3, 11, TurnWhite, "Delete Booking");
    AdvancedOutputToXY(3, 13, TurnWhite, "Exit Account");
    AdvancedOutputToXY(3, 15, TurnWhite, "Exit System");
    AdvancedOutputToXY(3, 5, TurnBackGreen, "Add User");
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and (selector + 5) % 6 == 0) {
            AdvancedOutputToXY(3, 5, TurnWhite, "Add User");
            AdvancedOutputToXY(3, 7, TurnBackGreen, "Delete User");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 4) % 6 == 0) {
            AdvancedOutputToXY(3, 7, TurnWhite, "Delete User");
            AdvancedOutputToXY(3, 9, TurnBackGreen, "Add Booking");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 3) % 6 == 0) {
            AdvancedOutputToXY(3, 9, TurnWhite, "Add Booking");
            AdvancedOutputToXY(3, 11, TurnBackGreen, "Delete Booking");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 2) % 6 == 0) {
            AdvancedOutputToXY(3, 11, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(3, 13, TurnBackGreen, "Exit Account");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 1) % 6 == 0) {
            AdvancedOutputToXY(3, 13, TurnWhite, "Exit Account");
            AdvancedOutputToXY(3, 15, TurnBackGreen, "Exit System");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector) % 6 == 0) {
            AdvancedOutputToXY(3, 15, TurnWhite, "Exit System");
            AdvancedOutputToXY(3, 5, TurnBackGreen, "Add User");
            selector++;
        } else if (KeyCheck(Key) == "enter" and (selector + 5) % 6 == 0) {
            DrawFrame(3, 17, 27, 23);
            AdvancedOutputToXY(5, 18, TurnWhite, "log : ");
            AdvancedOutputToXY(5, 20, TurnWhite, "pas : ");
            for (;;) {
                string AddUserLogin = Input(11, 18, MAX_INPUT, ' ');
                if (AddUserLogin == "-1" or AddUserLogin.empty()) {
                    Clear(3, 17, 27, 23);
                    gotoxy(11, 5);
                    break;
                }
                string AddUserPass = Input(11, 20, MAX_INPUT, ' ');
                if (AddUserLogin == "-1" or AddUserPass.empty()) {
                    Clear(3, 17, 27, 23);
                    gotoxy(11, 5);
                    break;
                }
                string Result = Client::AskServer("UFND " + AddUserLogin + "%" + AddUserPass);
                if (Result == "WRONGPASS") {
                    AdvancedOutputToXY(5, 22, TurnRed, "This user already add");
                    sleep_for(milliseconds(1000));
                    Clear(3, 17, 27, 23);
                    gotoxy(11, 5);
                    break;
                } else {
                    Client::AskServer("UREG " + AddUserLogin + "%" + AddUserPass + "%");
                    AdvancedOutputToXY(9, 22, TurnYellow, "Successful add");
                    sleep_for(milliseconds(1000));
                    Clear(3, 17, 27, 23);
                    UpdateBase();
                    gotoxy(11, 5);
                    break;
                }
            }
        } else if (KeyCheck(Key) == "enter" and (selector + 4) % 6 == 0) {
            DrawFrame(3, 17, 27, 21);
            AdvancedOutputToXY(5, 18, TurnWhite, "index : ");
            for (;;) {
                string DeleteIndex = Input(13, 18, MAX_INDEX, ' ');
                if (DeleteIndex == "-1" or DeleteIndex.empty()) {
                    Clear(3, 17, 27, 21);
                    gotoxy(13, 7);
                    break;
                } else {
                    string str = Client::AskServer("UDEL " + DeleteIndex);
                    if (str == "NOTFOUND") {
                        AdvancedOutputToXY(9, 20, TurnRed, "User not found");
                        sleep_for(milliseconds(1000));
                        Clear(3, 17, 27, 21);
                        gotoxy(14, 7);
                        break;
                    } else {
                        AdvancedOutputToXY(9, 20, TurnYellow, "Successful del");
                        sleep_for(milliseconds(1000));
                        Clear(3, 17, 27, 21);
                        UpdateBase();
                        gotoxy(14, 7);
                        break;
                    }
                }
            }
        } else if (KeyCheck(Key) == "enter" and (selector + 1) % 6 == 0) {
            system("cls");
            LogMenu();
            break;
        } else if (KeyCheck(Key) == "enter" and (selector) % 6 == 0) {
            exit(666);

        } else if (KeyCheck(Key) == "enter" and (selector + 2) % 6 == 0) {
            DrawFrame(3, 17, 27, 21);
            AdvancedOutputToXY(5, 18, TurnWhite, "book index : ");
            for (;;) {
                string DeleteDataIndex = Input(18, 18, MAX_INDEX, ' ');
                if (DeleteDataIndex == "-1" or DeleteDataIndex.empty()) {
                    Clear(3, 17, 27, 21);
                    gotoxy(11, 11);
                    break;
                } else {
                    string str1 = Client::AskServer("DDEL " + DeleteDataIndex);
                    if (str1 == "Reservation not found") {
                        AdvancedOutputToXY(9, 20, TurnRed, "Book not found");
                        sleep_for(milliseconds(1000));
                        Clear(3, 17, 27, 21);
                        gotoxy(17, 11);
                        break;
                    } else {
                        AdvancedOutputToXY(9, 20, TurnYellow, "Successful del");
                        sleep_for(milliseconds(1000));
                        Clear(3, 17, 27, 21);
                        UpdateBase();
                        gotoxy(17, 11);
                        break;
                    }
                }
            }
        } else if (KeyCheck(Key) == "enter" and (selector + 3) % 6 == 0) {
            system("cls");
            BookingAdd();
            gotoxy(14, 9);
            break;
        }
    }
}

void UserInterface::BookingAdd() {
    vector<string> Class{"ACLASS", "BCLASS", "CCLASS"};
    vector<string> Datee{"01.01.2023/00:00", "20.04.2023/05:35", "05.05.2023/18:40", "08.05.2023/18:44",
                         "12.05.2023/10:20", "10.06.2023/06:06", "09.07.2023/21:40", "09.11.2023/18:15",
                         "19.11.2023/19:19"};
    string Book;
    AdvancedOutputToXY(20, 3, TurnWhite, "Chose date");
    AdvancedOutputToXY(60, 3, TurnWhite, "Enter seat");
    AdvancedOutputToXY(100, 3, TurnWhite, "exit");
    AdvancedOutputToXY(3, 3, TurnBackGreen, "Chose class");
    int Couter = 1;
    while (1) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab" and (Couter + 3) % 4 == 0) {
            AdvancedOutputToXY(3, 3, TurnWhite, "Chose class");
            AdvancedOutputToXY(20, 3, TurnBackGreen, "Chose date");
            Couter++;
        }
        else if (KeyCheck(Key) == "tab" and (Couter + 2) % 4 == 0) {
            AdvancedOutputToXY(20, 3, TurnWhite, "Chose date");
            AdvancedOutputToXY(60, 3, TurnBackGreen, "Enter seat");
            Couter++;

        }
        else if (KeyCheck(Key) == "tab" and (Couter+1) % 4 == 0) {
            AdvancedOutputToXY(60, 3, TurnWhite, "Enter seat");
            AdvancedOutputToXY(100, 3, TurnBackGreen, "exit");
            Couter++;
        }
        else if (KeyCheck(Key) == "tab" and (Couter) % 4 == 0) {
            AdvancedOutputToXY(100, 3, TurnWhite, "exit");
            AdvancedOutputToXY(3, 3, TurnBackGreen, "Chose class");
            Couter++;
        }
        else if (KeyCheck(Key) == "enter" and (Couter + 3) % 4 == 0) {
            int CurrenrClass = 0;
            AdvancedOutputToXY(3, 8, TurnWhite, Class[1]);
            AdvancedOutputToXY(3, 10, TurnWhite, Class[2]);
            AdvancedOutputToXY(3, 6, TurnBackGreen, Class[CurrenrClass]);
            int ClassCouter = 1;
            while (1) {
                int key = _getch();
                if (KeyCheck(key) == "tab" and (ClassCouter + 2) % 3 == 0) {
                    AdvancedOutputToXY(3, 6, TurnWhite, Class[CurrenrClass]);
                    CurrenrClass++;
                    AdvancedOutputToXY(3, 8, TurnBackGreen, Class[CurrenrClass]);
                    ClassCouter++;
                } else if (KeyCheck(key) == "tab" and (ClassCouter + 1) % 3 == 0) {
                    AdvancedOutputToXY(3, 8, TurnWhite, Class[CurrenrClass]);
                    CurrenrClass++;
                    AdvancedOutputToXY(3, 10, TurnBackGreen, Class[CurrenrClass]);
                    ClassCouter++;
                } else if (KeyCheck(key) == "tab" and (ClassCouter) % 3 == 0) {
                    AdvancedOutputToXY(3, 10, TurnWhite, Class[CurrenrClass]);
                    CurrenrClass = 0;
                    AdvancedOutputToXY(3, 6, TurnBackGreen, Class[CurrenrClass]);
                    ClassCouter++;
                } else if (KeyCheck(key) == "enter") {
                    Book = Class[CurrenrClass] + "%";
                    AdvancedOutputToXY(20, 27, Book);
                    break;
                }
            }
        }
        else if (KeyCheck(Key) == "enter" and (Couter + 2) % 4 == 0) {
            int CurrenDate = 0;
            AdvancedOutputToXY(20, 7, Datee[1]);
            AdvancedOutputToXY(20, 8, Datee[2]);
            AdvancedOutputToXY(20, 9, Datee[3]);
            AdvancedOutputToXY(20, 10, Datee[4]);
            AdvancedOutputToXY(20, 11, Datee[5]);
            AdvancedOutputToXY(20, 12, Datee[6]);
            AdvancedOutputToXY(20, 13, Datee[7]);
            AdvancedOutputToXY(20, 14, Datee[8]);
            AdvancedOutputToXY(20, 6, TurnBackGreen, Datee[CurrenDate]);
            int DataCouter = 1;
            while (1) {
                int _key = _getch();
                if (KeyCheck(_key) == "tab" and (DataCouter + 8) % 9 == 0) {
                    AdvancedOutputToXY(20, 6, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 7, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 7) % 9 == 0) {
                    AdvancedOutputToXY(20, 7, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 8, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 6) % 9 == 0) {
                    AdvancedOutputToXY(20, 8, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 9, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 5) % 9 == 0) {
                    AdvancedOutputToXY(20, 9, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 10, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 4) % 9 == 0) {
                    AdvancedOutputToXY(20, 10, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 11, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 3) % 9 == 0) {
                    AdvancedOutputToXY(20, 11, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 12, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 2) % 9 == 0) {
                    AdvancedOutputToXY(20, 12, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 13, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter + 1) % 9 == 0) {
                    AdvancedOutputToXY(20, 13, Datee[CurrenDate]);
                    CurrenDate++;
                    AdvancedOutputToXY(20, 14, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "tab" and (DataCouter) % 9 == 0) {
                    AdvancedOutputToXY(20, 14, Datee[CurrenDate]);
                    CurrenDate = 0;
                    AdvancedOutputToXY(20, 6, TurnBackGreen, Datee[CurrenDate]);
                    DataCouter++;
                } else if (KeyCheck(_key) == "enter") {
                    Book += Datee[CurrenDate] + "%";
                    AdvancedOutputToXY(20, 27, Book);
                    break;
                }
            }
        }
        else if (KeyCheck(Key) == "enter" and (Couter+1) % 4 == 0) {
            AdvancedOutputToXY(60, 6, "enter seat : ");
            for (;;) {
                string SeatSelect = Input(73, 6, MAX_INDEX, ' ');
                if (SeatSelect == "-1" or SeatSelect.empty() or atoi(SeatSelect.c_str()) < 1 or
                    atoi(SeatSelect.c_str()) >= 50) {
                    Clear(60, 6, 80, 8);
                    gotoxy(70, 3);
                    break;
                } else {

                    Book += SeatSelect + "%NONE";
                    AdvancedOutputToXY(20, 27, Book);
                    wait;
                    string Result = Client::AskServer("DFND " + Book);
                    if (Result == "NOTFOUND") {
                        Client::AskServer("DADD " + Book);
                        AdvancedOutputToXY(60, 8, TurnYellow, "Successfuly added");
                        sleep_for(milliseconds(1000));
                        system("cls");
                        PersonalAdminArea();
                        break;
                    } else {
                        AdvancedOutputToXY(60, 8, TurnRed, "Already in database");
                        sleep_for(milliseconds(1000));
                        Clear(3, 6, 80, 27);
                        gotoxy(70, 3);
                        break;
                    }
                }
            }
        }
        else if (KeyCheck(Key)=="enter" and Couter%4==0){
            system("cls");
            PersonalAdminArea();
            break;
        }
    }
}

//**********************************************************************************************************************
int UserInterface::Press() {
    return 0;
}


int UserInterface::SelectionMode() {
    int SizeVec = size(Buttons);
    int flagEBYCHIU = 0;
    AdvancedOutputToXY(Buttons[flagEBYCHIU].x1, Buttons[flagEBYCHIU].y1, TurnBackGreen, Buttons[flagEBYCHIU].Text);
    for (;;) {
        int Key = _getch();
        if (KeyCheck(Key) == "tab") {
            if (flagEBYCHIU != SizeVec - 1) {
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1, Buttons[flagEBYCHIU].y1, TurnWhite,
                                   Buttons[flagEBYCHIU].Text);
                flagEBYCHIU++;
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1, Buttons[flagEBYCHIU].y1, TurnBackGreen,
                                   Buttons[flagEBYCHIU].Text);
            } else {
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1, Buttons[flagEBYCHIU].y1, TurnWhite,
                                   Buttons[flagEBYCHIU].Text);
                flagEBYCHIU = 0;
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1, Buttons[flagEBYCHIU].y1, TurnBackGreen,
                                   Buttons[flagEBYCHIU].Text);
            }
        }
        if (KeyCheck(Key) == "enter" and flagEBYCHIU != SizeVec - 1) {
            Buttons[flagEBYCHIU].Action();
            system("cls");
            break;
        } else if (KeyCheck(Key) == "enter" and flagEBYCHIU == SizeVec - 1) {
            exit(999);
        } else if (KeyCheck(Key) == "esc") {
            continue;
        }
    }
}

void UserInterface::AddButton(Button Button) {
    Buttons.push_back(Button);
}

void UserInterface::DeleteButtons() {
    Buttons.clear();
}

int UserInterface::PersonalArea() {
    string ListOfAvailable = Client::AskServer("AALL");
    cout << ListOfAvailable;
    DrawFrame(0, 0, 119, 29);
    AdvancedOutputToXY(5, 10, TurnBackGreen, Client::User.Login);


}


Button::Button(int
               x1, int
               y1, string
               Text, ::function<string(int, int, const char *, char)>
               Function) {
    this->Text = Text;
    this->x1 = x1;
    this->y1 = y1;
    gotoxy(x1, y1);
    cout << Text;
    Container = Function;
    UserInterface::AddButton(*this);
}

Button::Button(int
               x1, int
               y1, string
               Text, ::function<void(int, int)>
               Function) {
    this->Text = Text;
    this->x1 = x1;
    this->y1 = y1;
    gotoxy(x1, y1);
    cout << Text;
    Container1 = Function;
    UserInterface::AddButton(*this);
}

Button::Button(int
               x1, int
               y1, string
               Text, ::function<void()>
               Function) {
    this->Text = Text;
    this->x1 = x1;
    this->y1 = y1;
    gotoxy(x1, y1);
    cout << Text;
    Container2 = Function;
    UserInterface::AddButton(*this);
}










