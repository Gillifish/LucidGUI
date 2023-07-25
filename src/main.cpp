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

    std::cout << "Adding" << std::endl;

    Account acc;
    acc.tag = "Goggle";
    acc.username = "Drew";
    acc.password = "3665";
    db.add(acc);

    for (auto e : data)
    {
        std::cout << e.tag << std::endl;
    }
}
