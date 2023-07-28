#pragma once

#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <DataManager.h>

class App
{
    float m_width;
    float m_height;
    sf::RenderWindow m_window;
    DataManager &m_db;
    sf::Color m_background = {0, 0, 0};
    bool m_running = true;
    sf::Clock deltaClock;
    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;

    void quit();

    void update();
    void sUserInput();
    void sImGui();
    void mainWindow();

public:
    App(float x, float y, std::string title, float fr, DataManager &db);
    ~App();
    void run();

    sf::RenderWindow &window();
    bool isRunning();
};