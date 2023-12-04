#include <iostream>
#include <fstream>
#include <string>
#include <vector>


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

int isPossible(std::string line, std::unordered_map<std::string, int> balls) 
{
    using std::vector;
    using std::string; 
    using std::stoi;
    
    vector<string> gameAndContent { splitString(line, ':') };
    string game { gameAndContent[0] };
    string content { gameAndContent[1] };

    std::cout << game << "\n";
    std::cout << content << "\n";

    string gameNumber { splitString(game, ' ')[1] }; 
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