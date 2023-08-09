#include "AccountManager.h"

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

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Account acc;
        iss >> acc.tag;
        iss >> acc.username;
        iss >> acc.password;

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
    std::ofstream outputFile(m_filepath, std::ofstream::out);

    for (auto acc : m_data)
    {
        outputFile << acc.tag << " " << acc.username << " " << acc.password << std::endl;
    }

    outputFile.close();
}