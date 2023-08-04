#pragma once

#include <iostream>
#include <DataManager.h>

class LucidControl
{
public:
    static void CLI(std::string option, DataManager &db);
    static void displayCommands();
    static void add(DataManager &db);
    static void remove(DataManager &db);
    static void update(DataManager &db);
    static void list(DataManager &db);
    static void wipe(DataManager &db);
};