#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\advent_of_code_2025\\day_1\\input.txt");

    int num = 50;
    int count = 0;

    while(std::getline(file, line)) {
        if(line.substr(0, 1) == "R") {
            int rot = std::stoi(line.substr(1));
            while(rot > 0) {
                num = (num + 1) % 100;
                if(num == 0) count ++;
                rot -= 1;
            }
        } else {
            int rot = std::stoi(line.substr(1));
            while(rot > 0) {
                num = (num - 1) % 100;
                if(num == 0) count ++;
                rot -= 1;
            }
        }
    }

    file.close();

    std::cout << count << std::endl;

    return 0;
}