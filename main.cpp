#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
#include <windows.h>
#define osString "Windows"
#define OS_FUNC HANDLE hCondole = GetStdHandle(STD_OUTPUT_HANDLE);\
        DWORD mode;\
        GetConsoleMode(hConsole, &mode);\
        SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);\

#endif
#if defined(__unix__) || defined(__unix) || defined(__unix__)
#define osString "Linux"
#define OS_FUNC
#endif

#include <iostream>
#include <vector>
int main(int argc, char** argv)
{
    OS_FUNC;
    std::vector<char> vect;
    std::cout<<"\033[2J";
    std::cout<<"\033[H";
    std::cout<<"OS Detected : "<< osString <<std::endl;
    std::cout<<"\033[?25l";
    std::cout<<"\033[?25h";
    return 0;
}
