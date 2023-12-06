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

#include "utils.h"


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



int countCommonCards(std::set<std::string> winningCards, std::vector<std::string> userCards) 
{
    int common {0};
    for (const auto& userCard: userCards)
    {
        if (winningCards.count(userCard))
        {
            common += 1;
        }
    }
    return common;
}

int getScore(std::string line)
{
    line = removeCardTitle(line);
    std::vector<std::string> splitCards { splitWinningAndUserCards(line) };
    std::set<std::string> winningCards { getCardsSet(splitCards[0]) };
    std::vector<std::string> userCards { getCardsArray(splitCards[1]) };
    int score { countCommonCards(winningCards, userCards) };

    return score;
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
            int pow { getScore(line) };
            if (pow > 0) 
            {
                sum += std::pow(2, pow - 1);
            }
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