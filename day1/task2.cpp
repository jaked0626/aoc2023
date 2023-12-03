#include <iostream>
#include <fstream>
#include <string>
#include <regex>




int main() {
    std::string filePath {"./day1/input.txt"};
    std::ifstream file(filePath);

    if (file.is_open()) 
    {
        std::string line {};
        int sum {};
        std::unordered_map<std::string, int> wordToDigit {};
        wordToDigit["one"] = 1;
        wordToDigit["two"] = 2;
        wordToDigit["three"] = 3;
        wordToDigit["four"] = 4;
        wordToDigit["five"] = 5;
        wordToDigit["six"] = 6;
        wordToDigit["seven"] = 7;
        wordToDigit["eight"] = 8;
        wordToDigit["nine"] = 9;
        std::regex firstPattern {"(one|two|three|four|five|six|seven|eight|nine)"};
        std::regex lastPattern {"(enin|thgie|neves|xis|evif|ruof|eerht|owt|eno)"};
        while (std::getline(file, line)) 
        {
            int firstDigit {-1};
            int lastDigit {};
            int asciiInt {};
            std::string contiguousChars {};
            char c {};
            for (int i = 0; i < line.length(); ++i) 
            {
                c = line[i];
                // get integer representation of ascii and rebase by subtracting value of '0'
                asciiInt = c - '0';

                // no arabic digits encountered
                if ((asciiInt < 0 || asciiInt > 9) && i < line.length() - 1)
                {
                    contiguousChars += c;
                    continue;
                }

                // an arabic numeral is encountered or we reach the last character

                std::smatch firstMatch {};
                if (firstDigit < 0)
                {
                    // first, we treat contiguousChars to see if we missed any 
                    // digits there for the first digit
                    if (std::regex_search(contiguousChars, firstMatch, firstPattern)) 
                    {
                        firstDigit = wordToDigit[firstMatch[0]];
                    }
                    else 
                    // assign the roman numeral
                    {
                        firstDigit = asciiInt;
                    }
                }

                // next, we look for the last occurrence of a digit

                // in case last character encountered is not an arabic numeral
                if (i == line.length() - 1 && (asciiInt < 0 || asciiInt > 9))
                {
                    contiguousChars += c;
                    std::string reversedContiguousChars {contiguousChars};
                    std::reverse(reversedContiguousChars.begin(), reversedContiguousChars.end());
                    std::smatch lastMatch {};
                    if (std::regex_search(reversedContiguousChars, lastMatch, lastPattern)) 
                    {
                        std::string matchedString {lastMatch[0]};
                        std::reverse(matchedString.begin(), matchedString.end());
                        lastDigit = wordToDigit[matchedString];
                    }
                }
                else 
                {
                    lastDigit = asciiInt;
                }

                // reset contiguousChars
                contiguousChars = "";
            }
            sum += 10 * firstDigit + lastDigit;
        }

        file.close();

        std::cout << sum << "\n";
    } else {
        std::cerr << "Error: Unable to open file " << filePath << "\n";
    }

    return 0;
}