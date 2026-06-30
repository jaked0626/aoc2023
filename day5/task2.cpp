/* AOC 2023 DAY 5 TASK 2

Ok, it's getting a little tricky... can't be iterating through every seed. 


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


/**
 * translate takes the minimum seed, the range for the seed,
 *  and puts them through a map, returning a list of pairs of minimum destinations
 * and the range for each destination. 
*/
std::vector<long> translateMap(long source, long range, std::string mapString)
{
    long destination { source };
    using std::vector;
    using std::string;
    vector<long> translated { source, range };
    vector<string> lines {};

    lines = splitString(mapString, '\n');
    for (const string& line : lines)
    {
        translated = translateLine(translated, line);
    }
    // std::cout << destination << "\n";
    return translated;
}

/**
 * Takes a list of sources and ranges, puts them each through a map line and 
 * produces a vector of destinations and their ranges. 
*/
std::vector<long> translateLine(std::vector<long> inputList, std::string line)
{
    using std::vector;
    using std::string;

    vector<long> destinationList{ };
    vector<string> temp { splitString(line, ' ') };
    long destinationLb { std::stol(temp[0]) };
    long sourceLb { std::stol(temp[1]) };
    long mapRange { std::stol(temp[2]) };

    for (size_t i = 0; i < inputList.size(); i += 2)
    {
        long input { inputList[i] };
        long inputRange { inputList[i + 1]};

        // logic to extract overlap, translate, and append subsets to destinationList 
        if (input < sourceLb)
        {
            destinationList.push_back(input);
            destinationList.push_back(minLong(sourceLb - 1, input + inputRange)); // range! check for range 
        }
        if (input + mapRange >= sourceLb && input + mapRange <= sourceLb + mapRange)
        {
            destinationList.push_back(maxLong(sourceLb, input));
            destinationList.push_back(minLong(input + inputRange, sourceLb + mapRange));
        }
        minLong(input, sourceLb);
        maxLong(input + inputRange, sourceLb + mapRange);

        // if (source < sourceLb || source > sourceLb + range - 1)
        // {
        //     continue;
        // }
        // std::cout << "source: " << source << ", sourceLb: " << sourceLb <<", destinationLb: " << destinationLb << ", range: " << range;
        // destination = destinationLb + source - sourceLb;
        // std::cout << ", destination: " << destination <<" \n";
        break;
    }
}

void task2(std::string inputString)
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

    for (size_t i; i < seeds.size(); i += 2)
    {
        long seed { seeds[i] };
        long range { seeds[i + 1] };

        long source {seed};
        long destination {seed};
        std::cout << "seed: " << seed << "\n";
        std::cout << "range: " << range << "\n";

        for (const string& mapName : mapNames)
        {
            // std::cout << "inputting " << source << " into " << mapName << "\n";
            string mapString { extractMapString(inputString, mapName) };
            destination = translate(source, range, mapString);
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
        task2(fileString);
        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return 0;
}