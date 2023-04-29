#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"


void  printKek1(){
    cout << "Hello\n";
}

string jopa(int x) {
    cout << "123";
    return "123";
}

int main() {
    InitializeSettings();
    Button btn1(10, 10, 20, 20, UserInterface::Input);
    btn1.Action(11, 11, MAX_LOGIN, '*');
    wait;
}

