#include <string>
#include <algorithm>

#include <AccountManager.h>
#include <LucidConfig.h>
#include <LucidControl.h>

#ifdef _WIN32
    #define OS_NAME "Windows"
#elif __APPLE__
    #define OS_NAME "macOS"
#else
    #define OS_NAME "UNKNOWN"
#endif

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        LucidControl::displayCommands();

        return 1;
    }

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

    std::string option = argv[1];

    // Makes any input for the second argument lowercase
    std::transform(option.begin(), option.end(), option.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    
    LucidControl::CLI(option, db);

    return 0;
}
