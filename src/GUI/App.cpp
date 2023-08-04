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