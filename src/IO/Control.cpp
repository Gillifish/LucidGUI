#include "Control.h"

void LucidControl::displayCommands()
{
    printf("Usage: lucid [options]\n\n");
    printf("Options:\n");
    printf("a  | add     Adds an account\n");
    printf("rm | remove  Adds an account\n");
    printf("u  | update  Adds an account\n");
    printf("l  | list    Adds an account\n");
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