#include "LucidConfig.h"

LucidConfig::LucidConfig()
{
    if (std::filesystem::exists(m_filepath))
    {
        loadFromFile();
    }
    else
    {
        configSetup();
    }
}

void LucidConfig::loadFromFile()
{
    std::fstream inputFile(m_filepath + "/LucidConfig.txt");
    if (!inputFile)
    {
        throw std::runtime_error("Failed to open file...");
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        iss >> m_config.filepath;
        iss >> m_config.user;
        iss >> m_config.pin;
    }

    inputFile.close();
}

void LucidConfig::configSetup()
{
    std::filesystem::create_directory(m_defaultDir + "/Lucid");
    std::filesystem::create_directory(m_backupPath);

    std::ofstream createConfig(m_configpath);

    if (createConfig.is_open())
    {
        createConfig << m_filepath << " " << std::endl;

        createConfig.close();
    }

    std::ofstream createDB(m_dbpath);

    if (createDB.is_open())
    {
        createDB.close();
    }
}

void LucidConfig::saveToFile()
{
    std::ofstream outputFile(m_filepath, std::ofstream::out);

    outputFile << m_config.filepath << " " << m_config.setup << std::endl;

    outputFile.close();
}

void LucidConfig::setConfig(Config &config)
{
    m_config = config;
}

Config &LucidConfig::getConfig()
{
    return m_config;
}

