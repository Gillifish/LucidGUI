#include <string>
#include <algorithm>

#include <AccountManager.h>
#include <LucidConfig.h>
#include <LucidControl.h>
#include <LucidGui.h>
#include <LucidConfigGui.h>

const std::string LUCIDVERSION = "0.8";

int main(int argc, char *argv[])
{
    std::string macDefaultHomePath = getenv("HOME");

    LucidConfig config;

    if (argc != 2)
    {
        LucidControl::displayCommands();
        return 1;
    }

    std::string path = "/Users/gillifish/Lucid/LucidDB.txt";
    AccountManager db(path);

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

    if (std::strcmp(option.c_str(), "-config") == 0)
    {
        float WINDOW_X = 640;
        float WINDOW_Y = 480;
        std::string windowTitle = "Lucid++ Config";

        LucidConfigGui gui(WINDOW_X, WINDOW_Y, windowTitle, 60);
        gui.run();

        return 0;
    }
    
    LucidControl::CLI(option, db);

    return 0;
}
