#include "LucidControl.h"

void LucidControl::CLI(std::string option, DataManager &db)
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

void LucidControl::add(DataManager &db)
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

void LucidControl::remove(DataManager &db)
{
    Account acc;

    std::cout << "Enter account name: ";
    std::getline(std::cin, acc.tag);

    std::cout << "Enter Username: ";
    std::getline(std::cin, acc.username);

    if (db.remove(acc))
    {
        printf("Account successfully removed...");
    } else
    {
        printf("Account does not exist...");
    }
}

void LucidControl::update(DataManager &db)
{
}

void LucidControl::list(DataManager &db)
{
    for (auto acc : db.data())
    {
        printf("Account Name: %s\nUsername: %s\nPassword: %s\n", acc.tag.c_str(), acc.username.c_str(), acc.password.c_str());
        printf("----------------------\n");
    }
}

void LucidControl::wipe(DataManager &db)
{
    db.clear();
}