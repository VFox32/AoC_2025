#include <iostream>
#include <fstream>

// https://adventofcode.com/2025/day/1

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2025\\01\\input.txt");

    int num = 50; // initial dial position
    int count1 = 0; // part 1
    int count2 = 0; // part 2

    while(std::getline(file, line)) {
        int rot = std::stoi(line.substr(1));
        // very ugly solution, but works
        if(line.substr(0, 1) == "R") {
            while(rot > 0) {
                num = (num + 1) % 100;
                if(num == 0) count2 ++; // increment part 2 if dial passes 0
                rot --;
            }
        } else {
            while(rot > 0) {
                num = (num - 1) % 100;
                if(num == 0) count2 ++; // ''
                rot --;
            }
        }
        if(num == 0) count1++; // increment part 1 if 0 after whole rotation
    }

    file.close();

    std::cout << "part 1: " << count1 << std::endl;
    std::cout << "part 2: " << count2 << std::endl;

    return 0;
}
