#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <map>
#include <sstream>

#include "json.hpp"

// Abstract template base class for managing different types of data. Probably a little overengineered/not needed but I
//      wanted to try out some C++ generics/inheritance.
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

    // Constructor
    DataManagerBase(std::string filepath) : m_filepath(filepath)
    {
    }

    // Adds data to the vector and map
    void add(T &data)
    {
        m_data.push_back(data);
        m_size++;
        saveToFile();
    }

    // Removes data from the vector and map
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

    // Clears the files data
    void clear()
    {
        std::ofstream outputFile(m_filepath, std::ofstream::out);
        outputFile.clear();
        outputFile.close();
    }

    // Returns a vector of every element that matches the tag
    std::vector<T> &getByTag(std::string tag)
    {
        return m_map[tag];
    }

    // Returns a vector of all the data
    std::vector<T> &data()
    {
        return m_data;
    }

    // Returns the filepath
    const std::string &filepath()
    {
        return m_filepath;
    }

    // Returns the size of the data
    int size()
    {
        return m_size;
    }
};