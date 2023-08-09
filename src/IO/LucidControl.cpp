#include "LucidControl.h"

#ifdef _WIN32
    #define OS_NAME "Windows"
#elif __APPLE__
    #define OS_NAME "macOS"
#else
    #define OS_NAME "UNKNOWN"
#endif

void LucidControl::CLI(std::string option, AccountManager &db)
{
    if ((std::strcmp(option.c_str(), "a") == 0) || (std::strcmp(option.c_str(), "add") == 0))
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
}

void LucidControl::displayCommands()
{
    printf("Usage: lucid [options]\n\n");
    printf("Options:\n");
    printf("-gui         Uses the Lucid GUI\n");
    printf("a  | add     Adds an account\n");
    printf("rm | remove  Removes an account\n");
    printf("u  | update  Updates an account\n");
    printf("l  | list    Lists all accounts\n");
}

void LucidControl::add(AccountManager &db)
{
    Account acc;

    std::cout << "Enter account name: ";
    std::getline(std::cin, acc.tag);

    std::cout << "Enter Username: ";
    std::getline(std::cin, acc.username);

    std::cout << "Enter Password: ";
    std::getline(std::cin, acc.password);

    db.add(acc);
}

void LucidControl::remove(AccountManager &db)
{
    Account acc;

    std::cout << "Enter account name: ";
    std::getline(std::cin, acc.tag);

    std::cout << "Enter Username: ";
    std::getline(std::cin, acc.username);

    if (db.remove(acc))
    {
        printf("Account successfully removed...");
    }
    else
    {
        printf("Account does not exist...");
    }
}

void LucidControl::update(AccountManager &db)
{
}

void LucidControl::list(AccountManager &db)
{
    for (auto acc : db.data())
    {
        printf("Account Name: %s\nUsername: %s\nPassword: %s\n", acc.tag.c_str(), acc.username.c_str(), acc.password.c_str());
        printf("----------------------\n");
    }
}

void LucidControl::wipe(AccountManager &db)
{
    db.clear();
}

void LucidControl::setup()
{
    if (std::strcmp(OS_NAME, "Windows"))
    {
        windowsSetup();
    }
    else if (std::strcmp(OS_NAME, "macOS"))
    {
        macSetup();
    }
}

void LucidControl::windowsSetup()
{

}

void LucidControl::macSetup()
{

}

bool LucidControl::checkForConfig()
{
    if (std::strcmp(OS_NAME, "Windows"))
    {
        return checkForWindowsConfig();
    }
    else if (std::strcmp(OS_NAME, "macOS"))
    {
        return checkForMacConfig();
    }
    else
    {
        throw std::runtime_error("Unknown Operating System");
    }
}

bool LucidControl::checkForWindowsConfig()
{
    return false;
}

bool LucidControl::checkForMacConfig()
{
    std::string homePath = getenv("HOME");

    return false;
}
