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

AccountManager::AccountManager(std::string filepath) : m_filepath(filepath)
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

    int index = 0;

    for (auto data : jsonData)
    {
        Account acc;
        acc.index = index;
        acc.tag = data["AccountName"];
        acc.username = data["Username"];
        acc.password = data["Password"];

        m_data.push_back(acc);
        m_map[acc.tag].push_back(acc);
        m_size++;
        index++;
    }

    inputFile.close();
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

void AccountManager::resetIndex()
{
    int index = 0;

    for (auto acc : m_data)
    {
        acc.index = index;
        index++;
    }
}

// Adds data to the vector and map
void AccountManager::add(Account &data)
{
    m_data.push_back(data);
    m_size++;
    saveToFile();
}

bool AccountManager::remove(Account &data)
{
    bool removed = false;

    m_data.erase(
        std::remove_if(m_data.begin(), m_data.end(),
                       [&](Account &a)
                       {
                           if (a.tag == data.tag && a.username == data.username && a.password == data.password)
                           {
                               resetIndex();
                               removed = true;
                               return true;
                           }
                           else
                           {
                               return false;
                           }
                       }),
        m_data.end());

    if (removed)
    {
        saveToFile();
        return true;
    }
    else
    {
        return false;
    }
}

void AccountManager::clear()
{
    std::ofstream outputFile(m_filepath, std::ofstream::out);
    outputFile.clear();
    outputFile.close();
}

std::vector<Account> &AccountManager::getByTag(std::string tag)
{
    return m_map[tag];
}

Account &AccountManager::getByIndex(int index)
{
    for (auto& acc : m_data)
    {
        if (acc.index == index)
        {
            return acc;
        }
    }

    throw std::out_of_range("Index out of bounds");
}

std::vector<Account> &AccountManager::data()
{
    return m_data;
}

// Returns the filepath
const std::string &AccountManager::filepath()
{
    return m_filepath;
}

// Returns the size of the data
int AccountManager::size()
{
    return m_size;
}

void AccountManager::createBackup()
{
    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a std::tm structure
    std::tm* timeInfo = std::localtime(&currentTime);

    std::string month = std::to_string(timeInfo->tm_mon + 1);
    std::string day = std::to_string(timeInfo->tm_mday);
    std::string hour = std::to_string(timeInfo->tm_hour);
    std::string minute = std::to_string(timeInfo->tm_min);
    std::string second = std::to_string(timeInfo-> tm_sec);

    std::string outStr = month + "-" + day + "-" + hour + "-" + minute + "-" + second + ".json";

    std::ofstream outputFile("/Users/gillifish/Lucid/Backups/" + outStr);

    json j;

    for (auto data : m_data)
    {
        j.push_back(data);
    }

    outputFile << std::setw(4) << j << std::endl;

    outputFile.close();
}