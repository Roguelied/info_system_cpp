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
    //Client::Initialize();


    UserInterface::PersonalArea();

    //cout << Client::AskServer("DALL"); //NOTFOUND //creds //WRONGPASS
    //Client::AskServer("REG NewLogin%NewPassw%");
    //Client::CloseConnection();
    wait;
}

