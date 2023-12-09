/* AOC 2023 DAY 5 TASK 1

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.h"

std::vector<std::string> extractSeeds(const std::string inputString)
{
    size_t start { 7 };
    size_t stop {};
    stop = inputString.find("\n\n", start);
    std::string seedsString { inputString.substr(start, stop - start) };
    std::vector<std::string> seedsVec { splitString(seedsString, ' ') };

    return seedsVec;
}

std::string extractStringMap(std::string inputString, std::string mapName)
{
    size_t start { inputString.find(mapName, 0) };
    if (start == std::string::npos)
    {
        return "error: could not find mapName";
    }

    size_t stop { inputString.find("\n\n", start ) };
    if (stop == std::string::npos)
    {
        stop = inputString.size() - 1;
    }

    start = start + mapName.length() + 2;

    return inputString.substr(start, stop - start);
}


int main() 
{
    using std::string;
    using std::vector;

    string filePath {"./day5/input.txt"};
    std::ifstream file {filePath};

    if (file.is_open()) 
    {
        string fileString { readFileIntoString(file) };

        vector<string> seeds { extractSeeds(fileString) };

        for (const string seed : seeds)
        {
            // std::cout << seed << " ";
        }

        string seedToSoil { extractStringMap(fileString, "humidity-to-location map") };

        std::cout << seedToSoil << "\n";

        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return 0;
}