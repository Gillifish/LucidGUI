#pragma once

#include <iostream>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class App
{
protected:
    float m_width;
    float m_height;
    sf::RenderWindow m_window;
    sf::Color m_background = {0, 0, 0};
    bool m_running = true;
    sf::Clock deltaClock;

    void quit();

    void update();
    virtual void sUserInput() = 0;
    virtual void sImGui() = 0;

public:
    App(float x, float y, std::string title, float framerate);
    ~App();
    void run();

    sf::RenderWindow &window();
    bool isRunning();
};