#include "Settings.h"
#include <string.h>
#include <iostream>


Settings::Settings():
    m_width(100),
    m_height(50),
    m_resolution(32),
    m_screenBackground(' '),
    m_screenMeshProjection('X'),
    m_screenPosition(9),
    m_meshPosition(5)
{
}

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
            SetScreenHeight(std::any_cast<int>(val));
            break;
        case WIDTH:
            SetScreenWidth(std::any_cast<int>(val));
            break;
        case RESOLUTION:
            SetScreenResolution(std::any_cast<int>(val));
            break;
        case SCREEN_BACKGROUND:
            SetScreenBackground(std::any_cast<char>(val));
            break;
        case MESH_PROJECTION:
            SetScreenMeshProjection(std::any_cast<char>(val));
            break;
        case SCREEN_POSITION:
            SetScreenPosition(std::any_cast<int>(val));
            break;
        case MESH_POSITION:
            SetMeshPosition(std::any_cast<int>(val));
        }

    }
    return true;
}

bool Settings::ParseArguments(int argc, char** argv)
{
    for(int i = 1; i<argc; ++i)
    {
        if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0)
        {
            m_command[HELP] = 0;   
            i++;
        }
        else if(strcmp(argv[i], "-g") == 0 || strcmp(argv[i],"--height") == 0)
        {
            if(i + 1 > argc)
                return false;

            m_command[HEIGHT] = atoi(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-w") == 0 || strcmp(argv[i],"--width") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[WIDTH] = atoi(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-r") == 0 || strcmp(argv[i],"--resolution") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[RESOLUTION] = atoi(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-b") == 0 || strcmp(argv[i],"--background") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[SCREEN_BACKGROUND] = *(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-p") == 0 || strcmp(argv[i],"--meshproj") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[MESH_PROJECTION] = *(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-s") == 0 || strcmp(argv[i],"--screenpos") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[SCREEN_POSITION] = atoi(argv[i + 1]);
            i++;
        }
        else if(strcmp(argv[i], "-m") == 0 || strcmp(argv[i],"--meshpos") == 0)
        {
            if(i + 1 > argc)
                return false;
            
            m_command[MESH_POSITION] = atoi(argv[i + 1]);
            i++;
        }
        else
        {
            std::cout<<argv[i]<<" is not a command use -h or --help for help"<<std::endl;
            exit(1);
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
    std::cout<<"-r --resolution : sets screen resolution"<<std::endl;
    std::cout<<"------"<<std::endl;
    exit(1);
}

