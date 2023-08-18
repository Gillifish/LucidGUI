#pragma once

#include <iostream>
#include <AccountManager.h>
#include <DataManagerBase.h>

// Manages all of the CLI interactions for Lucid

class LucidControl
{   
public:
    static void CLI(std::string option, AccountManager &db);
    static void displayCommands();
    static void add(AccountManager &db);
    static void remove(AccountManager &db);
    static void update(AccountManager &db);
    static void list(AccountManager &db);
    static void wipe(AccountManager &db);
};