#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<std::string> splitString (std::string inputString, std::string delimiter)
{
    std::vector<std::string> splitArray {};

    size_t pos = 0;
    std::string splitToken {};
    while ((pos = inputString.find(delimiter)) != std::string::npos) {
        splitToken = inputString.substr(0, pos);
        splitArray.push_back(splitToken);
        inputString.erase(0, pos + delimiter.length());
    }

    return splitArray;
}

int isPossible(std::string line, std::unordered_map<std::string, int> balls) 
{
    using std::vector;
    using std::string; 
    using std::stoi;
    
    vector<string> gameAndContent { splitString(line, ":") };
    string game { gameAndContent[0] };
    string content { gameAndContent[1] };

    std::cout << game << "\n";
    std::cout << content << "\n";

    string gameNumber { splitString(game, " ")[1] }; 
    // int gameNumber { stoi(splitString(game, " ")[1]) }; 

    // std::cout << gameNumber << "\n";

    return 0;
}


int main() 
{
    std::string filePath {"./day2/input.txt"};
    std::ifstream file(filePath);

    std::unordered_map<std::string, int> balls {};
    balls["red"] = 12;
    balls["blue"] = 13;
    balls["green"] = 14;

    int sum {};

    if (file.is_open()) 
    {
        std::string line {};
        while (std::getline(file, line))
        {
            sum += isPossible(line, balls);
        }

        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return sum;
}