#ifndef _MESH_H__
#define _MESH_H__

#include <vector>
#include <cstdio>
#include <cmath>
#include <iostream>
class Settings;

enum class Axis {
    X,
    Y,
    Z,
};
struct Vertex {
    float x;
    float y;
    float z;

    Vertex()
    {
        x = 0, y = 0, z = 0;
    }
    Vertex(int px, int py, int pz)
    {
        x = px, y = py, z = pz;
    }
    void Debug() const
    {
        std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n", x,y,z);
    }
    void Rotate(float angle, Axis axis)
    {
        Vertex original = *this;
        switch(axis)
        {
        case Axis::X:
            y = original.y * std::cos(angle) - original.z * std::sin(angle);
            z = original.y * std::sin(angle) + original.z * std::sin(angle);
            break;
        case Axis::Y:
            x = original.x * std::cos(angle) + original.z * std::sin(angle);
            z = original.x * -std::sin(angle) + original.z * std::cos(angle); 
            break;
        case Axis::Z:
            x = original.x * std::cos(angle) - original.y * std::sin(angle);
            y = original.x * std::sin(angle) + original.y * std::cos(angle);
            break;
        }
    }
};

class Mesh {
public:
    Mesh() = default;
    Mesh(Settings const& settings);
    ~Mesh() = default;

    bool Init(int resolution);
    void Debug() const;
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float size);
    void Rotate(float angle, Axis axis);

    std::vector<Vertex> const& GetVertices() const {return m_vertices;}


private:
    void GenerateSector(float radius, float angle);
    std::vector<Vertex> m_vertices;
    int m_resolution;

};
#endif
