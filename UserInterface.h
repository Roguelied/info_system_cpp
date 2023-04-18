#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"

class UserInterface {
private:
    static string AdminPsswrd;
    static vector <string> Date;
public:
    static void DrawFrame(int x1,int y1,int x2,int y2);
    static void Clear(int x1,int x2,int y1,int y2);
    static int AdminChoice();
    static string Input(int x, int y, const char* length, char replace);




    static int LogMenu();

    static int StartMenu();
    static void MainMenu();

};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
