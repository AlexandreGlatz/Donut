#include "Settings.h"
#include <string.h>
#include <iostream>


bool Settings::Init(int argc, char **argv)
{

    if(argc > COMMAND_COUNT * 2)
        return false;

    bool ret = ParseArguments(argc, argv);
    if(ret == false)
        return false;
    
    for(auto const&  [key, val] : m_command)
    {
        switch(key)
        {
        case HELP:
            DisplayHelp();
            break;
        case HEIGHT:
            SetScreenHeight(val);
            break;
        case WIDTH:
            SetScreenWidth(val);
            break;
        }

    }
    return true;
}

bool Settings::ParseArguments(int argc, char** argv)
{
    for(int i = 1; i<argc - 1; ++i)
    {
        if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0)
        {
            m_command[HELP] = 0;   
        }
        if(strcmp(argv[i], "-g") == 0 || strcmp(argv[i],"--height") == 0)
        {
            if(i + 1 > argc)
                return false;

            m_command[HEIGHT] = atoi(argv[i + 1]);
            i++;
        }
        if(strcmp(argv[i], "-w") == 0 || strcmp(argv[i],"--width") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[WIDTH] = atoi(argv[i + 1]);
            i++;
        }
    }
    return true;
}

void Settings::DisplayHelp()
{
    std::cout<<"Help"<<std::endl;
    std::cout<<"------"<<std::endl;
    std::cout<<"-h --help : display this message"<<std::endl;
    std::cout<<"-g --height : sets screen height"<<std::endl;
    std::cout<<"-w --width : sets screen width"<<std::endl;
    std::cout<<"------"<<std::endl;
}

void Settings::SetScreenHeight(int value)
{
    m_height = value;
}

void Settings::SetScreenWidth(int value)
{
    m_width = value;
}
