#include "App.h"

App::App(float x, float y, std::string title, float framerate) : m_width(x),
                                                          m_height(y)
{
    m_window.create(sf::VideoMode(m_width, m_height), title);
    m_window.setFramerateLimit(framerate);
    ImGui::SFML::Init(m_window);
}

void App::update()
{
    sUserInput();

    // MUST BE AFTER INPUT IS PROCESSED
    ImGui::SFML::Update(m_window, deltaClock.restart());
    sImGui();
}

void App::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // Careful not to input this twice
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed)
        {
            quit();
        }

        if (event.type == sf::Event::Resized)
        {
            m_width = event.size.width;
            m_height = event.size.height;
        }

        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
        {
            // if the current scene does not have an action associated with this key, skip the event
            if (getActionMap().find(event.key.code) == getActionMap().end()) { continue; }

            // determine start or end action by whether it was key press or release
            const std::string actionType = (event.type == sf::Event::KeyPressed) ? "START" : "END";

            // look up the action and send the action to the scene
            sDoAction(Action(getActionMap().at(event.key.code), actionType));
        }
    }
}

void App::run()
{
    while (isRunning())
    {
        m_window.clear(m_background);
        update();
        ImGui::SFML::Render(m_window);
        m_window.display();
    }
}

void App::quit()
{
    m_running = false;
}

sf::RenderWindow &App::window()
{
    return m_window;
}

bool App::isRunning()
{
    return m_running & m_window.isOpen();
}

App::~App()
{
    ImGui::SFML::Shutdown();
}

void App::registerAction(int inputKey, const std::string &actionName)
{
    m_actionMap[inputKey] = actionName;
}

const ActionMap &App::getActionMap() const
{
    return m_actionMap;
}