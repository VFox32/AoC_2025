#include <iostream>
#include <fstream>

// https://adventofcode.com/2015/day/1

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("2015\\01\\input.txt");

    std::getline(file, line);
    file.close();

    long long int floor = 0;
    int position = -1;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == '(') {
            floor++;
        } else {
            floor--;
        }
        if(floor < 0 && position < 0) position = i + 1;
    }

    std::cout << "part 1: " << floor << std::endl;
    std::cout << "part 2: " << position << std::endl;

    return 0;
}