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

int powerOfGame(std::string line) 
{
    using std::vector;
    using std::string; 
    using std::stoi;
    
    std::unordered_map<string, int> maxBalls {};
    int gameScore {1};

    vector<string> gameAndContent { splitString(line, ':') };
    string content { gameAndContent[1] };
    vector<string> gameResults { splitString(content, ' ') };

    for (size_t i = 0; i < gameResults.size(); i += 2)
    {   
        int num { stoi(gameResults[i]) };
        string color { gameResults[i + 1] };

        // process trailing , or ;
        color.erase(color.find_last_not_of(" ,;") + 1);

        if (maxBalls.find(color) == maxBalls.end()) 
        {
            maxBalls[color] = 0;
        }
        maxBalls[color] = std::max(maxBalls[color], num);
    }

    for (const auto& maxNum : maxBalls) 
    {
        gameScore *= maxNum.second;
    }

    return gameScore;
}


int main() 
{
    std::string filePath {"./day2/input.txt"};
    std::ifstream file(filePath);

    int sum {};

    if (file.is_open()) 
    {
        std::string line {};
        while (std::getline(file, line))
        {
            sum += powerOfGame(line);
        }

        file.close();
    } 
    else 
    {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    std::cout << sum << "\n";

    return 0;
}