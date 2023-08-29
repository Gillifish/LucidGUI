#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

#include "json.hpp"

#include "DataManagerBase.h"

using json = nlohmann::json;

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
    
    // Handles the removal logic of the base classes remove function
    // Should return true if the data given to the function matches what you have specified
    bool removeif(Account &entry, Account &data);
    bool update(Account &data);
};