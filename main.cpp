#include "Utility.h"
#include "Server.h"
#include "Client.h"
#include "Database.h"
#include "UserInterface.h"


int main() {


    int asnw;
    cout << "1 for client else for server" << endl;
    cin >> asnw;
    if (asnw == 1) {
        client_init();
        wait;
    } else { server_init(); wait;}




}
