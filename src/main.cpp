#include <iostream>
#include <algorithm>
#include <DataManager.h>
#include <Control.h>
#include <App.h>

int main(int argc, char *argv[])
{
    std::string path = "/Users/gillifish/Desktop/db.txt";
    DataManager db(path);

    if (argc != 2)
    {
        LucidControl::displayCommands();
        return 1;
    }
    std::string option = argv[1];

    // Makes any input for the second argument lowercase
    std::transform(option.begin(), option.end(), option.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    if (std::strcmp(option.c_str(), "-gui") == 0)
    {
        float WINDOW_X = 640;
        float WINDOW_Y = 480;
        std::string windowTitle = "Lucid++";

        App gui(WINDOW_X, WINDOW_Y, windowTitle, 60, db);
        gui.run();
        
        return 0;
    }
    else if ((std::strcmp(option.c_str(), "a") == 0) || (std::strcmp(option.c_str(), "add") == 0))
    {
        LucidControl::add(db);
    }
    else if ((std::strcmp(option.c_str(), "rm") == 0) || (std::strcmp(option.c_str(), "remove") == 0))
    {
        LucidControl::remove(db);
    }
    else if ((std::strcmp(option.c_str(), "u") == 0) || (std::strcmp(option.c_str(), "update") == 0))
    {
        LucidControl::update(db);
    }
    else if ((std::strcmp(option.c_str(), "l") == 0) || (std::strcmp(option.c_str(), "list") == 0))
    {
        LucidControl::list(db);
    }
    else if (std::strcmp(option.c_str(), "wipe") == 0)
    {
        LucidControl::wipe(db);
    }
    else
    {
        std::cout << "Unknown command..." << std::endl;
    }

    return 0;
}
