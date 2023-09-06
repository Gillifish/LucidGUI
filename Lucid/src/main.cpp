#include <string>
#include <algorithm>

#include <AccountManager.h>
#include <LucidConfig.h>
#include <LucidGui.h>

#ifdef _WIN32
#define OS_NAME "Windows"
#elif __APPLE__
#define OS_NAME "macOS"
#else
#define OS_NAME "UNKNOWN"
#endif

int main()
{
    LucidConfig config;

    std::string path;

    // std::string path = "/Users/gillifish/Lucid/LucidDB.txt";
    if (std::strcmp(OS_NAME, "macOS") == 0)
    {
        std::string macDefaultHomePath = getenv("HOME");
        path = macDefaultHomePath + "/Lucid/LucidDB.json";
    }
    else if (std::strcmp(OS_NAME, "Windows") == 0)
    {
        std::string windowsDefaultPath = "";
        path = windowsDefaultPath + "/Lucid/LucidDB.json";
    }
    else
    {
        printf("Unknown operating system...\n");

        return 1;
    }

    AccountManager db(path);

    float WINDOW_X = 640;
    float WINDOW_Y = 480;
    std::string windowTitle = "Lucid++";

    LucidGui gui(WINDOW_X, WINDOW_Y, windowTitle, 60, db);
    gui.run();

    return 0;
}
