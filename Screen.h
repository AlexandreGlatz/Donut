#ifndef _SCREEN_H__
#define _SCREEN_H__

#include <vector>
class Screen {
public:
    Screen() = default;
    ~Screen() = default;
        
    bool Init();
    bool Display();

private:
    std::vector<char> m_display;
    int m_width;
    int m_height;
};

#endif
