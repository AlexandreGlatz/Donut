#include "Screen.h"
#include "Mesh.h"
#include "Settings.h"
#include <cmath>
#include <iostream>

Screen::Screen(Settings const& settings):
    m_width(settings.GetWidth()),
    m_height(settings.GetHeight()),
    m_zPosition(settings.GetScreenPosition()),
    m_meshZPosition(settings.GetMeshPosition()),
    m_meshProjection(settings.GetScreenMeshProjection()),
    m_display(100 * 50, settings.GetScreenBackground())
{
}
bool Screen::Display(Mesh const& mesh)
{
    ProjectInScreenSpace(mesh);
    Display();
    return true;
}

bool Screen::Display()
{
    std::cout<<"\x1B[H\x1B[2J"<<std::endl;
    for(int i = 0; i<m_height; ++i)
    {
        for(int j = 0; j<m_width; ++j)
        {
            std::cout<<m_display[m_width * i + j];
        }
        std::cout<<std::endl;
    }
    return true;
}

bool Screen::ProjectInScreenSpace(Mesh const& mesh)
{
    std::fill(m_display.begin(), m_display.end(), '.');
    for(Vertex vertex : mesh.GetVertices())
    {
        vertex.z += m_meshZPosition;
        vertex.x = vertex.x/vertex.z * m_zPosition;
        vertex.y = vertex.y/vertex.z * m_zPosition / 2.f;

        vertex.x += m_width/2;
        vertex.y += m_height/2;

        int u = std::round(vertex.x);
        int v = std::round(vertex.y);

        if(u>=0 && u<m_width && v>=0 && v<m_height)
        {
            m_display[m_width * v + u] = m_meshProjection;
        }
    }

    return true;

}
