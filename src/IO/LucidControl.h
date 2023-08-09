#pragma once

#include <iostream>
#include <AccountManager.h>
#include <DataManagerBase.h>

class LucidControl
{   
    static void windowsSetup();
    static void macSetup();

    static bool checkForWindowsConfig();
    static bool checkForMacConfig();
public:
    static void CLI(std::string option, AccountManager &db);
    static void displayCommands();
    static void add(AccountManager &db);
    static void remove(AccountManager &db);
    static void update(AccountManager &db);
    static void list(AccountManager &db);
    static void wipe(AccountManager &db);

    static void setup();
    static bool checkForConfig();
};