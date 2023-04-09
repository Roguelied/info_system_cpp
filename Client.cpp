#include "Client.h"
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>

using namespace std;


int client_init() {

    WSADATA wsaData;
    ADDRINFO hints;
    ADDRINFO* addrResult = NULL;
    SOCKET ConnectSocket = INVALID_SOCKET;
    int Result;

    const char* SendBuffer = "Hello from Client";

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


    //инит адреса
    Result = getaddrinfo("localhost", "666", &hints, &addrResult);
    if (Result != 0) {
        cout << "GetAddrInfo failed";
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    ConnectSocket = socket(addrResult->ai_family, addrResult->ai_socktype, addrResult->ai_protocol);

    if (ConnectSocket == INVALID_SOCKET) {
        cout << "Socket creation failed";
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    Result = connect(ConnectSocket, addrResult->ai_addr, (int)addrResult->ai_addrlen);

    if (Result == SOCKET_ERROR) {
        cout << "Unable connect to server";
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
        freeaddrinfo(addrResult);
        WSACleanup();
        return 0;
    }

    //возвращает коилчество переданных данных либо сокет ерор
    Result = send(ConnectSocket, SendBuffer, (int)strlen(SendBuffer), 0 );
    if (Result == SOCKET_ERROR) {
        cout << "Send failed";
        closesocket(ConnectSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    cout << "Sent: " << Result << " bytes" << endl;

    Result = shutdown(ConnectSocket, SD_SEND);
    if (Result == SOCKET_ERROR) {
        cout << "Shutdown error " << Result << endl;
        closesocket(ConnectSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }


    do {
        ZeroMemory(recvBuffer, 512);
        Result = recv(ConnectSocket, recvBuffer, 512, 0);
        if (Result > 0) {
            cout << "Recieved " << Result << " bytes" << endl;
            cout << "Recieved data " << recvBuffer << endl;
        } else if (Result == 0) {
            cout << "Connection closed";
        } else if (Result < 0) {
            cout << "recv failed with error";
        }
    } while (Result > 0);

    closesocket(ConnectSocket);
    freeaddrinfo(addrResult);
    WSACleanup();
    int a;
    cin >> a;
    return 0;
}