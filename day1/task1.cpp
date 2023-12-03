#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::string filePath {"./day1/input.txt"};
    std::ifstream file(filePath);

    if (file.is_open()) 
    {
        std::string line {};
        int sum {};
        while (std::getline(file, line)) 
        {
            int firstDigit {-1};
            int lastDigit {};
            int temp {};
            for (char const &c: line) 
            {
                // get integer representation of ascii and rebase by subtracting value of '0'
                temp = c - '0';
                if (temp < 0 || temp > 9) 
                {
                    // not a digit
                    continue;
                }
                if (firstDigit < 0) 
                {
                    firstDigit = temp;
                }
                lastDigit = temp;
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