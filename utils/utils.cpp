#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "utils.h"

// must be reference, ifstream does not have a copy constructor (deleted)
std::string readFileIntoString(const std::ifstream& file) 
{
    std::string fileContents {};
    if (file.is_open()) 
    {
        std::stringstream buffer;
        buffer << file.rdbuf();
        fileContents = buffer.str();
    }

    return fileContents;
}

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

template <typename K, typename V>
void initializeMapKeyIfEmpty(std::unordered_map<K, V>& myMap, const K& key, const V& defaultValue) 
{
    // Check if the key exists in the map
    auto target { myMap.find(key) };

    // If the key does not exist, initialize it with the default value
    if (target == myMap.end()) 
    {
        myMap[key] = defaultValue;
    }
}

template void initializeMapKeyIfEmpty<std::string, int>(std::unordered_map<std::string, int>&, const std::string&, const int&);
template void initializeMapKeyIfEmpty<int, int>(std::unordered_map<int, int>&, const int&, const int&);