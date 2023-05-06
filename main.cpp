#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"


//SERver commands UREG UFND UDEL
//                DADD DFND DDEL
//                RES DALL UALL AALL

// UREG Login%Passwd%
//
int main() {
    InitializeSettings();
    Client::Initialize();


    UserInterface::StartMenu();

    //Client::AskServer("UDEL 22");
    //Client::AskServer("DDEL 2");
    //Client::AskServer("AALL");
    //Client::AskServer("RES 4 Admin%");
    //Client::AskServer("DALL");

    //Client::AskServer("REG NewLogin%NewPassw%");
    //Client::CloseConnection();
    wait;
}

