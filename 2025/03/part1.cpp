#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::string line = "";
    std::ifstream file("C:\\Users\\mail\\Documents\\Dev\\Cpp\\AoC2025\\03\\input.txt");

    int num = 0;

    while(std::getline(file, line)) {
        int first = 0;
        for(int i = 0; i < line.length() - 1; i++) {
            if(line[i] > line[first]) {
                first = i;
            }
        }
        int second = first + 1;
        for(int j = first + 1; j < line.length(); j++) {
            if(line[j] > line[second]) {
                second = j;
            }
        }

        num += (line[first] - '0') * 10 + (line[second] - '0');
    }

    file.close();

    std::cout << num << std::endl;

    return 0;
}