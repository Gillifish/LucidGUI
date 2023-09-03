#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

#include "json.hpp"

using json = nlohmann::json;

struct Account
{
    int index;
    std::string tag;
    std::string username;
    std::string password;
};

class AccountManager
{
    std::vector<Account> m_data;
    std::map<std::string, std::vector<Account>> m_map;
    const std::string m_filepath;
    int m_size = 0;

    void loadFromFile();
    void resetIndex();

public:
    AccountManager(std::string filepath);

    void add(Account &acc);
    bool remove(Account &acc);
    void clear();
    void saveToFile();
    std::vector<Account> &getByTag(std::string tag);
    Account &getByIndex(int index);
    std::vector<Account>& data();
    // Returns the filepath
    const std::string &filepath();
    int size();
};