#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include "Server.h"
#include "Client.h"

using namespace std;

int main() {


    int asnw;
    cout << "1 for client else for server" << endl;
    cin >> asnw;
    if (asnw == 1) {
        client_init();
    } else { server_init(); }




}
