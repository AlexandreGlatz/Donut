#include "Screen.h"
#include <iostream>

bool Screen::Init(int width, int height)
{
   m_width = width;
   m_height = height;

   return true;
}

bool Screen::Display()
{
    for(int i = 0; i<m_width; ++i)
    {
        for(int j = 0; j<m_height; ++j)
        {
            std::cout<<".";
        }
        std::cout<<std::endl;
    }
    return true;
}
