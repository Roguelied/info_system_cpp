//super govnocode by notFOUND
#include "UserInterface.h"


string UserInterface::AdminPsswrd = "admin";
string UserInterface::AdminLoggin = "admin";
string UserInterface::ServerPsswrd = "server_";
string UserInterface::ServerLoggin = "server_";
vector<Button> UserInterface::Buttons = {};
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

string UserInterface::Input(int x, int y, int length, char replace) {

    char buffer[128] = {0};
    char *ptr = buffer;
    unsigned char symbol;

    char* arr[length];

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

        if (symbol >= VK_SPACE and (in_range(buffer,  *arr))) {
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
                AdvancedOutputToXY(20 , 16, TurnBackGreen, "USER");
                couter++;
            }
        } else if (KeyCheck(Key) == "enter" and couter % 2 == 0) {
            exit(666);
        }  else if ((couter+1)%2==0 and KeyCheck(Key) == "enter") {
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
                        cout << Result;

                        AdvancedOutputToXY(18,25,TurnRed,Result);
                        sleep_for(milliseconds(1000));
                        Clear(5, 18, 40, 26);
                        gotoxy(24, 16);
                        break;


                    } else {
                        stringstream StringStream(Result);
                        system("cls");
                        StringStream >> Client::User.Index ;
                        StringStream >> Client::User.Login ;
                        StringStream >> Client::User.Password ;
                        StringStream >> Client::User.ID ;
                        StringStream >> Client::User.AdminFlag;

                        if (Client::User.AdminFlag ==  "1") {
                            PersonalAdminArea();
                        } else {
                            DateChoice();
                        }
                    }

                } else if ((LoginFlag + 1) % 2 == 0 and KeyCheck(key) == "enter") {
                    Clear(42, 29, 61, 35);
                    DrawFrame(10, 29, 100, 43);
                    AdvancedOutputToXY(50, 30, TurnWhite, "REGISTRATION");
                    AdvancedOutputToXY(13, 33, "Enter your name : ");
                    AdvancedOutputToXY(13, 36, "Create password : ");
                    AdvancedOutputToXY(13, 39, "Repeat password : ");
                    for (;;) {
                        string RegLoginResult = Input(31, 33, MAX_INPUT, ' ');
                        if (RegLoginResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }//else{system("cls");}
                        string RegPassResult = Input(31, 36, MAX_INPUT, '*');
                        if (RegPassResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }
                        string RegPassCheckResult = Input(31, 39, MAX_INPUT, '*');
                        if (RegPassCheckResult == "-1") {
                            Clear(10, 29, 100, 43);
                            gotoxy(54, 27);
                            break;
                        }
                        if (RegPassResult == RegPassCheckResult) {
                            // UREG LOGIN%PAROL%
                            string Result = Client::AskServer("UREG " + RegLoginResult + "%" + RegPassCheckResult + "%");
                            cout << Result; sleep_for(milliseconds(1200));
                            if (Result == "Username is taken") {
                                AdvancedOutputToXY(50, 41, TurnRed, "THIS USERNAME IS TAKEN");
                                sleep_for(milliseconds(1200));
                                Clear(31, 33, 68, 41);
                                continue;
                            } else {
                                AdvancedOutputToXY(50, 41, TurnRed, "SUCCESSFULLY REGISTERED, TRY SIGN IN");
                                sleep_for(milliseconds(1200));
                                Clear(31, 33, 68, 41);
                                continue;
                            }

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

void UserInterface::PersonalUserArea(){

}









void UserInterface::PersonalAdminArea() {
    int selector = 7;
    DrawFrame(0, 0, 210, 53);
    AdvancedOutputToXY(175, 8, "Person Info");
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
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 4) % 6 == 0) {
            AdvancedOutputToXY(10, 21, TurnWhite, "Add User");
            AdvancedOutputToXY(10, 24, TurnBackGreen, "Delete User");
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 3) % 6 == 0) {
            AdvancedOutputToXY(10, 24, TurnWhite, "Delete User");
            AdvancedOutputToXY(10, 27, TurnBackGreen, "Add Booking");
            gotoxy(21, 27);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 2) % 6 == 0) {
            AdvancedOutputToXY(10, 27, TurnWhite, "Add Booking");
            AdvancedOutputToXY(10, 30, TurnBackGreen, "Delete Booking");
            gotoxy(24, 30);
            selector++;
        } else if (KeyCheck(Key) == "tab" and (selector + 1) % 6 == 0) {
            AdvancedOutputToXY(10, 30, TurnWhite, "Delete Booking");
            AdvancedOutputToXY(10, 33, TurnBackGreen, "Sort Database");
            gotoxy(23, 33);
            selector++;
        } else if (KeyCheck(Key) == "tab" and selector % 6 == 0) {
            AdvancedOutputToXY(10, 33, TurnWhite, "Sort Database");
            AdvancedOutputToXY(10, 18, TurnBackGreen, "Check User Info");
            selector++;
        } else if (KeyCheck(Key) == "enter" and (selector + 5) % 6 == 0) {
            DateChoice();
        } else if (KeyCheck(Key) == "enter") {
            continue;
        }
    }
}
//**********************************************************************************************************************
int UserInterface::Press() {
    return 0;
}


int UserInterface::SelectionMode() {
    int SizeVec= size (Buttons);
    int flagEBYCHIU=0;
    AdvancedOutputToXY(Buttons[flagEBYCHIU].x1,Buttons[flagEBYCHIU].y1,TurnBackGreen,Buttons[flagEBYCHIU].Text);
    for(;;){
        int Key=_getch();
        if(KeyCheck(Key)=="tab"){
            if(flagEBYCHIU!=SizeVec-1){
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1,Buttons[flagEBYCHIU].y1,TurnWhite,Buttons[flagEBYCHIU].Text);
                flagEBYCHIU++;
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1,Buttons[flagEBYCHIU].y1,TurnBackGreen,Buttons[flagEBYCHIU].Text);
            } else{
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1,Buttons[flagEBYCHIU].y1,TurnWhite,Buttons[flagEBYCHIU].Text);
                flagEBYCHIU=0;
                AdvancedOutputToXY(Buttons[flagEBYCHIU].x1,Buttons[flagEBYCHIU].y1,TurnBackGreen,Buttons[flagEBYCHIU].Text);
            }
        }if(KeyCheck(Key)=="enter" and flagEBYCHIU!=SizeVec-1){
            Buttons[flagEBYCHIU].Action();
            system("cls");
            break;
        }else if(KeyCheck(Key)=="enter" and flagEBYCHIU==SizeVec-1){
            exit(999);
        } else if (KeyCheck(Key)=="esc") {
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


Button::Button(int x1, int y1, string Text, ::function<string(int, int, const char *, char)> Function) {
    this->Text = Text;
    this->x1=x1;
    this->y1=y1;
    gotoxy(x1, y1);
    cout << Text;
    Container = Function;
    UserInterface::AddButton(*this);
}

Button::Button(int x1, int y1, string Text, ::function<void(int, int)> Function) {
    this->Text = Text;
    this->x1=x1;
    this->y1=y1;
    gotoxy(x1, y1);
    cout << Text;
    Container1 = Function;
    UserInterface::AddButton(*this);
}

Button::Button(int x1, int y1, string Text, ::function<void()> Function) {
    this->Text = Text;
    this->x1=x1;
    this->y1=y1;
    gotoxy(x1, y1);
    cout << Text;
    Container2 = Function;
    UserInterface::AddButton(*this);
}









