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
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

int main(int argc, char** argv)
{
    OS_FUNC;
    Settings settings;
    settings.Init(argc, argv);
    
    Screen screen(settings);

    Mesh mesh(settings);
    mesh.GenerateCircle(5);

    screen.Display(mesh);
    mesh.GenerateCircle(5);
    screen.Display(mesh);
    mesh.GenerateSquare(5);
    screen.Display(mesh);

    return 0;
}
