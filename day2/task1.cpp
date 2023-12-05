/* AOC 2023 DAY 2 TASK 1
This task was interesting as it taught me how to process strings in cpp. 
Coming from Python, it's easy to take simple functions with common use cases 
like split or strip for granted, but nooooooo god forbid it be that simple! 
managed to figure out how to use find to iterate through a string, instead of 
relying on regex like last round. Also learned that in cpp, ' and " mean different 
things, and char demands to be in '. 
*/


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

    // std::cout << game << "\n";
    // std::cout << content << "\n";
\
    int gameScore { stoi(splitString(game, ' ')[1]) };
    vector<string> gameResults { splitString(content, ' ') };

    for (size_t i = 0; i < gameResults.size(); i += 2)
    {   
        int num { stoi(gameResults[i]) };
        string color { gameResults[i + 1] };

        // process trailing , or ;
        color.erase(color.find_last_not_of(" ,;") + 1);

        if (stoi(gameResults[i]) > balls[color])
        {
            gameScore = 0;
            break;
        }
    }

    return gameScore;
}


int main() 
{
    std::string filePath {"./day2/input.txt"};
    std::ifstream file(filePath);

    std::unordered_map<std::string, int> balls {};
    balls["red"] = 12;
    balls["blue"] = 14;
    balls["green"] = 13;

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

    std::cout << sum << "\n";

    return 0;
}