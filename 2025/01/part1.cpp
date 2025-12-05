#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC2025\\01\\input.txt");

    int num = 50;
    int count = 0;

    while(std::getline(file, line)) {
        if(line.substr(0, 1) == "R") {
            num = (num + std::stoi(line.substr(1))) % 100;
        } else {
            num = (num - std::stoi(line.substr(1))) % 100;
        }

        if(num == 0) {
            count += 1;
        }
    }

    file.close();

    std::cout << count << std::endl;

    return 0;
}
