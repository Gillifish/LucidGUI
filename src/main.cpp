#include <string>
#include <algorithm>

#include <AccountManager.h>
#include <LucidConfig.h>
#include <LucidControl.h>
#include <LucidGui.h>
#include <LucidConfigGui.h>

int main(int argc, char *argv[])
{
    //std::string macDefaultHomePath = getenv("HOME");

    LucidConfig config;

    std::string path = "/Users/gillifish/Lucid/LucidDB.txt";
    AccountManager db(path);

    if (argc == 1)
    {
        float WINDOW_X = 640;
        float WINDOW_Y = 480;
        std::string windowTitle = "Lucid++";

        LucidGui gui(WINDOW_X, WINDOW_Y, windowTitle, 60, db);
        gui.run();

        return 0;
    }

    std::string option = argv[1];

    // Makes any input for the second argument lowercase
    std::transform(option.begin(), option.end(), option.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    
    LucidControl::CLI(option, db);

    return 0;
}
