#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

struct Account
{
    std::string tag;
    std::string username;
    std::string password;
};

typedef std::vector<Account> AccountData;
typedef std::map<std::string, AccountData> AccountMap;

class DataManager
{
    AccountData m_accountData;
    AccountMap m_accountMap;
    const std::string m_filepath;
    int m_size = 0;

    void loadFromFile();
    void save();

public:
    DataManager(std::string filepath);
    void add(Account acc);
    void remove(Account acc);
    bool update(Account acc);
    void clear();
    AccountData &getByTag(std::string tag);
    const std::string &filepath();
    AccountData &data();
    int size();
};