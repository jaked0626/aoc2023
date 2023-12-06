/* AOC 2023 DAY 4 TASK 2

Author: Jake Underland
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

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

template <typename K, typename V>
void initializeMapKeyIfEmpty(std::unordered_map<K, V>& myMap, const K& key, const V& defaultValue) 
{
    // Check if the key exists in the map
    auto target { myMap.find(key) };

    // If the key does not exist, initialize it with the default value
    if (target == myMap.end()) 
    {
        myMap[key] = defaultValue;
    }
}



/*
keep hashmap. 
cards = {card1: xxx, card2: xxx, }
matches = getMatches(card1)
for (int i = 1 + 1; i < 1 + matches; ++i)
{
    cards[i] += cards[1] 
}

*/

int main() 
{
    std::string filePath {"./day4/input.txt"};
    std::ifstream file(filePath);

    std::string line {};
    std::unordered_map<int, int> cardNumbers{};
    int currentCard {1};
    int sum {0};

    

    if (file.is_open()) 
    {

        while (std::getline(file, line))
        {
            // zero initialize the current cards.
            initializeMapKeyIfEmpty(cardNumbers, currentCard, 1);

            int numMatches { getScore(line) };

            std::cout << currentCard << " " << numMatches << "\n";

            for (int increasedCard = currentCard + 1; increasedCard < currentCard + numMatches + 1; ++increasedCard)
            {
                // zero initialize the next cards.
                initializeMapKeyIfEmpty(cardNumbers, increasedCard, 1);
                cardNumbers[increasedCard] += cardNumbers[currentCard];
            }

            ++currentCard;
        }

        for (const auto& cardNum : cardNumbers) 
        {
            std::cout << "card number: " << cardNum.first << "; numCards: " << cardNum.second << "\n";
            sum += cardNum.second;
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