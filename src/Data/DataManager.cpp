#include "DataManager.h"

DataManager::DataManager(std::string filepath) : m_filepath(filepath)
{
    if (std::filesystem::exists(filepath))
    {
        loadFromFile();
    }
    else
    {
        std::ofstream outputFile(filepath);
        if (outputFile.is_open())
        {
            outputFile.close();
            loadFromFile();
        }
        else
        {
            throw std::runtime_error("ERROR: File could not be created...");
        }
    }
}

void DataManager::loadFromFile()
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

        m_accountData.push_back(acc);
        m_accountMap[acc.tag].push_back(acc);
        m_size++;
    }

    inputFile.close();
}

void DataManager::add(Account acc)
{
    m_accountData.push_back(acc);
    m_size++;
    save();
}

bool DataManager::remove(Account acc)
{
    bool removed = false;

    m_accountData.erase(
        std::remove_if(m_accountData.begin(), m_accountData.end(),
                       [&](Account &a)
                       {
                           if (a.tag == acc.tag && a.username == acc.username)
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
        m_accountData.end());

    if (removed)
    {
        save();
        return true;
    }
    else
    {
        return false;
    }
}

bool DataManager::update(Account acc)
{
    return true;
}

void DataManager::clear()
{
    std::ofstream outputFile(m_filepath, std::ofstream::out);
    outputFile.clear();
    outputFile.close();
}

void DataManager::save()
{
    std::ofstream outputFile(m_filepath, std::ofstream::out);

    for (auto acc : m_accountData)
    {
        outputFile << acc.tag << " " << acc.username << " " << acc.password << std::endl;
    }

    outputFile.close();
}

AccountData &DataManager::getByTag(std::string tag)
{
    return m_accountMap[tag];
}

AccountData &DataManager::data()
{
    return m_accountData;
}

const std::string &DataManager::filepath()
{
    return m_filepath;
}

int DataManager::size()
{
    return m_size;
}