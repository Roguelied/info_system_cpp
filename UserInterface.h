#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"

class UserInterface {
private:
    char AdminPassword[5] = {'a', 'd', 'm', 'i', 'n'};
    int Selector;
public:
    void DrawFrame(int x1,int y1,int x2,int y2);
    bool in_range(char* buff, const char* max);
    int StartMenu();
    int LogMenu();
    int ADMINInputPassword(char* buffer);
    int USERInputReg(char *Loggin,char *Password);
    void clearWINDOW(int x1,int x2,int y1,int y2);
    int USERchoise();

};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
