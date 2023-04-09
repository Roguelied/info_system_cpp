#ifndef INFO_SYSTEM_CPP_UTILITY_H
#define INFO_SYSTEM_CPP_UTILITY_H

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include <string>
#include <vector>

#define TurnLightRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)
#define TurnMagenta SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)
#define TurnYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)
#define TurnAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3)
#define TurnBrightAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)
#define TurnWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#define TurnBlack SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0)
#define TurnBackGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32)

using namespace std;


void wait();
void InitializeSettings();
void gotoxy(int x, int y);
string KeyCheck(int Key);










#endif //INFO_SYSTEM_CPP_UTILITY_H
