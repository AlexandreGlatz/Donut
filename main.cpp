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

constexpr float PI = 3.14159265f;
int main(int argc, char** argv)
{
    OS_FUNC;
    Settings settings;
    settings.Init(argc, argv);
    
    Screen screen(settings);

    Mesh mesh(settings);
    mesh.GenerateCircle(10);

    while(true)
    {
        
        mesh.Rotate(0.001f, Axis::Y);
        screen.Display(mesh);
    }


    return 0;
}
