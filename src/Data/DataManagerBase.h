#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

template <typename T>
class DataManagerBase
{
protected:
    std::vector<T> m_data;
    std::map<std::string, std::vector<T>> m_map;
    const std::string m_filepath;
    int m_size = 0;

    virtual void loadFromFile() = 0;
    virtual void saveToFile() = 0;

public:
    virtual bool removeif(T &entry, T &data) = 0;
    virtual bool update(T &data) = 0;

    DataManagerBase(std::string filepath) : m_filepath(filepath)
    {
    }

    void add(T &data)
    {
        m_data.push_back(data);
        m_size++;
        saveToFile();
    }

    bool remove(T &data)
    {
        bool removed = false;

        m_data.erase(
            std::remove_if(m_data.begin(), m_data.end(),
                           [&](T &a)
                           {
                               bool result = removeif(a, data);
                               removed = result;
                               return result;
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

    void clear()
    {
        std::ofstream outputFile(m_filepath, std::ofstream::out);
        outputFile.clear();
        outputFile.close();
    }

    std::vector<T> &getByTag(std::string tag)
    {
        return m_map[tag];
    }

    std::vector<T> &data()
    {
        return m_data;
    }

    const std::string &filepath()
    {
        return m_filepath;
    }

    int size()
    {
        return m_size;
    }
};