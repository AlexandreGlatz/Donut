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
    
    int width = 100;
    int height = 20;

    std::vector<char> screen;
    std::fill(screen.begin(), screen.end(), '.');
    
    for(int i = 0; i<width; ++i)
    {
        for(int j = 0; j<height; ++j)
            std::cout<<screen[i];

        std::cout<<std::endl;
    }
    return 0;
}
