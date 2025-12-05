#include <iostream>
#include <fstream>
#include <sstream>

// https://adventofcode.com/2025/day/2

bool isPattern(std::string num) {
    for(int i = 1; i <= num.length() / 2; i++) { // for each pattern length
        if(num.length() % i != 0) continue; // if length is multiple of pattern length

        std::string first = num.substr(0, i); // compare agains first pattern instance

        bool match = true;
        for(int j = 0; j < num.length(); j += i) {
            if(first != num.substr(j, i)) { // compare first instance with every other instance
                match = false;
                break;
            }
        }

        if(match) return true; // if any matches, number is a repeating pattern
    }

    return false;
}

bool isDouble(std::string num) {
    if(num.length() % 2 != 0) return false; // if length is not multiple of 2, it cant be a repeated pattern

    if(num.substr(0, num.length() / 2) == num.substr(num.length() / 2)) return true; // compare halves

    return false;
}

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\02\\input.txt");

    unsigned long long int num1 = 0;
    unsigned long long int num2 = 0;

    while(std::getline(file, line, ',')) {
        std::string first = "";
        std::string second = "";

        std::stringstream ss(line);
        std::getline(ss, first, '-');
        std::getline(ss, second, '-');

        unsigned long long int lower = std::stoull(first);
        unsigned long long int upper = std::stoull(second);

        // check all numbers in the given range
        for(unsigned long long int n = lower; n <= upper; n++) {
            if(isDouble(std::to_string(n))) num1 += n; // add to part 1 if number is something repeated twice
            if(isPattern(std::to_string(n))) num2 += n; // add to part 2 if number is pattern of any length
        }
    }

    file.close();

    std::cout << "part 1: " << num1 << std::endl;
    std::cout << "part 2: " << num2 << std::endl;

    return 0;
}
