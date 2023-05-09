#include "Utility.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void InitializeSettings() {
    SetConsoleOutputCP( 65001 );
    system("title Information system prototype");
}

string KeyCheck(int Key) {
    if (Key == 'w' or Key == 'W' or Key == 230 or Key == 150) {
        return "w";
    }
    if (Key == 'a' or Key == 'A' or Key == 228 or Key == 148)  {
        return "a";
    }
    if (Key == 's' or Key == 'S' or Key == 235 or Key == 155) {
        return "s";
    }
    if (Key == 'd' or Key == 'D' or Key == 162 or Key == 130) {
        return "d";
    }
    if (Key == 13){
        return "enter";
    }
    if (Key == 'e' or Key == 'E' or Key == 227 or Key == 147) {
        return "e";
    }
    if (Key == VK_ESCAPE) {
        return "esc";
    }
    if(Key == VK_TAB){
        return "tab";
    } else {return "NONE";}
}


void AdvancedOutputToXY(int x, int y, string str, WINBOOL Color) {
    gotoxy(x, y);
    cout << str;
    TurnWhite;
}
void AdvancedOutputToXY(int x, int y, WINBOOL Color,  string str) { //overload
    AdvancedOutputToXY(x, y, str, Color);
    TurnWhite;
}
void AdvancedOutputToXY(int x, int y, WINBOOL Color,  int num) { //overload
    gotoxy(x, y);
    cout << num;
    TurnWhite;
}

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool in_range(char *buff, const char *max) {
    int lb = strlen(buff), lm = strlen(max);
    return (lb != lm) ? (lb < lm) : strcmp(max, buff) >= 0;
}
