#pragma once

#include "App.h"
#include <AccountManager.h>

class LucidGui : public App
{
    AccountManager &m_db;
    bool m_showAddWindow = false;
    bool m_showRemoveWindow = false;
    ImGuiWindowFlags m_mainWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings;
    ImGuiWindowFlags m_addWindowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;

    // Inherited from App
    void sImGui();
    void sDoAction(const Action &action);

    // Function for registering keyboard actions
    void actionRegistry();

    // Window creation and setup
    void mainWindow();
    void addWindow();
    void removeWindow();
    void displayData();

public:
    LucidGui(float x, float y, std::string title, float fr, AccountManager &db);
};