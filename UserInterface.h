#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"

class UserInterface {
private:
    string AdminPsswrd="admin";
    int Selector;
public:
    void DrawFrame(int x1,int y1,int x2,int y2);
    static void Clear(int x1,int x2,int y1,int y2);
    int AdminChoice();
    string Input(int x, int y, const char* length, char replace);
    int LogMenu();




    int StartMenu();
    void MainMenu();

};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
