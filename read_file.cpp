#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("example.txt");
    std::string line;

    if (!inputFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return 0;
}
