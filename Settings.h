#ifndef _SETTINGS_H__
#define _SETTINGS_H__

#include <map>
#include <string>
#include <any>

class Settings {
public:
    enum COMMAND
    {
        HELP,
        WIDTH,
        HEIGHT,
        RESOLUTION,
        SCREEN_BACKGROUND,
        MESH_PROJECTION,
        SCREEN_POSITION,
        MESH_POSITION,

        COMMAND_COUNT,
    };

    Settings();
    ~Settings() = default;

    bool Init(int argc, char** argv);
    
    int GetWidth() const {return m_width;}
    int GetHeight() const {return m_height;}
    int GetMeshResolution() const {return m_resolution;}
    int GetScreenPosition() const {return m_screenPosition;}
    int GetMeshPosition() const {return m_meshPosition;}
    char GetScreenBackground() const {return m_screenBackground;}
    char GetScreenMeshProjection() const {return m_screenMeshProjection;}

private:
    void DisplayHelp();
    void SetScreenWidth(int value) {m_width = value;}
    void SetScreenHeight(int value) {m_height = value;}
    void SetScreenResolution(int value) {m_resolution = value;}
    void SetScreenPosition(int value) {m_screenPosition = value;}
    void SetMeshPosition(int value) {m_meshPosition = value;}
    void SetScreenBackground(char value) {m_screenBackground = value;}
    void SetScreenMeshProjection(char value) {m_screenMeshProjection = value;}

    bool ParseArguments(int argc, char** argv);

private:
    int m_width;
    int m_height;
    int m_resolution;
    int m_screenPosition;
    int m_meshPosition;
    char m_screenBackground;
    char m_screenMeshProjection;

    std::map<int, std::any> m_command;
    
};
#endif

