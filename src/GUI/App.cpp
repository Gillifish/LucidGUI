#include "App.h"

App::App(float x, float y, std::string title, float fr) : m_width(x),
                                                          m_height(y)
{
    m_window.create(sf::VideoMode(m_width, m_height), title);
    m_window.setFramerateLimit(fr);
    ImGui::SFML::Init(m_window);
}

void App::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed)
        {
            quit();
        }
    }
}

void App::sImGui()
{
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height)); // Set to zero to fit the entire window
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    ImGui::Begin("Fullscreen Window", nullptr, windowFlags);
    ImGui::End();
}

void App::update()
{
    ImGui::SFML::Update(m_window, deltaClock.restart());
    sUserInput();
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