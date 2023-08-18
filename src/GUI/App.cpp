#include "App.h"

// Constructor that takes in two floats for desired window height, a string for title, and float for framerate
App::App(float x, float y, std::string title, float framerate) : m_width(x),
                                                          m_height(y)
{
    m_window.create(sf::VideoMode(m_width, m_height), title);
    m_window.setFramerateLimit(framerate);
    ImGui::SFML::Init(m_window);
}

// Update function that is ran every frame
void App::update()
{
    sUserInput();

    // MUST BE AFTER INPUT IS PROCESSED
    ImGui::SFML::Update(m_window, deltaClock.restart());
    sImGui();
}

// Handles all user actions which are defined in the ActionMap
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

// Main update loop for window
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

// Quits the app
void App::quit()
{
    m_running = false;
}

// Returns the window object
sf::RenderWindow &App::window()
{
    return m_window;
}

// Returns if the window is open or the m_running variable is true
bool App::isRunning()
{
    return m_running & m_window.isOpen();
}

// Deconstructor for cleanup
App::~App()
{
    ImGui::SFML::Shutdown();
}

// Function for registering window actions
void App::registerAction(int inputKey, const std::string &actionName)
{
    m_actionMap[inputKey] = actionName;
}

// Returns the ActionMap
const ActionMap &App::getActionMap() const
{
    return m_actionMap;
}