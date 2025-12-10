#include <cmath>
#include "Mesh.h"
#include "Settings.h"

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::GenerateCircle(float radius)
{
    GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}

void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}

void Mesh::GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i<m_resolution; ++i)
    {
        float angleY = (2 * PI * i) / (m_resolution - 1);
        for(int j = 0; j<m_resolution; ++j)
        {
            float angleZ = (2 * PI * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = majorRadius + minorRadius * std::cos(angleZ);
            m_vertices[m_resolution * i + j].y = minorRadius * std::sin(angleZ);
            m_vertices[m_resolution * i + j].Rotate(angleY, Axis::Y);
        }
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for(Vertex& vertex : m_vertices)
    {
        vertex.Rotate(angle, axis);
    }

}
