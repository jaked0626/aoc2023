#include<iostream>
#include<string>
#include<vector>
#include "utils.h"


std::vector<std::string> splitString(const std::string &inputString, char delimiter) {
    std::vector<std::string> tokens;
    std::size_t start {0};
    std::size_t end { inputString.find(delimiter, start) };

    while (end != std::string::npos) 
    {
        // avoiding empty strings
        if (end != start) 
        {
          tokens.push_back(inputString.substr(start, end - start));
        }
        start = end + 1;
        end = inputString.find(delimiter, start);
    }

    // push last token 
    if (end != start) 
    {
       tokens.push_back(inputString.substr(start));
    }
    return tokens;
}

void printStringVector(std::vector<std::string> vec)
{
    for (const auto& s: vec)
    {
        std::cout << s <<", ";
    }
    std::cout << "\n";
}

// template <typename K, typename V>
// void initializeMapKey(std::map<K, V>& myMap, const K& key, const V& defaultValue) 
// {
//     // Check if the key exists in the map
//     auto it { myMap.find(key) };

//     // If the key does not exist, initialize it with the default value
//     if (it == myMap.end()) 
//     {
//         myMap[key] = defaultValue;
//     }
// }