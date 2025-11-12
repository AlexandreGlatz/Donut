#ifndef _SETTINGS_H__
#define _SETTINGS_H__

#include <map>
#include <string>
class Settings {
public:
    enum COMMAND
    {
        HELP,
        WIDTH,
        HEIGHT,

        COMMAND_COUNT,
    };

    Settings() = default;
    ~Settings() = default;

    bool Init(int argc, char** argv);
    
    int GetWidth() {return m_width;}
    int GetHeight() {return m_height;}


    void DisplayHelp();
    void SetScreenWidth(int value);
    void SetScreenHeight(int value);

private:
    bool ParseArguments(int argc, char** argv);

private:
    int m_width;
    int m_height;
    std::map<int, int> m_command;
    
};
#endif

