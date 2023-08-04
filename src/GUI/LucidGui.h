#include "App.h"
#include <DataManager.h>

class LucidGui : public App
{
    DataManager &m_db;
    bool m_showAddWindow = false;
    bool m_showRemoveWindow = false;
    ImGuiWindowFlags m_mainWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings;
    ImGuiWindowFlags m_addWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;

    void sUserInput();
    void sImGui();
    void mainWindow();
    void addWindow();
    void removeWindow();
    void displayData();

public:
    LucidGui(float x, float y, std::string title, float fr, DataManager &db);
};