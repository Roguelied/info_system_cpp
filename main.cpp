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
    UserInterface::StartMenu();
    //"17    ACLASS    09.11.2023/18:15    32    NONE
    //17    ACLASS    09.11.2023/18:15    32    NONE
    //17    ACLASS    09.11.2023/18:15    32    NONE"

//    stringstream ss(i);
//
//    struct Reservation {
//        string index;
//    };
//
//    AskServer("RES " + index;)
//    Reservation Reservation;
//    ss >> index;




    //cout<<Client::AskServer("DFFR Admin%");

    //cout << Client::AskServer("AALL");
    //UserInterface::PersonalArea();

    //cout << Client::AskServer("DALL"); //NOTFOUND //creds //WRONGPASS
    //Client::AskServer("REG NewLogin%NewPassw%");
    //Client::CloseConnection();
    //InitializeSettings();
    //UserInterface::StartMenu();
    wait;
}

