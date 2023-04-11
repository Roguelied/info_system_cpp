#ifndef INFO_SYSTEM_CPP_SERVER_H
#define INFO_SYSTEM_CPP_SERVER_H

#include "Utility.h"


class Server {
private:
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;

    char SendBuffer[512] = "ServerInfo";
    char recvBuffer[512];

public:

    int Initialize();
    int Listen();

};


#endif //INFO_SYSTEM_CPP_SERVER_H
