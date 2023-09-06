#include "LucidGui.h"

// Contructor which takes two floats x and y for the dimensions of the window, string for title, float for framerate and
//      a reference to the AccountManager database
LucidGui::LucidGui(float x, float y, std::string title, float fr, AccountManager &db)
    : App(x, y, title, fr),
      m_db(db)
{
    actionRegistry();

    LucidGui::run();
}

// Function for registering keyboard actions to the window
void LucidGui::actionRegistry()
{
    registerAction(sf::Keyboard::W, "UP");
}

// Function for setting up all ImGui GUI components
void LucidGui::sImGui()
{
    ImGui::SetNextWindowSize(ImVec2(m_width, m_height)); // Set to zero to fit the entire window
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    mainWindow();

    if (m_showAddWindow)
    {
        addWindow();
    }

    if (m_showRemoveWindow)
    {
        removeWindow();
    }

    if (m_showUpdateWindow)
    {
        updateWindow();
    }
}

// ImGui window for adding accounts to the DB
void LucidGui::addWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 125));

    ImGui::Begin("Add", nullptr, m_addWindowFlags);

    static char accName[25] = "";
    static char username[25] = "";
    static char password[25] = "";

    ImGui::InputText("Account Name", accName, IM_ARRAYSIZE(accName));
    ImGui::InputText("Username", username, IM_ARRAYSIZE(username));
    ImGui::InputText("Password", password, IM_ARRAYSIZE(password));

    if (ImGui::Button("Add"))
    {
        Account acc;
        acc.tag = accName;
        acc.username = username;
        acc.password = password;

        m_db.add(acc);

        accName[0] = '\0';
        username[0] = '\0';
        password[0] = '\0';
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel"))
    {
        accName[0] = '\0';
        username[0] = '\0';
        password[0] = '\0';

        m_showAddWindow = false;
    }

    ImGui::End();
}

// ImGui window for removing accounts from the DB
void LucidGui::removeWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 125));

    ImGui::Begin("Remove", nullptr, m_addWindowFlags);

    static char accName[25] = "";
    static char username[25] = "";
    static char password[25] = "";

    ImGui::InputText("Account Name", accName, IM_ARRAYSIZE(accName));
    ImGui::InputText("Username", username, IM_ARRAYSIZE(username));
    ImGui::InputText("Password", password, IM_ARRAYSIZE(password));

    if (ImGui::Button("Remove"))
    {
        Account acc;
        acc.tag = accName;
        acc.username = username;
        acc.password = password;

        m_db.remove(acc);

        accName[0] = '\0';
        username[0] = '\0';
        password[0] = '\0';
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel"))
    {
        accName[0] = '\0';
        username[0] = '\0';
        password[0] = '\0';

        m_showRemoveWindow = false;
    }

    ImGui::End();
}

void LucidGui::updateWindow()
{
    ImGui::SetNextWindowSize(ImVec2(300, 80));

    ImGui::Begin("Update Password", nullptr, m_addWindowFlags);

    static char passwordUpdate[25] = "";

    ImGui::InputText("Password", passwordUpdate, IM_ARRAYSIZE(passwordUpdate));

    if (ImGui::Button("Update"))
    {
        m_selectedToUpdate->password = passwordUpdate;
        m_db.saveToFile();
    }

    ImGui::SameLine();

    if (ImGui::Button("Cancel"))
    {
        passwordUpdate[0] = '\0';

        m_showUpdateWindow = false;
    }

    ImGui::End();
}

// ImGui window for showing all data in the DB
void LucidGui::mainWindow()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {

            if (ImGui::MenuItem("Add"))
            {
                m_showAddWindow = true;
            }

            if (ImGui::MenuItem("Create Backup"))
            {
                m_db.createBackup();
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Remove"))
            {
                m_showRemoveWindow = true;
            }
            else if (ImGui::MenuItem("Update"))
            {
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }

    ImGui::Separator();

    ImGui::SetNextWindowSize(ImVec2(m_width, m_height - 19));
    ImGui::SetNextWindowPos(ImVec2(0, 19));

    ImGui::Begin("MainWindow", nullptr, m_mainWindowFlags);

    displayData();

    ImGui::End();
}

// ImGui code for setting up table for displaying data
void LucidGui::displayData()
{
    if (ImGui::BeginTable("Data", 3, m_tableFlags))
    {
        ImGui::TableSetupColumn("Account Name");
        ImGui::TableSetupColumn("User");
        ImGui::TableSetupColumn("Password");
        ImGui::TableHeadersRow();

        for (auto& acc : m_db.data())
        {
            ImGui::TableNextColumn();
            if (ImGui::Selectable(acc.tag.c_str()))
            {
                m_selectedToUpdate = &acc;
                if (m_showUpdateWindow)
                {
                    m_showUpdateWindow = false;
                } 
                else
                {
                    m_showUpdateWindow = true;
                }
            }

            ImGui::TableNextColumn();
            if (ImGui::Selectable(acc.username.c_str()))
            {
                ImGui::SetClipboardText(acc.username.c_str());
            }

            ImGui::TableNextColumn();
            if (ImGui::Selectable(acc.password.c_str()))
            {
                ImGui::SetClipboardText(acc.password.c_str());
            }
        }

        ImGui::EndTable();
    }
}

// Function for handling actions on the ActionMap
void LucidGui::sDoAction(const Action &action)
{
    if (action.type() == "START")
    {
        if (action.name() == "UP")
        {
        }
    }
}