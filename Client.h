#ifndef INFO_SYSTEM_CPP_CLIENT_H
#define INFO_SYSTEM_CPP_CLIENT_H

#include "Utility.h"


typedef struct User {
    string Index;
    string Login;
    string Password;
    string ID;
    string AdminFlag;
} User;

class Client {
private:
    static WSADATA wsaData;
    static ADDRINFO hints;
    static ADDRINFO* addrResult;
    static SOCKET ConnectSocket;

    static char SendBuffer[512];
    static char recvBuffer[2048];
public:
    static User User;
    static int Initialize();
    static string AskServer(string Command);
    static int CloseConnection();
};



#endif //INFO_SYSTEM_CPP_CLIENT_H
