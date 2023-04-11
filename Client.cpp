#include "Client.h"


int Client::Initialize() {
    int Result;
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
}

int Client::AskServer() {

    int Result;

    while (SendBuffer[0] != '&') {

        cin >> SendBuffer;

        Result = send(ConnectSocket, SendBuffer, (int) strlen(SendBuffer), 0);
        if (Result == SOCKET_ERROR) {
            cout << "Send failed";
            closesocket(ConnectSocket);
            freeaddrinfo(addrResult);
            WSACleanup();
            return 1;
        }

        recv(ConnectSocket, recvBuffer, 512, 0);
        cout << recvBuffer << endl;
    }


    Result = shutdown(ConnectSocket, SD_SEND);
    if (Result == SOCKET_ERROR) {
        cout << "Shutdown error " << Result << endl;
        closesocket(ConnectSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return 1;
    }

    closesocket(ConnectSocket);
    freeaddrinfo(addrResult);
    WSACleanup();
    return 0;

}