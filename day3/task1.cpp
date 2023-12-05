/* AOC 2023 DAY 3 TASK 1

This is quickly getting to be grueling. 

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool isPartialNum(std::vector<std::string> lines, int row, int colStart, int colEnd)
{
    bool isPartialNum {false};
    int startSearch {};
    int endSearch {};
    startSearch = std::max(colStart - 1, 0);
    endSearch = std::min(colEnd + 1, int(lines[0].length()));

    for (int rowDelta = -1; rowDelta < 2; ++rowDelta)
    {
        for (int col = startSearch; col < endSearch; ++col)
        {
            char c { lines[row + rowDelta][col] };
            // std::cout << c << " ";
            // int asciiInt { c - '0' };
            // if ((asciiInt > 9 || asciiInt < 0) && c != '.')
            // {
            //     isPartialNum = true;
            //     return isPartialNum;
            // }
        }
        // std::cout << "\n";
    }
    return isPartialNum;
}

int sumPartNumbers(std::vector<std::string> lines) 
{
    using std::string;
    int sum {0};

    for (size_t row = 0; row < lines.size(); ++row)
    {
        string line { lines[row] };
        int numStart {-1};
        int numEnd {0};
        int num {};
        // std::cout << "iterating row " << numStart << numEnd << "\n";
        for (size_t i = 0; i < line.length(); ++i) 
        {
            // std::cout << i << "\n"; 
            int asciiInt { line[i] - '0' };
            // std::cout << asciiInt << "\n"; 

            // not a number 
            if (asciiInt > 9 || asciiInt < 0)
            {
                // this means we have just left the end of a number 
                if (numStart >= numEnd) 
                {
                    numEnd = i;
                    // std::cout << "numStart is " << numStart << " numEnd is " << numEnd << "\n";
                    num = std::stoi(line.substr(numStart, numEnd - numStart));
                    std::cout << num << "\n";
                    
                    if (isPartialNum(lines, i, numStart, numEnd)) 
                    {
                        sum += num;
                    }
                }
                continue;
            }
            // this means we have just encountered the start of a number 
            if (numStart < numEnd)
            {
                numStart = i;
            }
        }
        // in case a number ends the line 
        if (numStart > numEnd) 
        {
            numEnd = lines[0].length();
            num = std::stoi(line.substr(numStart, numEnd - numStart));
            if (isPartialNum(lines, lines.size(), numStart, numEnd)) 
            {
                sum += num;
                std::cout << num << "\n";
            }
        }
    }
    return sum;
}

int main() 
{
    std::string filePath {"./day3/input.txt"};
    std::ifstream file(filePath);
    std::vector<std::string> lines {};

    if (file.is_open()) 
    {
        std::string line {};
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    int sum { sumPartNumbers(lines) };
    std::cout << sum << "\n";

    return 0;
}