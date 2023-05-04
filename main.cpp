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
    //InitializeSettings();
    Client::Initialize();
    Client::AskServer("DEL 22");
    Client::AskServer("DEL 44");
    Client::AskServer("FND LoginTest%PassTest%");
    Client::AskServer("REG NewLogin%NewPassw%");
    Client::CloseConnection();
    wait;
}

