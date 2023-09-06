#pragma once

#include "App.h"
#include "Data/AccountManager.h"

// Class for the GUI component of Lucid
class LucidGui : public App
{
    AccountManager &m_db;

    Account* m_selectedToUpdate;

    bool m_showAddWindow = false;
    bool m_showRemoveWindow = false;
    bool m_showUpdateWindow = false;
    ImGuiWindowFlags m_mainWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings;
    ImGuiWindowFlags m_addWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
    ImGuiTableFlags m_tableFlags = ImGuiTableFlags_Resizable | ImGuiTableFlags_NoSavedSettings | ImGuiTableFlags_Borders;

    // Inherited from App
    void sImGui();
    void sDoAction(const Action &action);

    // Function for registering keyboard actions
    void actionRegistry();

    // Window creation and setup
    void mainWindow();
    void addWindow();
    void removeWindow();
    void updateWindow();
    void displayData();

public:
    LucidGui(float x, float y, std::string title, float fr, AccountManager &db);
};