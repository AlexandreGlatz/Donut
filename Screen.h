#ifndef _SCREEN_H__
#define _SCREEN_H__

#include <vector>
class Mesh;
class Settings;
class Screen {
public:
    Screen(Settings const& settings);
    ~Screen() = default;
        
    bool Display(Mesh const& mesh);
    bool Display();

private:
    bool ProjectInScreenSpace(Mesh const& mesh);

private:
    std::vector<char> m_display;
    int m_width;
    int m_height;
    int m_zPosition;
    int m_meshZPosition;
    char m_meshProjection;
};

#endif
