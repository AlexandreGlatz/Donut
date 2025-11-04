#include <iostream>
#ifdef _WIN32
#include <windows.h>
#define osString "Windows";
HANDLE hCondole = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD mode;
GetConsoleMode(hConsole, &mode);
SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
#if defined(__unix__) || defined(__unix)
#define osString "Linux"
#endif

int main(int argc, char** argv)
{
    std::cout<<"\033[2J";
    std::cout<<"\033[H";
    std::cout<<"\033[?25l";
    std::cout<<"Detected OS : "<<osString<<std::endl;
    std::cout<<"Hello World !"<<std::endl;
    std::cout<<"\033[?25h";
    return 0;
}
