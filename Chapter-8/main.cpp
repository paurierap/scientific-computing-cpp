#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> phonebook;
    phonebook["Joaquín"] = 123;
    phonebook["Alberto"] = 234;
    phonebook["Unama Madita"] = 910;

    for (auto it = phonebook.begin(); it != phonebook.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    return 0;
}