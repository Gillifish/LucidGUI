#pragma once

#include <iostream>
#include <map>

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <Action.h>

typedef std::map<int, std::string> ActionMap;

class App
{
protected:
    float m_width;
    float m_height;
    sf::RenderWindow m_window;
    ActionMap m_actionMap;
    sf::Color m_background = {0, 0, 0};
    bool m_running = true;
    sf::Clock deltaClock;

    void quit();

    void update();
    void sUserInput();
    virtual void sDoAction(const Action &action) = 0;
    virtual void sImGui() = 0;

public:
    App(float x, float y, std::string title, float framerate);
    ~App();
    void run();

    void registerAction(int inputKey, const std::string &actionName);

    const ActionMap &getActionMap() const;
    sf::RenderWindow &window();
    bool isRunning();
};