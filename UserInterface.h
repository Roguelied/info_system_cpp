#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include <utility>

#include "Utility.h"


class Button;

class UserInterface {
private:
    static vector<Button> Buttons;
    static string AdminLoggin;
    static string AdminPsswrd;
    static string ServerPsswrd;
    static string ServerLoggin;

    static vector <string> Date;
public:
    static void DrawFrame(int x1,int y1,int x2,int y2);
    static void Clear(int x1,int x2,int y1,int y2);
    static string Input(int x, int y, const char* length, char replace);

    static void AddButton(Button Button);

    static void SelectionMode();

    static int LogMenu();
    static int StartMenu();
    static string DateChoice();
    static void PersonalAdminArea();

};



class Button : public UserInterface {
private:
    int x1, y1, x2, y2;

public:
    //string (*funcB)(int);
    function<string(int, int, const char*, char)> Container;



    void OnClick(function<string(int, int, const char*, char)> Function) {
        Container = Function;
    }

    void Action(int x, int y, const char* length, char sym){
        Container(x, y, length, sym);
    }


    Button(int x1, int y1, int x2, int y2, function<string(int, int, const char*, char)> Function);

    //~Button();

};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
