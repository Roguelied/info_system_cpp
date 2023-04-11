#ifndef INFO_SYSTEM_CPP_CLIENT_H
#define INFO_SYSTEM_CPP_CLIENT_H

#include "Utility.h"


class Client {
private:
    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ConnectSocket = INVALID_SOCKET;

    char SendBuffer[20];
    char recvBuffer[512];
public:

    int Initialize();
    int AskServer();

};



#endif //INFO_SYSTEM_CPP_CLIENT_H
