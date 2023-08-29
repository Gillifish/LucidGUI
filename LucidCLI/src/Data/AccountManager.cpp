#include "AccountManager.h"

// to_json overload for Account struct
void to_json(json &j, const Account &acc)
{
    j = json{{"AccountName", acc.tag}, {"Username", acc.username}, {"Password", acc.password}};
}

// from_json overload for the Account struct
void from_json(const json &j, Account &acc)
{
    j.at("AccountName").get_to(acc.tag);
    j.at("Username").get_to(acc.username);
    j.at("Password").get_to(acc.password);
}

AccountManager::AccountManager(std::string filepath) : DataManagerBase<Account>(filepath)
{
    loadFromFile();
}

void AccountManager::loadFromFile()
{
    std::fstream inputFile(m_filepath);
    if (!inputFile)
    {
        throw std::runtime_error("Failed to open file...");
    }

    json jsonData = json::parse(inputFile);

    for (auto data : jsonData)
    {
        Account acc;
        acc.tag = data["AccountName"];
        acc.username = data["Username"];
        acc.password = data["Password"];

        m_data.push_back(acc);
        m_map[acc.tag].push_back(acc);
        m_size++;
    }

    inputFile.close();
}

bool AccountManager::removeif(Account &entry, Account &data)
{
    if (entry.tag == data.tag && entry.username == data.username && entry.password == data.password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool AccountManager::update(Account &data)
{
    return true;
}

void AccountManager::saveToFile()
{
    std::ofstream outputFile(m_filepath);

    json j;

    for (auto data : m_data)
    {
        j.push_back(data);
    }

    outputFile << std::setw(4) << j << std::endl;

    outputFile.close();
}