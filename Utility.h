#ifndef INFO_SYSTEM_CPP_UTILITY_H
#define INFO_SYSTEM_CPP_UTILITY_H

#include <chrono>
#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cstdio>
#include <thread>
#include <functional>

#define WIN32_LEAN_AND_MEAN //wtf is that?
#define wait getch()
#define TurnRed SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)
#define TurnMagenta SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)
#define TurnYellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)
#define TurnAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3)
#define TurnBrightAqua SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)
#define TurnWhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#define TurnBlack SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0)
#define TurnGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2)
#define TurnBackGreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32)

#define VK_BKSPC   0x08
#define VK_RETURN  0x0D
#define VK_SPACE   0x20
#define VK_PRIOR	0x21
#define VK_NEXT	0x22
#define VK_END	0x23
#define VK_HOME	0x24
#define VK_LEFT	0x25
#define VK_UP	0x26
#define VK_RIGHT	0x27
#define VK_DOWN	0x28
#define VK_F11	0x7A
#define VK_F12	0x7B
#define VK_DELETE	0x2E

#define MAX_PASS   "4294967295"
#define MAX_LOGIN   "1111111111111111111111111111111111111111111111111"

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

void InitializeSettings();
void gotoxy(int x, int y);
string KeyCheck(int Key);
bool in_range(char *buff, const char *max);

void AdvancedInputToXY(int x, int y, string str = "", WINBOOL Color = TurnWhite);
void AdvancedInputToXY(int x, int y, WINBOOL Color = TRUE,  string str = "");

#endif //INFO_SYSTEM_CPP_UTILITY_H
