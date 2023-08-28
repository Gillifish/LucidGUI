#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct Config
{
    std::string user;
    std::string pin;
    std::string filepath;
    bool setup;
};

// I'm not gonna lie, this code isn't great but at least it works ya know?

class LucidConfig
{
#ifdef __APPLE__
    const std::string m_defaultDir = getenv("HOME");
#elif __linux__
    const std::string defaultPath = "";
#elif _WIN32
    const std::string defaultPath = "";
#endif

    std::string m_filepath = m_defaultDir + "/Lucid";
    std::string m_dbpath = m_filepath + "/LucidDB.json";
    std::string m_configpath = m_filepath + "/LucidConfig.txt";
    Config m_config;

    void loadFromFile();
    void configSetup();

public:
    LucidConfig();

    void saveToFile();
    void setConfig(Config &config);
    Config &getConfig();
};