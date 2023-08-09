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

bool AccountManager::remove(Account data)
{
    bool removed = false;

    m_data.erase(
        std::remove_if(m_data.begin(), m_data.end(),
                       [&](Account &a)
                       {
                           if (a.tag == data.tag && a.username == data.username)
                           {
                               m_size--;
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

bool AccountManager::update(Account data)
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