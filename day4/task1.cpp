/* AOC 2023 DAY 4 TASK 1

soooo, who wanna talk about that cursed cpp intersection function. 

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

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

int getScore(std::string line) 
{
    return 0;
}

std::string removeCardTitle(std::string line) 
{
    size_t colonPos { line.find(":") };
    std::string trimmedCard {line};

    if (colonPos != std::string::npos)
    {
        size_t n { line.size() };
        trimmedCard = line.substr(colonPos + 2, n - colonPos - 2);
    }
    else 
    {
        std::cout << "Error removing Card Title" << "\n";
    }
    return trimmedCard;
}

std::vector<std::string> splitWinningAndUserCards(std::string trimmedCard) 
{
    std::vector<std::string> cards {};
    cards = splitString(trimmedCard, '|');
    return cards;
}

std::set<std::string> getCardsSet(std::string cardsString)
{
    std::vector<std::string> cardsArray { splitString(cardsString, ' ') };
    std::set<std::string> cardsSet {};

    for (const auto& card: cardsArray)
    {
        cardsSet.insert(card);
    }
    return cardsSet;
}

std::vector<std::string> getCardsArray(std::string cardsString)
{
    std::vector<std::string> cardsArray { splitString(cardsString, ' ') };

    return cardsArray;
}

void printStringVector(std::vector<std::string> vec)
{
    for (const auto& s: vec)
    {
        std::cout << s <<", ";
    }
    std::cout << "\n";
}

int main() 
{
    using std::string;

    string filePath {"./day4/input.txt"};
    std::ifstream file(filePath);

    int sum {0};

    if (file.is_open()) 
    {
        string line {};
        while (std::getline(file, line))
        {
            std::vector<string> splitCards {};
            std::set<string> winningCards {};
            std::vector<string> userCards {};
            int pow {0};

            line = removeCardTitle(line);
            splitCards = splitWinningAndUserCards(line);
            winningCards = getCardsSet(splitCards[0]);
            userCards = getCardsArray(splitCards[1]);
            
            for (const auto& userCard: userCards)
            {
                if (winningCards.count(userCard))
                {
                    std::cout << userCard << "; ";
                    pow += 1;
                }
            }
            if (pow > 0) 
            {
                sum += std::pow(2, pow - 1);
            }
            pow = 0;
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