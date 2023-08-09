#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

#include "DataManagerBase.h"

struct Account
{
    std::string tag;
    std::string username;
    std::string password;
};

class AccountManager : public DataManagerBase<Account>
{
    void loadFromFile();
    void saveToFile();

public:
    AccountManager(std::string filepath);
    
    bool remove(Account data);
    bool update(Account data);
};