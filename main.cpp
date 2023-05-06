#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"


//SERver commands UREG UFND UDEL
//                DADD DFND DDEL
//                RES DALL UALL AALL
//
//          UFND Login%Pass%    UDEL 1      DADD BCLASS%DATA/TIME%34%NONE%
//          DFND BCLASS%DATA/TIME%34%LOGIN%
//          DDEL 12
//          RES 23 LOGIN
//          DALL
//
//

// UREG Login%Passwd%
//
int main() {
    InitializeSettings();
    Client::Initialize();


    //UserInterface::StartMenu();

    //Client::AskServer("UDEL 22");
    //Client::AskServer("DDEL 2");
    //Client::AskServer("AALL");
    //Client::AskServer("RES 4 Admin%");
    Client::AskServer("AALL");

    //Client::AskServer("REG NewLogin%NewPassw%");
    //Client::CloseConnection();
    wait;
}

