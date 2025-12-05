#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

bool isInvalidNum(std::string num) {
    if(num.length() % 2 != 0) return false;

    if(num.substr(0, num.length() / 2) == num.substr(num.length() / 2)) return true;

    return false;
}

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC2025\\02\\input.txt");

    unsigned long long int num = 0;

    while(std::getline(file, line, ',')) {
        std::string first = "";
        std::string second = "";

        std::stringstream ss(line);
        std::getline(ss, first, '-');
        std::getline(ss, second, '-');

        unsigned long long int lower = std::stoull(first);
        unsigned long long int upper = std::stoull(second);

        for(unsigned long long int n = lower; n <= upper; n++) {
            if(isInvalidNum(std::to_string(n))) num += n;
        }
    }

    file.close();

    std::cout << num << std::endl;

    return 0;
}
