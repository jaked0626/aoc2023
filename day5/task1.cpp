/* AOC 2023 DAY 5 TASK 1

Had to use the long type! first timer here. Glad I didnt have to implement 
my own struct and operator to handle the comparison logic, for now... 

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.h"

std::vector<long> extractSeeds(const std::string inputString)
{
    /* returns a vector containing the seeds in integer form */
    std::vector<long> seedsVec {};

    size_t start { 7 };
    size_t stop {};
    stop = inputString.find("\n\n", start);
    std::string seedsString { inputString.substr(start, stop - start) };
    std::vector<std::string> seedsVecStr { splitString(seedsString, ' ') };

    // convert strings to int 
    for (const std::string& seedStr : seedsVecStr)
    {
        seedsVec.push_back(std::stol(seedStr));
    }

    return seedsVec;
}

std::string extractMapString(std::string inputString, std::string mapName)
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

    std::string mapString { inputString.substr(start, stop - start) };

    return mapString;
}

long translate(long source, std::string mapString)
{
    long destination { source };
    using std::vector;
    using std::string;
    vector<string> lines {};

    lines = splitString(mapString, '\n');
    for (const string& line : lines)
    {
        vector<string> temp { splitString(line, ' ') };
        long destinationLb { std::stol(temp[0]) };
        long sourceLb { std::stol(temp[1]) };
        long range { std::stol(temp[2]) };

        if (source < sourceLb || source > sourceLb + range - 1)
        {
            continue;
        }
        // std::cout << "source: " << source << ", sourceLb: " << sourceLb <<", destinationLb: " << destinationLb << ", range: " << range;
        destination = destinationLb + source - sourceLb;
        // std::cout << ", destination: " << destination <<" \n";
        break;
    }
    // std::cout << destination << "\n";
    return destination;
}

void task1(std::string inputString)
{
    using std::string;
    using std::vector;

    vector<long> seeds { extractSeeds(inputString) };
    vector<long> locations { };

    vector<string> mapNames {
        "seed-to-soil map", 
        "soil-to-fertilizer map", 
        "fertilizer-to-water map",
        "water-to-light map",
        "light-to-temperature map",
        "temperature-to-humidity map",
        "humidity-to-location map",
    };

    for (const long seed : seeds)
    {
        long source {seed};
        long destination {seed};
        // std::cout << "seed: " << seed << "\n";
        for (const string& mapName : mapNames)
        {
            // std::cout << "inputting " << source << " into " << mapName << "\n";
            string mapString { extractMapString(inputString, mapName) };
            destination = translate(source, mapString);
            // std::cout << "destination output: " << destination << "\n";
            source = destination;
        }
        locations.push_back(destination);
    }

    long minLocation { locations[0] };
    for (const long& location : locations)
    {
        if (location < minLocation)
        {
            minLocation = location;
        }
    }
    std::cout << minLocation << "\n";
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
        task1(fileString);
        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return 0;
}