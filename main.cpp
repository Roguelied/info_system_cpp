#include "Utility.h"
#include "Server.h"
#include "Client.h"
#include "Database.h"
#include "UserInterface.h"



int main() {
    InitializeSettings();

    UserInterface A;
    A.StartMenu();
    A.MainMenu();
    wait;
    
   /* int asnw;
    cout << "1 for client else for server" << endl;
    cin >> asnw;
    if (asnw == 1) {
        client_init();
        wait;
    } else { server_init(); wait;}
    
   Booking Booking;
   Booking.SaveCustomer(Booking); */

}


//    int asnw;
//    cout << "1 for client else for server" << endl;
//    cin >> asnw;
//    if (asnw == 1) {
//        client_init();
//        wait;
//    } else { server_init(); wait;}}
