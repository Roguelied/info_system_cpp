#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"


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
private:
    vector<void*> Functions;
public:
    Button(int x1, int y1, int x2, int y2) {
    }




};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
