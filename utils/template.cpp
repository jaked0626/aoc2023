#include <iostream>
#include <fstream>
#include <string>


int main() {
    std::string filePath {"input.txt"};
    std::ifstream file(filePath);

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