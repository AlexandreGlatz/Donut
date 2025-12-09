#ifndef _MESH_H__
#define _MESH_H__

#include <vector>
#include <cstdio>

class Settings;
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

    std::vector<Vertex> const& GetVertices() const {return m_vertices;}


private:
    void GenerateSector(float radius, float angle);
    std::vector<Vertex> m_vertices;
    int m_resolution;

};
#endif
