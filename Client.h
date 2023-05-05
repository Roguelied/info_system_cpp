#ifndef INFO_SYSTEM_CPP_CLIENT_H
#define INFO_SYSTEM_CPP_CLIENT_H

#include "Utility.h"


class Client {
private:
    static WSADATA wsaData;
    static ADDRINFO hints;
    static ADDRINFO* addrResult;
    static SOCKET ConnectSocket;

    static char SendBuffer[64];
    static char recvBuffer[2048];
public:

    static int Initialize();
    static int AskServer(string Command);
    static int CloseConnection();
};



#endif //INFO_SYSTEM_CPP_CLIENT_H
