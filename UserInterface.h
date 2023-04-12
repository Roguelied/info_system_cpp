#ifndef INFO_SYSTEM_CPP_USERINTERFACE_H
#define INFO_SYSTEM_CPP_USERINTERFACE_H

#include "Utility.h"

class UserInterface {
private:
    char AdminPassword[5] = {'a', 'd', 'm', 'i', 'n'};
    int Selector;
public:
    bool in_range(char* buff, const char* max);
    int StartMenu();
    int LogMenu();
    int InputPassword(char* buffer);


};


#endif //INFO_SYSTEM_CPP_USERINTERFACE_H
