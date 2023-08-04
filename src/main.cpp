#include <iostream>
#include <algorithm>
#include <DataManager.h>
#include <Control.h>
#include <LucidGui.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        LucidControl::displayCommands();
        return 1;
    }

    std::string path = "/Users/gillifish/Desktop/db.txt";
    DataManager db(path);

    std::string option = argv[1];

    // Makes any input for the second argument lowercase
    std::transform(option.begin(), option.end(), option.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    if (std::strcmp(option.c_str(), "-gui") == 0)
    {
        float WINDOW_X = 640;
        float WINDOW_Y = 480;
        std::string windowTitle = "Lucid++";

        LucidGui gui(WINDOW_X, WINDOW_Y, windowTitle, 60, db);
        gui.run();

        return 0;
    }
    
    LucidControl::CLI(option, db);

    return 0;
}
