#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include <utility>

#include "Utility.h"


class Button;
class UserInterface {
private:

    static vector <string> Date;
    static string AdminLoggin;
    static string AdminPsswrd;
    static string ServerPsswrd;
    static string ServerLoggin;
public:
    static vector<Button> Buttons;
    static void DrawFrame(int x1,int y1,int x2,int y2);
    static void Clear(int x1,int x2,int y1,int y2);
    static string Input(int x, int y, const char* length, char replace);


    static int Press();
    static void AddButton(Button Button);
    static void DeleteButtons();
    static int SelectionMode();





    static int LogMenu();
    static void StartMenu();
    static string DateChoice();
    static void PersonalAdminArea();
};



class Button : public UserInterface {
public:
    int x1,y1,x2,y2;
    string Text;

    //string (*funcB)(int);
    function<string(int, int, const char*, char)> Container;
    function<void(int, int)> Container1;
    function<void()> Container2;

    void OnClick(function<string(int, int, const char*, char)> Function) {
        Container = Function;
    }
    void OnClick(function<void(int, int)> Function) {
        Container1 = Function;
    }
    void OnClick(function<void()> Function) {
        Container2=Function;
    }

    void Action(int x, int y, const char* length, char sym){
        Container(x, y, length, sym);
    }
    void Action(int x, int y){
        Container1(x,y);
    }
    void Action(){
        Container2();
    }
    Button(int x1, int y1, string Text, function<string(int, int, const char*, char)> Function);
    Button(int x1, int y1, string Text, function<void(int, int)> Function);
    Button(int x1, int y1, string Text, function<void()> Function);
};

void StartScreen();
void LogScreen();

#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
