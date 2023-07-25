#include <iostream>
#include <DataManager.h>

int main()
{
    std::string path = "/Users/gillifish/Desktop/db.txt";
    DataManager db(path);

    auto& data = db.data();

    for (auto e : data)
    {
        std::cout << e.tag << std::endl;
    }

    std::cout << "\nREMOVING...\n" << std::endl;

    Account acc;
    acc.tag = "GilliNet";
    acc.username = "Gillifish";
    acc.password = "3665";
    db.remove(acc);

    for (auto e : data)
    {
        std::cout << e.tag << std::endl;
    }
}
