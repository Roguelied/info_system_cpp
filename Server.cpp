#include "Server.h"

#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;

int server_init() {

    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ClientSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;
    int Result;

    const char* SendBuffer = "Hello from Server";

    char recvBuffer[512];

    //инит сокетов
    Result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (Result != 0) {
        cout << "WSAStartup failed";
        return 1;
    }


    //хинты
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET; //семейтво протоколов //ipv4 ethernet
    hints.ai_socktype = SOCK_STREAM; //тип сокета
    hints.ai_protocol = IPPROTO_TCP; //tcp протокол
    hints.ai_flags = AI_PASSIVE;


    //инит адреса
    Result = getaddrinfo(NULL, "666", &hints, &addrResult);
    if (Result != 0) {
        cout << "GetAddrInfo failed";
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    ListenSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);

    if (ListenSocket == INVALID_SOCKET) {
        cout << "Socket creation failed";
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    Result = bind(ListenSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);

    if (Result == SOCKET_ERROR) {
        cout << "Bind socket failed";
        closesocket(ListenSocket);
        ListenSocket  = INVALID_SOCKET;
        freeaddrinfo(addrResult);
        WSACleanup();
        return 0;
    }


    Result = listen(ListenSocket, SOMAXCONN);
    if (Result == SOCKET_ERROR) {
        cout << "Listening socket failed" << endl;
        closesocket(ListenSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        cout << "Accepting socket failed" << endl;
        closesocket(ListenSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    closesocket(ListenSocket);

    do {
        ZeroMemory(recvBuffer, 512);
        Result = recv(ClientSocket, recvBuffer, 512, 0);
        if (Result > 0) {
            cout << "Recieved " << Result << " bytes" << endl;
            cout << "Recieved data " << recvBuffer << endl;

            Result = send(ClientSocket, SendBuffer, (int)strlen(SendBuffer), 0);
            if (Result == SOCKET_ERROR) {
                cout << "Failed to send data back" << endl;
                closesocket(ClientSocket);
                freeaddrinfo(addrResult);
                WSACleanup();
                return 1;
            }
        } else if (Result == 0) {
            cout << "Connection closing...";
        } else if (Result < 0) {
            cout << "recv failed with error";
            closesocket(ClientSocket);
            freeaddrinfo(addrResult);
            WSACleanup();
            return 1;
        }
    } while (Result > 0);

    Result = shutdown(ClientSocket, SD_SEND);
    if (Result == SOCKET_ERROR) {
        cout << "shutdown client socket failed" << endl;
        closesocket(ClientSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }
    closesocket(ClientSocket);
    freeaddrinfo(addrResult);
    WSACleanup();
    return 0;
}