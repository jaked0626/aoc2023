/* AOC 2023 DAY X TASK X

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>


int main() 
{
    const std::string filePath {"input.txt"};
    std::ifstream file {filePath};

    if (file.is_open()) 
    {
        std::string line {};
        while (std::getline(file, line))
        {
            std::cout << line << "\n";
        }

        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return 0;
}