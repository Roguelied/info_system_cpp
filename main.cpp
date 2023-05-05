#include "Utility.h"
#include "Client.h"
#include "UserInterface.h"


//SERver commands UREG UFND UDEL
//                DADD DFND DDEL
//                RES DALL UALL
int main() {
    //InitializeSettings();

    Client::Initialize();
    //Client::AskServer("UDEL 22");
    //Client::AskServer("DDEL 2");
    //Client::AskServer("UREG ABOBA%SKRILLEX%");
    Client::AskServer("DADD DCLASS%08.05.2024/18:23%12%NONE%");

    //Client::AskServer("REG NewLogin%NewPassw%");
    Client::CloseConnection();
    wait;
}

