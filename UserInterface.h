#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"


void Logic();

class Button;

class UserInterface {
private:
    vector<Button> Buttons;
    static string AdminLoggin;
    static string AdminPsswrd;
    static string ServerPsswrd;
    static string ServerLoggin;
    static vector <string> Date;
public:
    static void DrawFrame(int x1,int y1,int x2,int y2);
    static void Clear(int x1,int x2,int y1,int y2);
    static string Input(int x, int y, const char* length, char replace);

    static int LogMenu();
    static int StartMenu();
    static string DateChoice();
    static void PersonalAdminArea();

};

class Button : public UserInterface {
public:
    static void (*FuncB)();
    static void OnClick(void (*FuncA)()){
        FuncB = FuncA;
    }
    static void Executor(){
        FuncB();
    }
    static void ButtonCammon(int x, int y,WINBOOL Color,string str){};

};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
