#include "Client.h"

WSADATA Client::wsaData;
ADDRINFO Client::hints;
ADDRINFO* Client::addrResult = NULL;
SOCKET Client::ConnectSocket = INVALID_SOCKET;
char Client::SendBuffer[64];
char Client::recvBuffer[2048];

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

    for (int Counter = 0; Counter < 5; Counter++) {
        Result = connect(ConnectSocket, addrResult->ai_addr, (int) addrResult->ai_addrlen);
        if (Result != SOCKET_ERROR) break;
        if (Result == SOCKET_ERROR) {
            cout << "Trying to connect...\n";
            sleep_for(seconds(2));
            continue;
        } if (Counter == 4) {
            cout << "Unable connect to server";
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            freeaddrinfo(addrResult);
            WSACleanup();
            return 0;
        }
    }

}

string Client::AskServer(string Command) {
    int Result;

    //clear the buffer
    for (int i = 0; i < (int) strlen(SendBuffer); i++) {
        SendBuffer[i] = ' ';
    }
    //send buffer string command
    for (int i = 0; i < Command.length(); i++) {
        SendBuffer[i] = Command[i];
    }

    //send command to server
    Result = send(ConnectSocket, SendBuffer, (int) strlen(SendBuffer), 0);
    if (Result == SOCKET_ERROR) {
        //cout << "Send failed";
        closesocket(ConnectSocket);
        freeaddrinfo(addrResult);
        WSACleanup();
        return "SOCKET_ERROR";
    }

    //receive server answer
    recv(ConnectSocket, recvBuffer, 512, 0);

    if (strcmp(recvBuffer, "LISTEN_TO_ME") == 0) {
        int Index;
        string Buffer;
        cout << recvBuffer << endl;
        recv(ConnectSocket, recvBuffer, 512, 0);
        Index = atoi(recvBuffer);
        cout << Index << endl;

        recv(ConnectSocket, recvBuffer, 512, 0);
        Buffer = recvBuffer;
        return Buffer;
    }

    cout << recvBuffer << endl;
}

int Client::CloseConnection() {
    //shutdown connection and close socket
    int Result = shutdown(ConnectSocket, SD_SEND);
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
